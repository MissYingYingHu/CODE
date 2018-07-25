#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/stat.h>
//守护进程的创建:
//1.创建子进程,父进程终止,子进程继续执行
//2.子进程调用setsid
//3.忽略SIGHUP信号
//4.忽略SIGCHILD信号
//5.修改工作目录为 /
//6.重定向文件描述符
//7.修改umask
void mydeamon()
{
    int pid = fork();
    if(pid < 0)
    {
        perror("fork\n");
        return;
    }
    if(pid > 0)
    {
        //father
        exit(0);
    }
    setsid();
    signal(SIGHUP,SIG_IGN);
    signal(SIGCHLD,SIG_IGN);
    chdir("/");
    int fd = open("/dev/null",O_RDWR); //该文件相当于Linux中的垃圾桶
    if(fd < 0)
    {
        perror("open\n");
        return;
    }
    dup2(fd,1);
    dup2(fd,2);
    umask(0); 
}
int main()
{
    //mydeamon();
    daemon(0,0);
    while(1)
    {
        sleep(1);
    }
    return 0;
}
