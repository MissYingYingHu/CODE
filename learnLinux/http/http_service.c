#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
void* Handler_requst(void* arg)
{
    int64_t sock = (int64_t)arg;   //如果用int,而64位平台下指针是8字节,如果用int就会丢失4个字节.
    char input_buf[1024*10] = {0};
    ssize_t rd = read(sock,input_buf,sizeof(input_buf) - 1);
    if (rd < 0)
    {
        return NULL;
    }
    input_buf[rd] = '\0';
    printf("%s", input_buf);
    //把响应写回到客户端
    const char* first_line = "HTTP:/1.1 200 OK\n";
     const char* black_line = "\n";
    const char* body = "<h1>Hello World</h1>";
    char header[1024] = {0};
    sprintf(header,"Content-Length: %lu\nContent-Type: text/html\n",strlen(body));
    write(sock,first_line,strlen(first_line));
    write(sock,header,strlen(header));
    write(sock,black_line,strlen(black_line)); 
    write(sock,body,strlen(body));
    close(sock); 
    return NULL;
}
int Connect(char* ip,short port)
{
    int sock_ret = socket(AF_INET,SOCK_STREAM,0);
    if(sock_ret < 0)
    {
        perror("socket\n");
        return 1;
    }
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(ip);
    service.sin_port = htons(port);
    int bind_ret = bind(sock_ret,(sockaddr*)&service,sizeof(service));
    if(bind_ret < 0)
    {
        perror("bind\n");
        return 1;
    }
    int listen_ret = listen(sock_ret,5);
    if(listen_ret < 0)
    {
        perror("listen failed\n");
        return 1;
    }
    return sock_ret;
}
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./http_service [ip] [port]\n");
        return 1;
    }
    int listen_sock = Connect(argv[1],atoi(argv[2]));
    if(listen_sock < 0)
    {
        perror("listen_sock failed\n");
        return 1;
    }
    while(1)
    {
        sockaddr_in client;
        socklen_t len = sizeof(client);
        int64_t accept_ret = accept(listen_sock,(sockaddr*)&client,&len);
        if(accept_ret < 0)
        {
            perror("accept failed\n");
            continue;
        }
        pthread_t tid;
        pthread_create(&tid,NULL,Handler_requst,(void*)accept_ret);
        pthread_detach(tid);
    }
    return 0;
}
