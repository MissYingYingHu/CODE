#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

typedef struct Link 
{
    struct Link* next;
    int val;
}Link;

Link head;

void Link_Init(Link* head)
{
    head->val = 0;
    head->next = NULL;
}

Link* CreateNode(int val)
{
    Link* newnode = (Link*)malloc(sizeof(Link));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

void Link_Push(Link* head,int val)
{
    if(head == NULL)
    {
        return;
    }
    Link* newnode = CreateNode(val);
    newnode->next = head->next ;
    head->next = newnode;
}

void Destory(Link* ptr)
{
    free(ptr);
}

void Link_Pop(Link* head,int* value)
{
    if(head == NULL)
    {
        return;
    }
    if(head->next == NULL)
    {
        return;
    }
    Link* to_deleted = head->next;
    head->next = to_deleted->next;
    *value = to_deleted->val;
    Destory(to_deleted);
}

pthread_mutex_t mutex;
pthread_cond_t cond;
int count = 0;

void* Product(void* arg)
{
    (void)arg;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        Link_Push(&head,++count);
        printf("product:%d\n",count);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}

void* Consume(void* arg)
{
    (void)arg;
    int value = -1;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        while(head.next == NULL)
        {
            pthread_cond_wait(&cond,&mutex);
        }
        Link_Pop(&head,&value);
        printf("consumer:%d\n",value);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return NULL;
}
int main()
{
    //1.构建一个公共场所
    //2.两种线程
    //3.三种关系
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    pthread_t productor[4],consumer[4];
    int i = 0;
    for(i = 0;i < 4;++i)
    {
        int* p = (int*)malloc(sizeof(int));
        pthread_create(&productor[i],NULL,Product,(void*)p);
    }
    for(i = 0;i < 4;++i)
    {
        int* p = (int*)malloc(sizeof(int));
        pthread_create(&consumer[i],NULL,Consume,(void*)p);
    }
    for(i = 0;i < 4;++i)
    {
        pthread_join(productor[i],NULL);
    }
    for(i = 0;i < 4;++i)
    {
        pthread_join(consumer[i],NULL);
    }
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&mutex);
    return 0;
}
