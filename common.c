#include"common.h"
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

//创建消息队列,如果存在,就失败
//如果不存在,就创建
int common(int flag)
{
    //如果多个进程调用ftok使用相同的参数,那么获取的key值就是相同的
    key_t key = ftok(".",0);
    if(key < 0)
    {
        perror("ftok");
        return 1;
    }
    int msgid = msgget(key,flag);
    if(msgid < 0)
    {
        perror("msgget");
        return -1;
    }
    return msgid;
}
int CreateMsgQueue()
{
    return common(IPC_CREAT | IPC_EXCL | 0666);
}

int OpenMsgQueue()
{
    return common(IPC_CREAT | 0666);
}

int DestroyMsgQueue(int msgid)
{
    int ret = msgctl(msgid,IPC_RMID,NULL);
    if(ret < 0)
    {
        perror("msgctl");
        return 1;
    }
    return 0;
}

//把一条消息添加到消息队列中
int SendMsg(int msgid,char* msg,size_t size,int type)
{
      struct MsgBuf buf;
      buf.mtype = type;
      if(sizeof(buf.mtext) > size)
      {
          return -1;
      }
      strcpy(buf.mtext,msg); 
      int ret = msgsnd(msgid,&buf,sizeof(buf.mtext),0);
      if(ret < 0)
      {
          perror("msgsnd");
          return -1;
      }
      return 0;
}

int ReceiveMsg(int msgid,char* buffer,size_t size,int type)
{
    struct MsgBuf buf;
    int ret = msgrcv(msgid,&buf,sizeof(buf.mtext),type,0);
    if(ret < 0)
    {
        perror("msgrev");
        return -1;
    }
    if(sizeof(buf.mtext) > size)
    {
        return -1;
    }
    strcpy(buffer,buf.mtext);
    return 0;
}
