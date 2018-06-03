#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//从管道中读到标准输出
int main()
{
    int mk = mkfifo("./fifo",0666);
    if(mk < 0)
    {
        return 1;
    }
    int fd = open("./fifo",O_RDONLY);
    if(fd == -1)
    {
        return 1;
    }
    while(1)
    {
        char buf[1024] = {0};
        ssize_t size = read(fd,buf,sizeof(buf) - 1);
        if(size > 0)
        {
            printf("%s\n",buf);
        }
        else if(size == 0)
        {
            break;
        }
        else
        {
            perror("read");
            _exit(1);
        }
    }
    close(fd);
    return 0;
}
