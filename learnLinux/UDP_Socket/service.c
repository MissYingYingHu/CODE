#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
//服务器:
//1.接收来自客户端的消息
//2.根据接收的消息进行计算响应
//3.将响应返回给客户端

int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./service [ip] [port]\n");
        return 1;
    }
    //创建一个socket文件,第一个参数表示IPV4协议,第二个参数表示是数据报格式传输
    int ser_sock = socket(AF_INET,SOCK_DGRAM,0);
    if(ser_sock < 0)
    {
        perror("socket\n");
        return 1;
    }
    struct sockaddr_in addr_in;
    addr_in.sin_family = AF_INET;
    addr_in.sin_addr.s_addr = inet_addr(argv[1]);
    addr_in.sin_port = htons(atoi(argv[2]));
    //绑定端口号,IP地址,通过参数传进来
    int ret = bind(ser_sock,(struct sockaddr*)&addr_in,sizeof(addr_in));
    if(ret < 0)
    {
        perror("bind绑定失败\n");
        return 1;
    }
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    char buf[1024] = {0};
    while(1)
    {
        ssize_t rece_size = recvfrom(ser_sock, buf, sizeof(buf)-1,0,(struct sockaddr*)&client, &len);
        if(rece_size < 0)
        {
            perror("没有消息.\n");
            continue;
        }
        buf[rece_size] = '\0';
        printf("client[ip:%s----port:%d] sys:%s\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port),buf);
        sendto(ser_sock,buf,strlen(buf),0,(struct sockaddr*)&client,sizeof(client));
    }
    close(ser_sock);
    return 0;
}

