#include <stdio.h>
#include<signal.h>
#include<unistd.h>


void Handler(int sig)
{
    printf("sig = %d\n",sig);
}
void _sleep(int second)
{
    //捕捉信号.记录原来的信号
    __sighandler_t old = signal(SIGALRM,Handler);
    sigset_t set,oldset;
    //初始化信号
    sigemptyset(&set);
    //将闹钟信号添加上去
    sigaddset(&set,SIGALRM);
    //设置闹钟信号为阻塞信号
    sigprocmask(SIG_BLOCK,&set,&oldset);
    alarm(second);
    //用参数的值替换信号屏蔽字,在这里:参数中不能有闹钟信号屏蔽字
    sigset_t tmp = oldset;     //为了保证不包含闹钟信号屏蔽字
    sigdelset(&tmp,SIGALRM);
    sigsuspend(&tmp);
    //pause();
    signal(SIGALRM,old);
    sigprocmask(SIG_SETMASK,&oldset,NULL);
}
int main()
{
    printf("Before:\n");
    _sleep(2);
    printf("After:\n");
    return 0;
}
