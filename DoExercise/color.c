//带背景色和字体颜色的8*8乘法表
#include <stdio.h>
int main()
{
    int i = 1;
    int j = 1;
    for(i = 1;i <= 8;++i)
    {
        printf("\033[3%dm",i-1);
        printf("\033[4%dm",(i+1)%8);
        for(j = 1;j <= i;++j)
        {
            printf("%d*%d=%-3d",i,j,i*j);
        }
        printf("\n");
    }
    printf("\033[0m");
    return 0;
}
