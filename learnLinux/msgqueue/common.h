#pragma once
#include<stddef.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

typedef struct MsgBuf
{
    long mtype;
    char mtext[128];
}msgbuf;
int CreateMsgQueue();

int OpenMsgQueue();

int DestroyMsgQueue(int msgid);

int SendMsg(int msgid,char* msg,size_t size,int type);

int ReceiveMsg(int msgid,char* buf,size_t size,int flag);
