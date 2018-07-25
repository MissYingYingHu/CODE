#include <stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>


void hander(int signo)
{
    printf("sig = %d\n",signo);
    //exit(1);
}
void Print(sigset_t *set)
{
    int i = 1;
    for(i = 1;i < 32;++i)
    {
        if(sigismember(set,i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
    printf("\n");
}
int main()
{
    //1.捕捉信号
    //2.设置信号屏蔽字
    //3.读取信号屏蔽字
    signal(SIGINT,hander);
    sigset_t set,oldset;
    sigemptyset(&set);
    sigaddset(&set,SIGINT);
    sigprocmask(SIG_BLOCK,&set,&oldset);
    int count = 0;
    while(1)
    {
        ++count;
        if(count == 5)
        {
            count = 0;
            printf("解除信号屏蔽字\n");
            sigprocmask(SIG_SETMASK,&oldset,NULL);
            sleep(1);
            printf("重新设置信号屏蔽字\n");
            sigprocmask(SIG_BLOCK,&set,NULL);
        }
        sleep(1);
        sigset_t p;
        sigpending(&p);
        Print(&p);
    }
    return 0;
}
