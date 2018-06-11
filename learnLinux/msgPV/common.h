#pragma once
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO
                                (Linux-specific) */
};

void SetSeg(int segid,int index,int value);
//创建信号量集
int CreateSeg();

//打开信号量集
int OpenSeg();

//销毁信号量集
void DestroySeg(int segid);

//设置信号量
void SetSeg(int segid,int index,int value);

//获取信号量
void GetSeg(int segid,int index,int* value);

//P操作
void P(int segid,int index);

//V操作
void V(int segid,int index);

