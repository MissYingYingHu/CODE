#include <stdio.h>

void Print(int arr[4][4])
{
    int i = 0;
    int j = 0;
    for(i = 0;i < 4;++i)
    {
        for(j = 0;j < 4;++j)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void Rotate(int arr[4][4],int a,int b,int c,int d)
{
    int i = 0;
    for(i = 0;i < d - b;++i)
    {
        int value = arr[a][b +i];
        arr[a][b+i] = arr[c - i][b];
        arr[c - i][b] = arr[c][d - i];
        arr[c][d - i] = arr[a + i][d];
        arr[a + i][d] = value;
    }
}
void RotateArr(int arr[4][4])
{
    int a = 0;
    int b = 0;
    int c = 3;
    int d = 3;
    while(b < d)
    {
        Rotate(arr,a++,b++,c--,d--);
    }
}
int main()
{
    int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    Print(arr);
    //Rotate(arr,0,0,3,3);
    RotateArr(arr);
    Print(arr);
    return 0;
}
