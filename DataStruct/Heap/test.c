#include"heap.h"

int Less(heap_type a,heap_type b)
{
    return a < b;
}

int Greater(heap_type a,heap_type b)
{
    return a > b;
}

void PrintHeap(heap* p,const char* msg)
{
    if(p == NULL)
    {
        return;
    }
    printf("%s:",msg);
    int i = 0;
    for(;i < p->size;++i)
    {
        printf("[%d:]%d ",i,p->data[i]);
    }
    printf("\n");
}
////////////////////////////排序////////////////////////////////////////////
void Swap(heap_type* a,heap_type* b)
{
    heap_type tmp = *a;
    *a = *b;
    *b = tmp;
}
void heap_sort(heap_type arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    int i = 0;
    for(i = 0;i < size;++i)
    {
        AdjustUp(arr,i + 1,i,Less);  //降序
        //AdjustUp(arr,i + 1,i,Greater); //升序
    }
    int Size = size;
    while(Size > 0)
    {
        Swap(&arr[0],&arr[Size - 1]);
        --Size;
        AdjustDown(arr,Size,0,Less); //降序
        //AdjustDown(arr,Size,0,Greater); //升序
    }
}

void heap_sort2(heap_type arr[],int size)
{
    if(size <= 1)
    {
        return;
    }
    int i = (size - 1 - 1)/2;
    for(;i > 0;--i)
    {
        AdjustDown(arr,size,i,Less);  //降序
        //AdjustDown(arr,size,i,Greater);  //升序
    }
    //AdjustDown(arr,size,0,Greater);
    AdjustDown(arr,size,0,Less);
    int Size = size;
    while(Size > 0)
    {
        Swap(&arr[0],&arr[Size - 1]);
        --Size;
        AdjustDown(arr,Size,0,Less);  //降序
        //AdjustDown(arr,Size,0,Greater); //升序
    }
}
void TestSort()
{
    Header;
    heap_type arr[] = {9,5,2,7,3};
    heap_sort(arr,sizeof(arr)/sizeof(arr[0]));
    //heap_sort2(arr,sizeof(arr)/sizeof(arr[0]));
    size_t i = 0;
    for(;i < sizeof(arr)/sizeof(arr[0]);++i)
    {
        printf("%d ",arr[i]);
    }
}
///////////////////////////////////////////////////////////////////////////

void TestInsert()
{
    Header;
    heap p;
    InitHeap(&p,Less);
    InsertHeap(&p,9);
    InsertHeap(&p,5);
    InsertHeap(&p,2);
    InsertHeap(&p,7);
    PrintHeap(&p,"插入4个元素");
}

void TestEraseTop()
{
    Header;
    heap p;
    InitHeap(&p,Less);
    InsertHeap(&p,9);
    InsertHeap(&p,5);
    InsertHeap(&p,2);
    InsertHeap(&p,7);
    InsertHeap(&p,3);
    PrintHeap(&p,"插入5个元素");
    EraseHeapTop(&p);
    PrintHeap(&p,"删除了堆顶元素");
}

void TestEmpty()
{
    Header;
    heap p;
    InitHeap(&p,Less);
    int ret = EmptyHeap(&p);
    printf("ret expect is 1,actual is %d\n",ret);
    InsertHeap(&p,9);
    InsertHeap(&p,5);
    InsertHeap(&p,2);
    InsertHeap(&p,7);
    InsertHeap(&p,3);
    PrintHeap(&p,"插入5个元素");
    ret = EmptyHeap(&p);
    printf("ret expect is 0,actual is %d\n",ret);
}

void TestSize()
{
    Header;
    heap p;
    InitHeap(&p,Less);
    InsertHeap(&p,9);
    InsertHeap(&p,5);
    InsertHeap(&p,2);
    InsertHeap(&p,7);
    InsertHeap(&p,3);
    PrintHeap(&p,"插入5个元素");
    int ret = SizeHeap(&p);
    printf("ret expect is 5,actual is %d\n",ret);
}
int main()
{
    TestInsert();
    TestEraseTop();
    TestEmpty();
    TestSize();
    TestSort();
    return 0;
}
