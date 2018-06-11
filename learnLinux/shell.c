#include <stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#define MAX_SIZE 1024
void do_parse(char *buf1[],char *buf2[])
{
    char buffer[1024] = {0};
    char tmp[1024] = {0};
    char tmp1[1024] = {0};
    gets(buffer);
    size_t index = 0;
    size_t i = 0;
    for(;(buffer[index] != '|') && (buffer[index] != '\0');++index)
    {
        tmp[index] = buffer[index];
    }
    if(buffer[index] == '|')
    {
        ++index;
        for(;buffer[index] != '\0';++index)
        {
            tmp1[i++] = buffer[index];
        }
    }
    char* p = strtok(tmp," ");
    index = 0;
    while(p)
    {
        buf1[index++] = p;
        p = strtok(NULL," ");
    }
    buf1[index] = NULL;
    index = 0;
    p = strtok(tmp1," ");
    while(p)
    {
        buf2[index++] = p;
        p =  strtok(NULL," ");
    }
    buf2[index] = NULL;
}
int Common_exec(char* argv[])
{
    pid_t pid = fork();
    if(pid == -1)
    {
        perror(argv[0]);
        return 1;
    }
    else if(pid == 0)
    {
        int ret = execvp(argv[0],argv);
        if(ret < 0)
        {
            perror(argv[0]);
            _exit(0);
        }
    }
    else
    {
        wait(NULL);
    }
    return 0;
}
int Pipe_exec(char* argv[],char* argv1[])
{
    pid_t pid2 = 0;
    int fd[2];
    int ret = pipe(fd);
    if(ret == -1)
    {
        perror("pipe");
        return 1;
    }
    pid_t pid1 = fork();
    if(pid1 > 0)
    {
        //父进程
        pid2 = fork();
        if(pid2 == 0)
        {
            //子进程,关闭写端,将通道中的东西读出来
            close(fd[1]);
            int ret = dup2(fd[0],0);
            if(ret == -1)
            {
                return 1;
            }
            int r = execvp(argv1[0],argv1);
            if(r < 0)
            {
                perror(argv1[0]);
                _exit(1);
            }
        }
        wait(NULL);
    }
    else if(pid1 == 0)
    {
        //子进程,关闭读端,写端将管道左侧的部分命令实现及写到管道中
        close(fd[0]);
        int ret = dup2(fd[1],1);
        if(ret == -1)
        {
            return 1;
        }
        int r = execvp(argv[0],argv);
        if(r == -1)
        {
            perror(argv[0]);
            _exit(1);
        }
    }
    else
    {
        perror("fork()");
        _exit(1);
    }
    return 0;
}
int do_exec(char* argv[],char* argv1[])
{
    if (argv1[0] == NULL)
    {
        Common_exec(argv);
    }
    else
    {
        Pipe_exec(argv,argv1);
    }
    return 0;
}
int main()
{
    char* argv[1024] = {NULL};
    char* argv1[1024] = {NULL};
    while(1)
    {
        char name[255] = {0};
        gethostname(name,256);
        char* _name = strtok(name,".");
        char dir[1024] = {0};
        getcwd(dir,MAX_SIZE);
        printf("[myshell@%s %s] ",_name,dir);
        fflush(stdout);
        //1.从标准输入获取命令,然后解析字符串,解析出指令和参数
        do_parse(argv,argv1);
        //2.创建一个子进程,替换子进程,父进程等待子进程退出
        do_exec(argv,argv1);
    }
    return 0;
}
