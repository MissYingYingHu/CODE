#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/epoll.h>


typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
typedef struct epoll_event epoll_event;

int server_start(char* ip,short port)
{
    //创建socket文件描述符
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
    //绑定端口号
    int ret = bind(listen_sock,(sockaddr*)&server,sizeof(server));
    if(ret < 0)
    {
        perror("bind");
        return -1;
    }
    //开始监听socket,由主动变为被动
    ret = listen(listen_sock,5);
    if(ret < 0)
    {
        perror("listen");
        return -1;
    }
    return listen_sock;
}

//处理accept就绪的文件描述符
void ProcessConnect(int socket_sock,int epoll_fd)
{
    sockaddr_in peer;
    socklen_t len = sizeof(peer);
    int new_sock = accept(socket_sock,(sockaddr*)&peer,&len);
    if(new_sock < 0)
    {
        perror("accept");
        return;
    }
    printf("client:[%s : %d] connect\n",inet_ntoa(peer.sin_addr),ntohs(peer.sin_port));
    epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = new_sock;
    int ret_ctl = epoll_ctl(epoll_fd,EPOLL_CTL_ADD,new_sock,&event);
    if(ret_ctl < 0)
    {
        perror("epoll_ctl");
        return;
    }
}

//处理连接请求
void ProcessRequst(int accept_sock,int epoll_fd)
{
    char buf[1024] = {0};
    int read_size = read(accept_sock,buf,sizeof(buf) - 1);
    if(read_size < 0)
    {
        perror("read");
        return;
    }
    if(read_size == 0)
    {
        //读完了
        epoll_event event;
        event.events = EPOLLIN;
        event.data.fd = accept_sock;
        int ret_ctl = epoll_ctl(epoll_fd,EPOLL_CTL_DEL,accept_sock,&event);
        if(ret_ctl < 0)
        {
            perror("epoll_ctl Del");
            return;
        }
        printf("client %d disconnect.\n",accept_sock);
        close(accept_sock);
        return;
    }
    printf("client %d says:%s\n",accept_sock,buf);
    write(accept_sock,buf,strlen(buf));
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
        printf("server_start failed\n");
        return 1;
    }
    printf("server_start success\n");
    
    //1.创建一个epoll对象,相当于一个epoll句柄
    int ret_create = epoll_create(5);
    if(ret_create < 0)
    {
        perror("epoll_create");
        return 1;
    }
    //epoll的注册事件函数,该函数有4个参数
    //第一个参数:是创建的那个epoll句柄
    //第二个参数:表示该句柄管理的事件类型:
                //a)EPOLL_CTL_ADD:表示将就绪的文件描述符添加进句柄之中
                //b)EOPLL_CTL_MOD:表示修改已经添加进去的文件描述符
                //c)EPOLL_CTL_DEL:表示从句柄之中删除不再使用的文件描述符
    //第三个参数:表示事件对应的文件描述符
    //第四个参数:是一个结构体指针,该结构体里面包含的是对应的文件描述符是属于什么类型,读?写?错误?....
    epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = listen_sock;
    int ret_ctl = epoll_ctl(ret_create,EPOLL_CTL_ADD,listen_sock,&event);
    if(ret_ctl < 0)
    {
        perror("epoll_ctl");
        return 1;
    }
    //进入循环事件
    while(1)
    {
        //进行等待就绪的文件描述符,即等待数据已经进入缓冲区中的文件描述符
        //若返回的结果大于0表示已经就绪的文件描述符的数目,返回0表示已经超时,小于0表示函数失败.
        epoll_event events[10];
        int ret_wait = epoll_wait(ret_create,events,sizeof(events)/sizeof(events[0]),-1);
        //printf("%d\n",ret_wait);   
        //若在同一台电脑上进行测试,多个客户端进行连接服务器,那么这里只会返回1,因为多个客户端不可能同时发送消息
        //参数讲解:
        //第一个参数:表示准备好的epoll句柄
        //第二个参数:是一个输出型参数,结构体指针,表示是分配好的epoll_event结构体数组
        //第三个参数:表示event数组的大小,其值不能大于创建epoll_create()时的size
        //第四个参数:超时时间.-1表示阻塞方式,0表示非阻塞式,大于0就表示等待的时间
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
                //处理listen_sock
                ProcessConnect(listen_sock,ret_create);
            }
            else
            {
                //处理connect请求
                ProcessRequst(events[i].data.fd,ret_create);
            }
        }//end for
    }//end while
    return 0;
}
