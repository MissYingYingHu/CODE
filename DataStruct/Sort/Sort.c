#include"Sort.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TestHeader printf("\n================%s================\n",__FUNCTION__)
void Swap(int* a,int*  b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void BubbleSort(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    int bound = 0;
    int j = 0;
    for(;bound < size - 1;++bound )
    {
        for(j = 0;j < size - bound - 1;++j)
        {
            if(arr[j] > arr[j + 1])
            {
                Swap(&arr[j],&arr[j + 1]);
            }
        }
    }
}
void SelectSort(int arr[],int size )
{
    if(size <= 1)
    {
        return;
    }
    int bound = 0;
    int j = 0;
    for(bound = 0;bound < size;++bound )
    {
        for(j = bound + 1;j < size;++j)
        {
            if(arr[bound ] > arr[j])
            {
                Swap (&arr[bound ],&arr[j]);
            }
        }
    }
}
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
}
void AdjustDown(int arr[],int i,int size)
{
    int parent = i;
    int child = parent*2 + 1;
    while(child < size)
    {
        if(arr[child] < arr[child + 1] && (child + 1) < size)
        {
            child = child + 1;
        }
        if(arr[child] > arr[parent])
        {
            Swap(&arr[child],&arr[parent]);
        }
        else
        {
            break;
        }
        parent= child;
        child = parent*2 + 1;
    }
}
void HeapSort(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    //1.建堆(有子节点的节点只有一半的数据，从最后一个非叶子节点开始建堆)
    int i = (size - 1 - 1)/2;
    for(;i > 0;--i)
    {
        AdjustDown(arr,i,size);
    }
    AdjustDown(arr,0,size);
    //交换对顶元素和最小元素
    int heap_size = size;
    while(heap_size > 0)
    {
        Swap(&arr[0],&arr[heap_size - 1]);
        --heap_size;
        AdjustDown(arr,0,heap_size);
    }
}
void ShellSort(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    //当插入排序的数字个数较少或者比较有序时，排序的效率就特别高，希尔排序的内部结构就是插入排序
    int group = (size - 1)/2;
    for(;group > 0;group = group/2)
    {
        int bound = group;
        for(;bound < size;bound += group)
        {
            int value = arr[bound];
            int j = bound;  //不能写成:j = boung - group;因为会把首元素给丢掉！！！！
            for(;j > 0;j -= group)
            {
                if(arr[j - group] > value)
                {
                    arr[j] = arr[j - group];
                }
                else
                {
                    break;
                }
            }
            arr[j] = value;
        }
    }
}
void _Merge(int arr[],int* _new,int start,int mid,int end)
{
    int left = start;
    int middle = mid;
    int index = 0;
    if(end - start <= 1)
    {
        return;
    }
    while(left < mid && middle < end)
    {
        if(arr[left] < arr[middle])
        {
            _new[index++] = arr[left++];
        }
        else
        {
            _new[index++] = arr[middle++];
        }
    }
    while(left < mid)
    {
        _new[index++] = arr[left++];
    }
    while(middle < end)
    {
        _new[index++] = arr[middle++];
    }
    memcpy(arr + start,_new,sizeof(int)*(end - start));
}
void MergeSort(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    int* _new = (int*)malloc(sizeof(int)*size);
    int gap = 1;
    for(;gap < size;gap = gap*2)
    {
        int i = 0;
        for(i = 0;i < size;i += gap * 2) //注意i的变化规律。每一小组的最后一个元素要作为下一个元素的start
        {
            int start = i;
            int mid = gap + i;
            int end = gap * 2 + i;
            if(mid > size)
            {
                mid = size;
            }
            if(end > size)
            {
                end = size;
            }
            _Merge(arr,_new,start,mid,end);
        }
    }
    free(_new);
}
//递归版本的归并排序
void _MergeSortByR(int arr[],int _new[],int start,int end)
{
    if(end - start <= 1)
    {
        return;
    }
    if(start < end)
    {
        int mid = start + (end - start)/2;
        _MergeSortByR(arr,_new,start,mid);
        _MergeSortByR(arr,_new,mid,end);
        _Merge(arr,_new,start,mid,end);
    }
}
void MergeSortByRecursion(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    int* _new = (int*)malloc(sizeof(int)*size);
    _MergeSortByR(arr,_new,0,size);
    free(_new);
}
//1.exchange
int Position(int arr[],int start,int right)
{
     int end = right -1;
     int key = end; 
     while(start < end) 
     { 
         while(start < end && arr[start] <= arr[key]) 
         { 
             ++start; 
         } 
         while(start < end && arr[start] >= arr[key]) 
         { 
             --end; 
         } 
         if(start < end) 
         { 
             Swap(&arr[start],&arr[end]); 
         } 
     } 
     Swap(&arr[start],&arr[key]); 
     return start;
}
int Position2(int arr[],int start,int end)
{
    int right = end - 1;
    int left = start;
    int key = arr[right];
    while(left < right)
    {
        while(arr[left] <= key && left < right)
        {
            ++left;
        }
        if(arr[left] > key && left < right)
        {
            arr[right--] = arr[left];
        }
        while(arr[right] >= key && left < right)
        {
            --right;
        }
        if(arr[right] < key && left < right)
        {
            arr[left++] = arr[right];
        }
    }
    arr[left] = key;
    return left;
}
int Position3(int arr[],int start,int end)
{
    int prev = start - 1;
    int cur = start;
    int key = arr[end - 1];
    while(cur < end)
    {
        if(arr[cur] < key && (++prev) != cur)
        {
            Swap(&arr[prev],&arr[cur]);
        }
        ++cur;
    }
    if((++prev) != end)
    {
        Swap(&arr[prev],&arr[end - 1]);
    }
    return prev;
}
void _QuickSort(int arr[],int start,int end)
{
    if(end - start <= 1)
    {
        return;
    }
//    int mid = Position(arr,start,end);
    int mid = Position2(arr,start,end);
//    int mid = Position3(arr,start,end);
    _QuickSort(arr,0,mid);
    _QuickSort(arr,mid + 1,end);
}
void QuickSort(int arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    _QuickSort(arr,0,size);
}
void TestQuick()
{
    TestHeader;
 //   int arr[] = {123,98,737,2,78643,4278};
    int arr[] = {123,4234,53422,213242,1,23,7897,4234};
    size_t i = 0;
    printf("排序前：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    QuickSort(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n排序后：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void TestMergeByR()
{
    TestHeader;
    int arr[] = {123,4234,53422,213242,1,23,7897,4234};
    size_t i = 0;
    printf("排序前：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    MergeSortByRecursion(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n排序后：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void TestMerge()
{
    TestHeader;
    int arr[] = {123,4234,53422,213242,1,23,7897,4234};
    size_t i = 0;
    printf("排序前：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    //MergeSort(arr,sizeof(arr)/sizeof(arr[0]));
    MergeSortByRecursion(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n排序后：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void TestShell()
{
    TestHeader;
    //int arr[] = {123,4234,53422,213242,1,23,7897,4234};
    int arr[] = {9,5,2,7,3,6};
    size_t i = 0;
    printf("排序前：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    ShellSort(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n排序后：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void TestHeap()
{
    TestHeader;
    int arr[] = {123,4234,53422,213242,1,23,7897,4234};
    size_t i = 0;
    printf("排序前：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    HeapSort(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n排序后：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void TestInsert()
{
    TestHeader;
    int arr[] = {123,4234,53422,213242,1,23,7897,4234};
    size_t i = 0;
    printf("排序前：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    InsertSort(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n排序后：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void TestSelect()
{
    TestHeader;
    //int arr[] = {123,4234,53422,213242,1,23,7897,4234};
    int arr[] = {9,5,2,7};
    size_t i = 0;
    printf("排序前：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    SelectSort (arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n排序后：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void TestBubble()
{
    TestHeader;
    int arr[] = {123,4234,53422,213242,1,23,7897,4234};
    size_t i = 0;
    printf("排序前：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    BubbleSort (arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n排序后：");
    for(i = 0;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
///////////////////////Test/////////////////////////////////
int main()
{
    TestBubble ();
    TestSelect();
    TestInsert();
    TestHeap();
    TestShell();
    TestMerge();
    TestMergeByR();
    TestQuick();
    return 0;
}
