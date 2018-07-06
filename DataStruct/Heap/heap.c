#include"heap.h"

void InitHeap(heap* h,Compare compare)
{
    if(h == NULL)
    {
        return;
    }
    h->size = 0;
    h->cmp = compare; 
}

void swap(heap_type* a,heap_type* b)
{
    heap_type tmp = *a;
    *a = *b;
    *b = tmp;
}

//上浮
void AdjustUp(heap_type data[],int size,int index,Compare cmp)
{
    if(index >= size)
    {
        return;
    }
    int parent = (index - 1)/2;
    int child = index;
    //若子节点为0,就说明此时已经是根节点了
    while(child > 0)
    {
        //如果子节点小于父节点,就与父节点交换,必须保证父节点是小的节点.
        if(cmp(data[child],data[parent]))
        {
            swap(&data[child],&data[parent]);
        }
        else
        {
            break;
        }
        child = parent;
        parent = (child - 1)/2;
    }
}

void InsertHeap(heap* h,heap_type value)
{
    if(h == NULL)
    {
        return;
    }
    if(h->size >= MAX_SIZE)
    {
        //堆满
        return;
    }
    h->data[h->size++] = value;
    AdjustUp(h->data,h->size,h->size - 1,h->cmp);
}

//下沉
void AdjustDown(heap_type data[],int size,int index,Compare cmp)
{
    if(index >= size)
    {
        return;
    }
    int parent = index;
    int child = parent * 2 + 1;  //左子树
    while(child < size)
    {
        if(cmp(data[child + 1],data[child]) && (child + 1) < size)
        {
            //如果左子树大于右子树,那么就让child指向右子树.child是指向较小的节点
            child = child + 1;
        }
        if(cmp(data[child] ,data[parent]))
        {
            //如果父节点大于子节点,就让交换
            swap(&data[parent],&data[child]);
        }
        else
        {
            break;
        }
        parent = child;
        child = parent * 2 + 1;
    }
}

//删除堆顶元素的步骤:先与最后一个元素交换再将最后一个元素删除.然后再将堆调整为符合条件的堆.
void EraseHeapTop(heap* h)
{
    if(h == NULL || h->size == 0)
    {
        return;
    }
    swap(&h->data[0],&h->data[h->size - 1]);
    --h->size;
    AdjustDown(h->data,h->size,0,h->cmp);
}

int EmptyHeap(heap* h)
{
    if(h == NULL)
    {
        return 0;
    }
    return h->size > 0 ? 0 : 1;
}

int SizeHeap(heap* h)
{
    if(h == NULL)
    {
        return 0;
    }
    return h->size;
}

void DestoryHeap(heap* h)
{
    if(h == NULL)
    {
        return;
    }
    h->size = 0;
}

