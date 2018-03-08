#include<stdio.h>
#include"seqqueue.h"
void TEST_SeqQueue()
{
	QueueType temp = 0;
	TEST_HEADER;
	SeqQueueInit(&q);
	SeqQueuePush(&q,'a');
	SeqQueuePush(&q,'b');
	SeqQueuePush(&q,'c');
	SeqQueuePush(&q,'d');
	SeqQueueTop(&q,&temp);
	printf("top expect is a ,actual is %c\n",temp);
	SeqQueuePop(&q);

	SeqQueueTop(&q,&temp);
	printf("top expect is b ,actual is %c\n",temp);
	SeqQueuePop(&q);

	SeqQueueTop(&q,&temp);
	printf("top expect is c ,actual is %c\n",temp);
	SeqQueuePop(&q);

	SeqQueueTop(&q,&temp);
	printf("top expect is d ,actual is %c\n",temp);
	SeqQueuePop(&q);
}
//////////////////test/////////////////////
int main()
{
	TEST_SeqQueue();
	return 0;
}