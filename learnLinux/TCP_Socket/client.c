#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./client [ip] [port]\n");
        return 1;
    }
    int cli_sock = socket(AF_INET,SOCK_STREAM,0);
    if(cli_sock < 0)
    {
        perror("socket\n");
        return 1;
    }
    sockaddr_in in_addr;
    in_addr.sin_family = AF_INET;
    in_addr.sin_addr.s_addr = inet_addr(argv[1]);
    in_addr.sin_port = htons(atoi(argv[2]));
    int con_client = connect(cli_sock,(sockaddr*)&in_addr,sizeof(in_addr));
    if(con_client < 0)
    {
        perror("connect failed\n");
        return 1;
    }
    printf("connect success\n");
    while(1)
    {
        printf("client says:");
        fflush(stdout);
        char buf[1024] = {0};
        int read_size = read(0,buf,sizeof(buf) - 1);
        if(read_size < 0)
        {
            perror("read failed");
            return 1;
        }
        else
        {
            buf[read_size] = '\0';
            //printf("%s\n",buf);
            write(cli_sock,buf,strlen(buf));
        }
        read_size = read(cli_sock,buf,sizeof(buf) - 1);
        if(read_size > 0)
        {
            buf[read_size] = '\0';
            printf("service response:%s\n",buf);
        }
    }
    close(cli_sock);
    return 0;
}
