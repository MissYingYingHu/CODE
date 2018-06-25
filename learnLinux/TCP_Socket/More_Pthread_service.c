#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<pthread.h>

//基于多线程实现的服务器
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;

typedef struct Arg
{
    int fd;
    sockaddr_in in_addr;
}Arg;
void* PthreadEntry(void* arg)
{
    Arg* client = (Arg*)arg;
    char buf[1024] = {0};
    while(1)
    {
        //读取客户端的请求
        //响应客户端
        ssize_t read_size = read(client->fd,buf,sizeof(buf) - 1);
        if(read_size < 0)
        {
            perror("read\n");
            continue;
        }
        else if(read_size == 0)
        {
            printf("disconnect!!!\n");
            close(client->fd);
            return NULL;
        }
        else
        {
            buf[read_size] = '\0';
            printf("client[%s:%d] sys:%s\n",inet_ntoa(client->in_addr.sin_addr),
                   ntohs(client->in_addr.sin_port),buf);
            write(client->fd,buf,strlen(buf));
        }
    }
    return NULL;
}
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./More_Pthread_service [ip] [port]\n");
        return 1;
    }
    int ser_ret = socket(AF_INET,SOCK_STREAM,0);
    if(ser_ret < 0)
    {
        perror("socket\n");
        return 1;
    }
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(argv[1]);
    service.sin_port = htons(atoi(argv[2]));
    int bind_ret = bind(ser_ret,(sockaddr*)&service,sizeof(service));
    if(bind_ret < 0)
    {
        perror("bind failed\n");
        return 1;
    }
    int listen_ret = listen(ser_ret,3);
    if(listen_ret < 0)
    {
        perror("listen\n");
        return 1;
    }
    printf("listen success\n");
    while(1)
    {
        sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int acc_ret = accept(ser_ret,(sockaddr*)&peer,&len);
        if(acc_ret < 0)
        {
            perror("accept\n");
            continue;
        }
        Arg* arg = (Arg*)malloc(sizeof(Arg));
        arg->fd = acc_ret;
        arg->in_addr = peer;
        pthread_t tid;
        pthread_create(&tid,NULL,PthreadEntry,(void*)arg);
        pthread_detach(tid);
    }
    return 0;
}
