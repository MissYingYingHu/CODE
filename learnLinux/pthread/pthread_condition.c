#include <stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t mutex;
pthread_cond_t cond;
void* Pass(void* arg)
{
    (void)arg;
    while(1)
    {
        pthread_cond_wait(&cond,&mutex);
        printf("传球\n");
        usleep(123565);
    }
}
void* Shoot(void* arg)
{
    (void)arg;
    while(1)
    {
        printf("投球\n");
        usleep(789123);
        pthread_cond_signal(&cond);
    }
}
int main()
{
    pthread_cond_init(&cond,NULL);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,Pass,NULL);
    pthread_create(&t2,NULL,Shoot,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
