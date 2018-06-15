#include"common.h"

int main()
{
    int shmid = CreateShm();
    char* addr = (char*)shmat(shmid,NULL,0);
    while(1)
    {
        printf("%s\n",addr);
        sleep(1);
    }
    shmdt(addr);
    DestroyShm(shmid);
    return 0;
}
