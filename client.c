#include"common.h"

int main()
{
    int msgid = OpenMsgQueue();
    char buf[1024] = {0};
    while(1)
    {
        printf("client enter:");
        fflush(stdout);
        ssize_t size = read(0,buf,sizeof(buf) - 1);
        if(size > 0)
        {
            buf[size] = '\0';
            SendMsg(msgid,buf,sizeof(buf),1);
        }
        else if(size == 0)
        {
            break;
        }
        else
        {
            perror("client read...");
            return -1;
        }
        ReceiveMsg(msgid,buf,sizeof(buf),0);
        printf("server answer:%s\n",buf);
    }
    return 0;
}
