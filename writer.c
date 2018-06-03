#include <stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

//写到管道中
int main()
{
//    int mk = mkfifo("./fifo",0666);
//    if(mk == -1)
//    {
//        return 1;
//    }
    int fd = open("./fifo",O_WRONLY);
    if(fd == -1)
    {
        return 1;
    }
    int buf[1024] = {0};
    while(1)
    {
        ssize_t size = read(0,buf,sizeof(buf) - 1);
        if(size == 0)
        {
            _exit(0);
        }
        else if(size > 0)
        {
            buf[size] = '\0';
            write(fd,buf,size);
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
