#include"common.h"

int common(int flag)
{
    int key = ftok(".",0);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    int shmid = shmget(key,1,flag);
    if(shmid < 0)
    {
        perror("shmget");
        return -1;
    }
    return shmid;
}

int CreateShm()
{
    return common(IPC_CREAT | IPC_EXCL | 0666);
}

int OpenShm()
{
    return common(IPC_CREAT);
}

void DestroyShm(int shmid)
{
    int ret = shmctl(shmid,IPC_RMID,NULL);
    if(ret < 0)
    {
        perror("shmctl");
        return;
    }
    return;
}

