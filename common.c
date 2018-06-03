#include"common.h"

int Common(int flag)
{
    key_t key = ftok(".",0);
    if(key < 0)
    {
        perror("ftok");
        return -1;
    }
    int segid = semget(key,1,flag);
    if(segid < 0)
    {
        perror("semget");
        return -1;
    }
    return segid;
}

int CreateSeg()
{
    return Common(IPC_CREAT | IPC_EXCL | 0666);
}

int OpenSeg()
{
    return Common(IPC_CREAT);
}

void Destroy(int segid)
{
    int ret = semctl(segid,0,IPC_RMID);
    if(ret == -1)
    {
        return;
    }
}

void SetSeg(int segid,int index,int value)
{
    union semun s;
    s.val = value;
    int ret = semctl(segid,index,SETVAL,s);
    if(ret < 0)
    {
        perror("semctl set");
        return;
    }
}

void GetSeg(int segid,int index,int* value)
{
    int ret = semctl(segid,index,GETVAL);
    if(ret < 0)
    {
        perror("semctl get");
        return;
    }
    *value = ret;
}

void P(int segid,int index)
{
    struct sembuf b;
    b.sem_num = index;
    b.sem_op = -1;
    b.sem_flg = 0;
    int ret = semop(segid,&b,1);
    if(ret < 0)
    {
        perror("semop P");
        return;
    }
}

void V(int segid,int index)
{
    struct sembuf b;
    b.sem_num = index;
    b.sem_op = 1;
    b.sem_flg = 0;
    int ret = semop(segid,&b,1);
    if(ret < 0)
    {
        perror("semop V");
        return;
    }
}
