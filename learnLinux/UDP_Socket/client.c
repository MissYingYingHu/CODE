#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
//客户端:
//1.发消息给客户端
//2.接收服务器的响应
typedef struct sockaddr sockaddr;
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./client [ip] [port]\n");
        return 1;
    }
    int cli_sock = socket(AF_INET,SOCK_DGRAM,0);
    if(cli_sock < 0)
    {
        perror("socket\n");
        return 1;
    }
    struct sockaddr_in service;
    service.sin_family = AF_INET;
    service.sin_addr.s_addr = inet_addr(argv[1]);
    service.sin_port = htons(atoi(argv[2]));
    struct sockaddr_in peer;
    socklen_t len = sizeof(peer);
    while(1)
    {
        printf("I am client ,sys:");
        fflush(stdout);
        char buf[1024] = {0};
        ssize_t read_size = read(0,buf,sizeof(buf) - 1);
        if(read_size < 0)
        {
            perror("read falied\n");
            return 1;
        }
        buf[read_size] = '\0';
        sendto(cli_sock,buf,strlen(buf),0,(sockaddr*)&service,sizeof(service));
        ssize_t rece_ser = recvfrom(cli_sock,buf,sizeof(buf) - 1,0,(sockaddr*)&peer,&len);
        if(rece_ser > 0)
        {
            buf[rece_ser] = '\0';
            printf("service response:%s\n",buf);
        }
    }
    close(cli_sock);
    return 0;
}
