#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./client [ip] [port]");
        return 1;
    }
    int ret_sock = socket(AF_INET,SOCK_STREAM,0);
    if(ret_sock < 0)
    {
        perror("socket");
        return 1;
    }
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    int ret_connect = connect(ret_sock,(sockaddr*)&addr,sizeof(addr));
    if(ret_connect < 0)
    {
        perror("connect");
        return 1;
    }
    printf("success connect\n");
    while(1)
    {
        printf(">");
        fflush(stdout);
        char buf[1024] = {0};
        read(0,buf,sizeof(buf) - 1);
        ssize_t write_size = write(ret_sock,buf,strlen(buf));
        if(write_size < 0)
        {
            perror("write");
            continue;
        }
        ssize_t read_size = read_size = read(ret_sock,buf,sizeof(buf) - 1);
        if(read_size < 0)
        {
            perror("read");
            return 1;
        }
        if(read_size == 0)
        {
            printf("read done");
            break;
        }
        printf("response:%s\n",buf);
    }
    close(ret_sock);
    return 0;
}
