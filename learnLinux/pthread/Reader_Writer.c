#include <stdio.h>
#include<unistd.h>
#include<pthread.h>

pthread_rwlock_t rwlock;
int count = 0;

void* Read(void* arg)
{
    (void)arg;
    while(1)
    {
        pthread_rwlock_rdlock(&rwlock);
        printf("read\n");
        printf("read:%d\n",count);
        printf("read done\n");
        pthread_rwlock_unlock(&rwlock);
        usleep(234345);
    }
    return NULL;
}
void* Write(void* arg)
{
    (void)arg;
    while(1)
    {
        pthread_rwlock_wrlock(&rwlock);
        printf("writer\n");
        ++count;
        printf("writer:%d\n",count);
        printf("writer done\n");
        pthread_rwlock_unlock(&rwlock);
        usleep(123234);
    }
    return NULL;
}
int main()
{
    pthread_rwlock_init(&rwlock,NULL);
    pthread_t reader[4],writer;
    int i = 0;
    for(i = 0;i < 4;++i)
    {
        pthread_create(&reader[i],NULL,Read,NULL);
    }
    pthread_create(&writer,NULL,Write,NULL);
    for(i = 0;i < 4;++i)
    {
        pthread_join(reader[i],NULL);
    }
    pthread_join(writer,NULL);
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
