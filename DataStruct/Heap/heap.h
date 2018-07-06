#pragma once
#include <stdio.h>

typedef int heap_type;
typedef int(*Compare)(heap_type a,heap_type b);

#define MAX_SIZE 1000
#define Header printf("\n=======================%s==================\n",__FUNCTION__)

typedef struct heap
{
    heap_type data[MAX_SIZE];
    int size; //堆中元素的个数
    Compare cmp;
}heap;

//初始化堆
void InitHeap(heap* h,Compare cmp);

//插入元素
void InsertHeap(heap* h,heap_type value);

//删除元素
void EraseHeapTop(heap* h);

//判断堆是否为空
int EmptyHeap(heap* h);

//求堆的大小
int SizeHeap(heap* h);

//销毁堆
void DestoryHeap(heap* p);


//堆排序
void heap_sort(heap_type arr[],int size);
void AdjustDown(heap_type arr[],int size,int index,Compare cmp);
void AdjustUp(heap_type arr[],int size,int index,Compare cmp);
