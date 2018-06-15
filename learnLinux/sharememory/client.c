#include"common.h"
#include<stdio.h>

int main()
{
    int shmid = OpenShm();
    char* addr = (char*)shmat(shmid,NULL,0);
    int i = 0;
    while(1)
    {
        addr[i] = 'A';
        sleep(1);
        i++;
    }
    shmdt(addr);
    return 0;
}
