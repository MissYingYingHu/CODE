#include <stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#define Backlog 10

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./service [ip] [port]\n");
        return 1;
    }
    int ser_sock = socket(AF_INET,SOCK_STREAM,0);
    if(ser_sock < 0)
    {
        perror("socket\n");
        return 1;
    }
    sockaddr_in in_addr;
    in_addr.sin_family = AF_INET;
    in_addr.sin_addr.s_addr = inet_addr(argv[1]);
    in_addr.sin_port = htons(atoi(argv[2]));
    //绑定端口号与IP
    int ret = bind(ser_sock,(sockaddr*)&in_addr,sizeof(in_addr));
    if(ret < 0)
    {
        perror("bind failed\n");
        return 1;
    }
    //将服务器变为被动形式,开始监听
    int listen_ret = listen(ser_sock,Backlog);
    if(listen_ret < 0)
    {
        perror("监听失败");
        close(ser_sock);
        return 1;
    }
    printf("listening success...\n");
    sockaddr_in client;
    socklen_t len = sizeof(client);
    while(1)
    {
        //接收请求,该函数返回的是一个文件描述符
        int accept_ret = accept(ser_sock,(sockaddr*)&client,&len);
        if(accept_ret < 0)
        {
            perror("accept failed\n");
            close(ser_sock);
            return 2;
        }
        char buf[1024] = {0};
        while(1)
        {
            ssize_t read_size = read(accept_ret,buf,sizeof(buf) - 1);
            if(read_size < 0)
            {
                continue;
            }
            else if (read_size == 0)
            {
                //如果读到了0,也表示对方已经关闭了连接
                printf("disconnect!\n");
                close(accept_ret);
                break;   //如果有其它的客户端请求时,就会在第一个客户端退出后,跳出次循环,然后重新调用accept()来执行该进程的请求.
                //return 0;     
                //如果使用了return就会直接退出该进程,因为这个return是在main()中.
            }
            else
            {
                buf[read_size] = '\0';
                printf("client:-%s:%d--says:%s\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port),buf);
            }
            write(accept_ret,buf,strlen(buf));
        }
    }
    close(ser_sock);
    return 0;
}
