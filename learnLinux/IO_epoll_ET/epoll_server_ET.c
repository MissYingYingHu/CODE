#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
typedef struct epoll_event epoll_event;




int SetNoBlock(int sock)
{
    //先获取到文件描述符的标记
    int flag = fcntl(sock,F_GETFL);
    if(flag < 0)
    {
        perror("fcntl get");
        return -1;
    }
    //然后再添加上非阻塞的选项再设置到文件描述符中
    int ret = fcntl(sock,F_SETFL,flag | O_NONBLOCK);
    if(ret < 0)
    {
        perror("fcntl set");
        return -1;
    }
    return ret;
}

void ProcessConnect(int sock,int epoll_fd)
{
    sockaddr_in peer;
    socklen_t len = sizeof(peer);
    int new_sock = accept(sock,(sockaddr*)&peer,&len);
    if(new_sock < 0)
    {
        perror("accept");
        return;
    }
    printf("client [%s : %d] connect\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port));
    //new_sock也要设置为非阻塞
    SetNoBlock(new_sock);
    epoll_event event;
    event.events = EPOLLIN | EPOLLET;   //注意:要添加上ET选型,边缘出发
    event.data.fd = new_sock;
    //把new_sock添加进epoll句柄之中
    int ret_ctl = epoll_ctl(epoll_fd,EPOLL_CTL_ADD,new_sock,&event);
    if(ret_ctl < 0)
    {
        perror("epoll_ctl");
        return;
    }
}

ssize_t NoBlockRead(int sock,char output[],int size)
{
    ssize_t total_size = 0;
    while(1)
    {
        ssize_t buf_size = (size - total_size) > 1024 ? 1024:(size - total_size);
        //采取非阻塞的轮训方式进行读
        ssize_t read_size = read(sock,output + total_size,buf_size);
        total_size += read_size;
        if(errno == EAGAIN && read_size < 0)
        {
            //表示缓冲区读完了
            break;
        }
        //对于read_size < 0但是errno != EAGAIN的情况不管
        if(read_size == 0)
        {
            //读到了结尾
            break;
        }
    }
    output[total_size] = '\0';
    return total_size;
}

void ProcessRequst(int sock,int epoll_fd)
{
    //读客户端的请求
    char buf[1024] = {0};
    ssize_t read_size = NoBlockRead(sock,buf,sizeof(buf) - 1);
    
    if(read_size < 0)
    {
        perror("read_size");
        return;
    }
    if(read_size == 0)
    {
        close(sock);
        epoll_ctl(epoll_fd,EPOLL_CTL_DEL,sock,NULL);
        printf("client %d disconnect.\n",sock);
        return;
    }
    //回显给客户端
    buf[read_size] = '\0';
    printf("client %d say:%s\n",sock,buf);
    write(sock,buf,strlen(buf));
}
int server_start(char* ip,short port)
{
    int listen_sock = socket(AF_INET,SOCK_STREAM,0);
    if(listen_sock < 0)
    {
        perror("socket");
        return -1;
    }
    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);
    server.sin_port = htons(port);

    int ret = bind(listen_sock,(sockaddr*)&server,sizeof(server));
    if(ret < 0)
    {
        perror("bind");
        return -1;
    }
    ret = listen(listen_sock,5);
    if(ret < 0)
    {
        perror("listen");
        return -1;
    }
    return listen_sock;
}
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./server [ip] [port]\n");
        return 1;
    }
    int listen_sock = server_start(argv[1],atoi(argv[2]));
    if(listen_sock < 0)
    {
        printf("server_start failed.\n");
        return 1;
    }
    printf("server_start success\n");
    //使用epoll的边缘触发原理
    //socket创建的文件描述符默认都是阻塞的,首先将其改为非阻塞
    int ret = SetNoBlock(listen_sock);
    if(ret < 0)
    {
        printf("非阻塞设置失败.\n");
        return 1;
    }
    //创建文件句柄
    int epoll_fd = epoll_create(10);
    if(epoll_fd < 0)
    {
        perror("epoll_create");
        return 1;
    }
    //创建文件句柄
    epoll_event event;
    event.events = EPOLLIN | EPOLLET;  //添加ET选项
    event.data.fd = listen_sock;
    int ret_ctl = epoll_ctl(epoll_fd,EPOLL_CTL_ADD,listen_sock,&event);
    if(ret_ctl < 0)
    {
        perror("epoll_ctl");
        return 1;
    }
    //下面就进入事件循环之中
    while(1)
    {
        //进行等待
        epoll_event events[10];
        int ret_wait = epoll_wait(epoll_fd,events,sizeof(events)/sizeof(events[0]),-1);
        if(ret_wait < 0)
        {
            perror("epoll_wait");
            continue;
        }
        if(ret_wait == 0)
        {
            printf("timeout");
            continue;
        }
        int i = 0;
        for(i = 0;i < ret_wait;++i)
        {
            if(!(events[i].events & EPOLLIN))
            {
                continue;
            }
            if(events[i].data.fd == listen_sock)
            {
                //Do accept
                ProcessConnect(listen_sock,epoll_fd);
            }
            else
            {
                //Read Write
                ProcessRequst(events[i].data.fd,epoll_fd);
            }
        }
    }
    return 0;
}
