#include"common.h"
#include<stdio.h>

int main()
{
    int msgid = CreateMsgQueue();
    char buf[1024] = {0};
    while(1)
    {
        printf("client sys:");
        ReceiveMsg(msgid,buf,sizeof(buf),0);
        printf("%s\n",buf);
        printf("enter:");
        fflush(stdout);
        ssize_t size = read(0,buf,sizeof(buf) - 1);
        if(size > 0)
        {
            buf[size] = '\0';
            SendMsg(msgid,buf,sizeof(buf),1);
            printf("server sys:wait read...\n");
        }
        else if(size == 0)
        {
            break;
        }
        else
        {
            perror("server read..");
            return -1;
        }
    }
    DestroyMsgQueue(msgid);
    return 0;
}
