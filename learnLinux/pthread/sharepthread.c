#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* Pthread1(void* arg)
{
    int* p = (int*)arg;
    while(1)
    {
        ++(*p);
        sleep(1);
    }
}
void* Pthread2(void* arg)
{
    int* p = (int*)arg;
    while(1)
    {
        printf("*p = %d\n",*p);
        sleep(1);
    }
}
int main()
{
    pthread_t p1,p2;
    //int *ptr = (int*)malloc(sizeof(int));
    //*ptr = 10;
    int number = 1;
    int *ptr = &number;
    pthread_create(&p1,NULL,Pthread1,ptr);
    pthread_create(&p2,NULL,Pthread2,ptr);
    pthread_join(p1,NULL);
    pthread_join(p2,NULL);

    return 0;
}
