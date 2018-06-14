#include <stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<signal.h>

pthread_mutex_t mutex;
void Func()
{
    pthread_mutex_lock(&mutex);
    printf("lock\n");
    sleep(2);
    printf("unlock\n");
    pthread_mutex_unlock(&mutex);
}
void* Pthread(void* arg)
{
    (void)arg;
    while(1)
    {
        Func();
    }
    return NULL;
}
void Handler(int sig)
{
    (void)sig;
    Func();
}
int main()
{
    signal(SIGINT,Handler);
    pthread_mutex_init(&mutex,NULL);
    pthread_t t1;
    pthread_create(&t1,NULL,Pthread,NULL);
    pthread_join(t1,NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}
