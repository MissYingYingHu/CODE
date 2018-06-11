#include<stdio.h>
//找到数组中任意一个重复出现的数字
//题：在一个长度为n的数组中，所有的数字都在0~n-1的范围内.数组中某些数字是重复的，但不知道有几个数字重复，
//也不知道重复了几次，找出数组中任意一个重复的数字
//方法1：把数组先排序，然后遍历
int FindSame(int arr[],int size)
{
    if(size <= 1)
    {
        return 0;
    }
    int bound = 0;
    for(bound = 1;bound < size;++bound)
    {
        if(arr[bound] < 0 || arr[bound] > size)
        {
            return 0;
        }
        int value = arr[bound];
        int j = bound;
        for(;j > 0;--j)
        {
            if(arr[j - 1] > value)
            {
                arr[j] = arr[j - 1];
            }
            else
            {
                break;
            }
        }
        arr[j] = value;
    }
    for(bound = 0;(bound + 1) < size;++bound)
    {
        if(arr[bound] == arr[bound + 1])
        {
            return arr[bound];
        }
    }
    return 0;
}
//第二种方法
void Swap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
int FindSame2(int arr[],int size)
{
    int j = 0;
    for(j = 0; j < size;++j)
    {
        if(arr[j] > size || arr[j] < 0)
        {
            printf("超出了边界\n");
            return 0;
        }
    }
    int bound = 0;
    for(;bound < size;++bound)
    {
        while(arr[bound] != bound)
        {
            if(arr[bound] == arr[arr[bound]])
            {
                return arr[bound];
            }
            else
            {
                Swap(&arr[bound],&arr[arr[bound]]);
            }
        }
    }
    return 0;
}
int main()
{
//    int arr[] = {2,5,6,0,1,2,6};
    int arr[] = {2,3,1,1};
    int ret =  FindSame(arr,sizeof(arr)/sizeof(arr[0]));
    int ret2 =  FindSame2(arr,sizeof(arr)/sizeof(arr[0]));
    printf("ret expect is 2,actual is %d\n",ret);
    printf("ret expect is 2,actual is %d\n",ret2);

    return 0;
}
