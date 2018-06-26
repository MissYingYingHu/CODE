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
        printf("Usage:./Calculator_client [ip] [port]\n");
        return 1;
    }
    int cli_sock = socket(AF_INET,SOCK_DGRAM,0);
    if(cli_sock < 0)
    {
        perror("socket failed\n");
        return 1;
    }
    sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(argv[1]);
    service.sin_port = htons(atoi(argv[2]));
    Requst req;
    Response res;
    socklen_t len = sizeof(service);
    while(1)
    {
        printf("请分别输入求和的第一个参数和第二个参数\n");
        fflush(stdout);
        scanf("%d%d",&req.x,&req.y);
        req.x = htonl(req.x);
        req.y = htonl(req.y);
        ssize_t send_size = sendto(cli_sock,&req,sizeof(req),0,(sockaddr*)&service,sizeof(service));
        if(send_size < 0)
        {
            perror("sendto \n");
            return 1;
        }
        ssize_t read_size = recvfrom(cli_sock,&res,sizeof(res),0,(sockaddr*)&service,&len);
        if(read_size > 0)
        {
            printf("service response:sum = %d\n",ntohl(res.sum));
        }
    }
    return 0;
}
