#include"Protocol.h"
#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./Calculator_service [ip] [port]\n");
        return 1;
    }
    int ser_sock = socket(AF_INET,SOCK_DGRAM,0);
    if(ser_sock < 0)
    {
        perror("socket\n");
        return 1;
    }
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(argv[1]);
    service.sin_port = htons(atoi(argv[2]));
    int bind_ret = bind(ser_sock,(sockaddr*)&service,sizeof(service));
    if(bind_ret < 0)
    {
        perror("bind failed\n");
        return 1;
    }
    printf("bind success\n");
    sockaddr_in client;
    socklen_t len = sizeof(client);
    while(1)
    {
        Requst req;
        ssize_t reve_size = recvfrom(ser_sock,&req,sizeof(req),0,(sockaddr*)&client,&len);
        if(reve_size < 0)
        {
            printf("recvfrom failed\n");
            continue;
        }
        Response res;
        res.sum = ntohl(req.x) + ntohl(req.y);
        printf("service response client [%s:%d],sum = %d\n",
               inet_ntoa(client.sin_addr),ntohs(client.sin_port),res.sum);
        res.sum = htonl(res.sum);
        sendto(ser_sock,&res,sizeof(res),0,(sockaddr*)&client,sizeof(client));
    }
    return 0;
}
