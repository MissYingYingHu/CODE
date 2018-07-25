#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
//选择排序
void SelectSort(int arr[],int size)
{
    int i = 0;
    int j = 0;
    for(i = 0;i < size;++i)
    {
        for(j = i + 1;j < size;++j)
        {
            if(arr[i] < arr[j])
            {
                swap(&arr[i],&arr[j]);
            }
        }
    }
}
//插入排序
void InsertSort(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    int bound = 0;
    for(bound = 1;bound < size;++bound)
    {
        int value = arr[bound];
        int j = bound;
        for(;j > 0;--j)
        {
            if(arr[j - 1] > value)   //注意!!!!:这里要和需要插入的值进行比较
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
}

//下沉
void AdjustDown(int arr[],int size,int index)
{
    int parent = index;
    int child = index * 2 + 1;
    while(child < size)
    {
        if(arr[child] < arr[child + 1] && (child + 1) < size)
        {
            child = child + 1;
        }
        if(arr[parent] < arr[child])
        {
            swap(&arr[parent],&arr[child]);
        }
        else
        {
            break;
        }
        parent = child;
        child = parent * 2 + 1;
    }
}
//堆排序
void HeapSort(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    int i = (size - 1 - 1)/2;
    for(;i > 0;--i)
    {
        AdjustDown(arr,size,i - 1);
    }
    int len = size;
    while(len > 0)
    {
        swap(&arr[0],&arr[len - 1]);
        --len;
        AdjustDown(arr,len,0);
    }
}

void Merge(int arr[],int left,int mid,int right,int tmp[])
{
    if(right - left <= 1)
    {
        return;
    }
    int start = left;
    int end = mid;
    int index = 0;
    while(start < mid && end < right)
    {
        if(arr[start] < arr[end])
        {
            tmp[index++] = arr[start++];
        }
        else
        {
            tmp[index++] = arr[end++];
        }
    }
    while(start < mid)
    {
        tmp[index++] = arr[start++];
    }
    while(end < right)
    {
        tmp[index++] = arr[end++];
    }
    memcpy(arr + left,tmp,sizeof(int)*(right - left));
}
void _MergeSort(int arr[],int left,int right,int tmp[])
{
    if(right - left <= 1)
    {
        return;
    }
    int mid = left + (right - left)/2;
    _MergeSort(arr,left,mid,tmp);
    _MergeSort(arr,mid,right,tmp);
    Merge(arr,left,mid,right,tmp);
}
//归并排序(递归)
void MergeSort(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    int* tmp = (int*)malloc(sizeof(arr[0])*size);
    _MergeSort(arr,0,size,tmp);
    free(tmp);
}

//非递归
void MergeSortByLoop(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    int gap = 1;
    int* tmp = (int*)malloc(sizeof(arr[0])*size);
    for(;gap < size;gap *= 2)
    {
        int i = 0;
        for(; i < size;i += 2*gap)
        {
            int start = i;
            int mid = gap + i;
            int end = 2*gap + i;
            if(mid > size)
            {
                mid = size;
            }
            if(end > size)
            {
                end = size;
            }
            Merge(arr,start,mid,end,tmp);
        }
    }
}

//交换法
int Partition(int arr[],int left,int right)
{
    int end = right - 1;
    int key = end;
    while(left < end)
    {
        //找到左边第一个大于基准值的元素
        while(arr[left] <= arr[key] && left < end)
        {
            ++left;
        }
        //找到右边第一个小于基准值的元素
        while(arr[end] >= arr[key] && left < end)
        {
            --end;
        }
        if(left < end)
        {
            swap(&arr[left],&arr[end]);
        }
    }
    swap(&arr[left],&arr[key]);
    return left;
}
//挖坑法
int Partition2(int arr[],int left,int right)
{
    int start = left;
    int end = right - 1;
    int key = arr[end];
    while(start < end)
    {
        //找到左边大于基准值的元素
        while(start < end && arr[start] <= key)
        {
            ++start;
        }
        //将大于基准值的元素填入基准值的位置
        if(arr[start] > key && start < end)
        {
            arr[end--] = arr[start];
        }
        //找到右边小于基准值的元素
        while(start < end && arr[end] >= key)
        {
            --end;
        }
        //将找到的小于基准值的元素填入合适的位置.
        if(arr[end] < key && start < end)
        {
            arr[start++] = arr[end];
        }
    }
    arr[end] = key;
    return start;
}
void _QuickSort(int arr[],int start,int end)
{
    if(end - start < 1)
    {
        return;
    }
    //int mid = Partition(arr,0,end);
    int mid = Partition2(arr,0,end);
    _QuickSort(arr,0,mid);
    _QuickSort(arr,mid + 1,end);
}

//快排
void QuickSort(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    _QuickSort(arr,0,size);
}
int main()
{

    //int arr[] = {9,5,2,7,3};
    int arr[] = {21,25,49,25,16,8,31,41};
    size_t i = 0;
    //SelectSort(arr,sizeof(arr)/sizeof(arr[0]));
    //InsertSort(arr,sizeof(arr)/sizeof(arr[0]));
    //HeapSort(arr,sizeof(arr)/sizeof(arr[0]));
    //MergeSort(arr,sizeof(arr)/sizeof(arr[0]));
    //MergeSortByLoop(arr,sizeof(arr)/sizeof(arr[0]));
    QuickSort(arr,sizeof(arr)/sizeof(arr[0]));
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d,",arr[i]);
    }
    return 0;
}
