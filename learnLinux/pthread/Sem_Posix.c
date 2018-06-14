#include <stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#define SIZE 1000

typedef struct Queue
{
    int data[SIZE];
    int size;
    int head;
    int tail;
}Queue;

Queue q;

void Queue_Init(Queue* q)
{
    q->head = q->tail = q->size = 0;
}

void Push(Queue* q,int val)
{
    if(q->size >= SIZE)
    {
        return;
    }
    if(q->tail > SIZE)
    {
        q->tail = 0;
    }
    q->data[q->tail] = val;
    ++q->tail;
    ++q->size;
}

void Pop(Queue* q,int* value)
{
    if(q->size == 0)
    {
        return;
    }
    *value = q->data[q->head];
    ++q->head;
    if(q->head >= SIZE)
    {
        q->head = SIZE;
    }
    --q->size;
}

int count = 0;
sem_t g_data;
sem_t g_black;

void* product(void* arg)
{
    (void)arg;
    while(1)
    {
        sem_wait(&g_black);
        Push(&q,++count);
        sem_post(&g_data);
        printf("product:%d\n",count);
        usleep(456345);
    }
}

void* consume(void* arg)
{
    (void)arg;
    while(1)
    {
        int value = -1;
        sem_wait(&g_data);
        Pop(&q,&value);
        printf("consume:%d\n",value);
        sem_post(&g_black);
        usleep(123234);
    }
}
int main()
{
    //1.一个交易场所
    //2.两种角色
    //3.三种关系
    Queue_Init(&q);
    sem_init(&g_data,0,0);
    sem_init(&g_black,0,SIZE);
    pthread_t productor,consumer;    
    pthread_create(&productor,NULL,product,NULL);
    pthread_create(&consumer,NULL,consume,NULL);
    pthread_join(productor,NULL);
    pthread_join(consumer,NULL);
    sem_destroy(&g_data);
    sem_destroy(&g_black);
    return 0;
}

