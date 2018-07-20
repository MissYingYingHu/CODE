#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>
#include <fcntl.h>

//把文件描述符设置为非阻塞
int SetNoFlag(int fd)
{
    int flag = fcntl(fd,F_GETFL);
    if(flag < 0)
    {
        perror("fcntl");
        return -1;
    }
    int ret = fcntl(fd,F_SETFL,flag|O_NONBLOCK);
    if(ret < 0)
    {
        perror("fcntl");
        return -1;
    }
    return ret;
}
int main()
{
    SetNoFlag(0);
    char buf[1024] = {0};
    while(1)
    {
        ssize_t read_size = read(0,&buf,sizeof(buf) - 1);
        if(read_size < 0)
        {
            perror("read");
            continue;
        }
        if(read_size == 0)
        {
            return 0;
        }
        printf("%s\n",buf);
    }
    return 0;
}
