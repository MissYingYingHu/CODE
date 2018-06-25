#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<sys/wait.h>

//在service.c中,当一个客户端发出请求后并连接成功后(就会一直在while()中循环的去read,
//不能再去调用accept函数,所以就不能接收到新的请求),其它的客户端就不能连接到服务器了.
//
//所以这个服务器是基于多进程而实现的.
typedef struct sockaddr sockaddr;
typedef struct sockaddr_in sockaddr_in;
void Process(int acc_ret,sockaddr_in* client)
{
    char buf[1024] = {0};
    while(1)
    {
        //服务器读取客户端的请求并作出相应
        ssize_t read_size = read(acc_ret,buf,sizeof(buf) - 1);
        if(read_size < 0)
        {
            perror("read failed \n");
            continue;
        }
        else if(read_size == 0)
        {
            printf("client [%s:%d] disconnect\n",inet_ntoa(client->sin_addr),ntohs(client->sin_port));
            close(acc_ret);
            return;
        }
        else
        {
            buf[read_size] = '\0';
            printf("client says:[%s:%d]==:%s\n",inet_ntoa(client->sin_addr),ntohs(client->sin_port),buf);
            write(acc_ret,buf,strlen(buf));
        }
    }
}
void ProcessWork(int acc_ret,sockaddr_in* client)
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork failed\n");
        exit(1);
    }
    else if(pid == 0)
    {
        //child
        if(fork() == 0)
        {
            //grand_child
            Process(acc_ret,client);
        }
        //child退出,grand_child就会变为孤儿进程,然后被一号进程领养.
        exit(0);
    }
    else
    {
        //father
        close(acc_ret);
        waitpid(pid,NULL,0);
    }
}
int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        printf("Usage:./More_Process_service [ip] [port]\n");
        return 1;
    }
    int ser_sock = socket(AF_INET,SOCK_STREAM,0);
    if(ser_sock < 0)
    {
        perror("socket failed\n");
        return 1;
    }
    sockaddr_in in_addr;
    in_addr.sin_family = AF_INET;
    in_addr.sin_port = htons(atoi(argv[2]));
    in_addr.sin_addr.s_addr = inet_addr(argv[1]);
    int ret = bind(ser_sock,(sockaddr*)&in_addr,sizeof(in_addr));
    if(ret < 0)
    {
        printf("bind failed\n");
        return 1;
    }
    int listen_ret = listen(ser_sock,3);
    if(listen_ret < 0)
    {
        perror("listen failed\n");
        return 1;
    }
    printf("listen success....\n");
    while(1)
    {
        sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int acc_ret = accept(ser_sock,(sockaddr*)&peer,&len);
        if(acc_ret < 0)
        {
            perror("accept failed\n");
            continue;
        }
        ProcessWork(acc_ret,&peer);
    }
    return 0;


}
