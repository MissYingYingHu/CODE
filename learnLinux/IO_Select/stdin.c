#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>
#include<sys/time.h>

int main()
{
    struct timeval t;
    while(1)
    {
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(0,&read_fds);
        //每次都要初始化,当文件描述符变多时,将该初始化放在外面,就会存在有的描述符可能会越来越少.
        t.tv_sec = 2;
        t.tv_usec = 20;
        printf(">");
        fflush(stdout);
        int ret = select(1,&read_fds,NULL,NULL,&t);
        //select:第一个参数表示有效的文件描述符的最大值+1
        //返回的是有效的描述符的个数
        //返回0,表示超时
        //返回-1,表示出现了致命的错误
        if(ret == 0)
        {
            //如果超时了就会返回0
            printf("ret == 0\n");
        }
        if(ret < 0)
        {
            perror("select");
            return 1;
        }
        if(FD_ISSET(0,&read_fds))
        {
            //0号描述符读就绪
            char buf[1024] = {0};
            ssize_t read_size  = read(0,buf,sizeof(buf) - 1);
            if(read_size < 0)
            {
                perror("read");
                continue;
            }
            if(read_size == 0)
            {
                printf("read done\n");
                return 0;
            }
            printf("stdout:%s",buf);
        }
    }
    return 0;
}
