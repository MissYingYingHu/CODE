#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/poll.h>

int main()
{
    while(1)
    {
        struct pollfd pfd;
        pfd.fd = 0;
        pfd.events = POLLIN;
        while(1)
        {
            int ret = poll(&pfd,1,10000);
            if(ret < 0)
            {
                perror("poll");
                return 1;
            }
            if(ret == 0)
            {
                printf("timeout\n");
                continue;
            }
            if(pfd.revents == POLLIN)
            {
                char buf[1024] = {0};
                ssize_t read_size = read(0,buf,sizeof(buf) - 1);
                if(read_size < 0)
                {
                    perror("read");
                    continue;
                }
                if(read_size == 0)
                {
                    printf("read done");
                }
                printf("%s\n",buf);
            }
        }
    }
    return 0;
}
