#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int Total_Ticket = 100;
pthread_mutex_t mutex;
void* Entry(void* arg)
{
    int64_t id = (int64_t)arg;
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(Total_Ticket > 0)
        {
            usleep(1000);
            printf("now ticket is %d,%lu is buying ticket\n",Total_Ticket,id);
            --Total_Ticket;
            pthread_mutex_unlock(&mutex);
        }
        else
        {
            pthread_mutex_unlock(&mutex);
            break;
        }
    }
    return NULL;
}
int main()
{
    pthread_t t[4];
    int64_t i = 0;
    pthread_mutex_init(&mutex,NULL);
    for(i = 0;i < 4;++i)
    {
        pthread_create(&t[i],NULL,Entry,(void*)i);
    }
    for(i = 0;i < 4;++i)
    {
        pthread_join(t[i],NULL);
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}
