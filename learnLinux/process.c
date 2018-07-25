//练习：打印彩色的进度条
#include <stdio.h>
//Linux中调用操作系统的头文件
#include<unistd.h>
int main()
{
    char buf[1024] = {0};
    const char* cycle = "-/|\\";
    int i = 0;
    for(;i < 100;++i)
    {
        buf[i] = '#';
        if(i>0 && i<30)
        {
            printf("[%d%%][%c][\e[1;47m%s\e[0m]\r",i,(cycle[i%4]),buf);  //输出%
        }
        else if(i>=30 && i<70)
        {
            printf("[%d%%][%c][\e[1;42m%s\e[0m]\r",i,(cycle[i%4]),buf);  //输出%
        }
        else 
        {
            printf("[%d%%][%c][\e[1;41m%s\e[0m]\r",i,(cycle[i%4]),buf);  //输出%
        }
        fflush(stdout);
        usleep(100 * 1000);
    }
    return 0;
}

