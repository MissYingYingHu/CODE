#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
//获取最大的文件描述符
typedef struct fds
{
    fd_set fd;
    int max_fd;   //当前文件描述符中最大的文件描述符
}fds;

void FD_SET_init(fds *set)
{
    if(set == NULL)
    {
        return;
    }
    set->max_fd = -1;
    FD_ZERO(&set->fd);
}

void Set_Add(fds *set,int fd)
{
    if(set == NULL)
    {
        return;
    }
    FD_SET(fd,&set->fd);
    if(fd > set->max_fd)
    {
        set->max_fd = fd;
    }
}

void Del_Set(fds *set,int fd)
{
    if(set == NULL)
    {
        return;
    }
    FD_CLR(fd,&set->fd);
    int max = -1;
    int i = 0;
    for(i = 0;i <= set->max_fd;++i)
    {
        if(!FD_ISSET(i,&set->fd))
        {
            continue;
        }
        if(max < i)
        {
            max = i;
        }
    }
    set->max_fd = max;
}

int start_server(const char* ip,short port)
{
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        perror("socket");
        return -1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    
    //绑定
    int ret_bind = bind(sock,(sockaddr*)&addr,sizeof(addr));
    if(ret_bind < 0)
    {
        perror("bind");
        return -1;
    }

    //将服务器变为被动形式,进行监听
    int ret_listen = listen(sock,5);
    if(ret_listen < 0)
    {
        perror("listen");
        return -1;
    }
    return sock;
}
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./select_server [ip] [port]\n");
        return 1;
    }
    //初始化服务器
    int ret = start_server(argv[1],atoi(argv[2]));
    if(ret < 0)
    {
        printf("start failed\n");
        return 1;
    }
    printf("server success\n");
    //进入循环事件
    fds rfd;
    printf("%lu\n",sizeof(rfd.fd));
    FD_SET_init(&rfd);
    Set_Add(&rfd,ret);
    while(1)
    {
        //为了保证accept返回的也可以添加到读就绪中.
        fds fd = rfd;
        //原来写的服务器的阻塞等待是由read和write完成的.现在使用select来完成这个过程.
        //该服务器仍是属于回显服务器,接收到什么就回复什么
        int ret_sel = select(fd.max_fd + 1,&fd.fd,NULL,NULL,NULL);
        if(ret_sel < 0)
        {
            perror("select");
            continue;
        }
        if(ret_sel == 0)
        {
            printf("timeout\n");
            continue;
        }
        //说明现在有就绪的文件描述符
        if(FD_ISSET(ret,&fd.fd))
        {
            //并且就绪的文件描述符是ret读就绪
            //此时就要调用accept,获取连接
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);
            int ret_accept = accept(ret,(struct sockaddr*)&peer,&len);
            if(ret_accept < 0)
            {
                perror("accept");
                continue;
            }
            //如果ret就绪,就要将它添加到读继续中
            Set_Add(&rfd,ret_accept);
            printf("client %d id connected\n",ret_accept);
        }
        else
        {
            //此时返回的是accept的就绪
            int i = 0;
            char buff[1024] = {0};
            for(i = 0;i <= fd.max_fd;++i)
            {
                if(!FD_ISSET(i,&fd.fd))
                {
                    continue;
                }
                //在这儿不使用循环读写,因为等待的过程都是有select完成
                ssize_t read_size = read(i,buff,sizeof(buff) - 1);
                if(read_size < 0)
                {
                    perror("read");
                    continue;
                }
                if(read_size == 0)
                {
                    //如果读完了就要关闭该文件描述符
                    printf("%dread done,goodbye\n",i);
                    close(i);
                    Del_Set(&rfd,i);
                }
                else
                {
                    printf("文件描述符%d,说%s\n",i,buff);
                    write(i,buff,strlen(buff));
                }
            }//end else(for)
        }//end else
    }//end while
    return 0;
}
