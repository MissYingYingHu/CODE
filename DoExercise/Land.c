//题目描述:求岛屿的个数(即为1的块有多少个)
//给定一个二维数组,二维数组中只有1和0,求由1组成的块有多少个
#include <stdio.h>
#define N 5


void Infect(int arr[N][N],int row,int col)
{
    if(row < 0 || row >= N || col < 0 || col >= N || arr[row][col] != 1)
    {
        return;
    }
    //将1的地方改为2,表示已经遍历过了.
    //如果遇到该位置是0,说明这个方向的1已经遍历完,要进行下一个方向的遍历.
    arr[row][col] = 2;
    Infect(arr,row + 1,col);
    Infect(arr,row - 1,col);
    Infect(arr,row,col + 1);
    Infect(arr,row,col - 1);
}
int land(int arr[N][N])
{
    int i = 0;
    int j = 0;
    int count = 0;
    for(i = 0;i < N;++i)
    {
        for(j = 0;j < N;j++)
        {
            if(arr[i][j] == 1)
            {
                ++count;   //count即为岛屿的个数
                Infect(arr,i,j); //将该位置的周围进行感染,通过递归来进行遍历该点周围的其他点
            }
        }
    }
    return count;
}
int main()
{
    int arr[N][N] = {
        {1,1,1,0,0},
        {1,1,1,1,0},
        {0,0,0,0,1},
        {1,0,1,1,0},
        {1,1,1,0,0}
    };
    printf("land is %d\n",land(arr));
    return 0;
}
