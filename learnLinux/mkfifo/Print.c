#include "common.h"
#include<unistd.h>

int main()
{
    int semid = CreateSeg();
    SetSeg(semid,0,1);
    pid_t pid = fork();
    if(pid > 0)
    {
        //father打印AA
        while(1)
        {
            P(semid,0);
            printf("A");
            fflush(stdout);
            usleep(123345);
            printf("A ");
            fflush(stdout);
            usleep(456678);
            V(semid,0);
        }
    }
    else if(pid == 0)
    {
        //son
        while(1)
        {
            P(semid,0);
            printf("B");
            fflush(stdout);
            usleep(223345);
            printf("B ");
            fflush(stdout);
            usleep(956678);
            V(semid,0);
        }
    }
    else
    {
        perror("fork");
        return 0;
    }
    DestroySeg(semid);
    return 0;
}

