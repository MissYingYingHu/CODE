#include"LinkQueue.h"
#include<stdio.h>
void TEST_LinkQueue()
{
	QueueNodeType tmp = 0;
	TEST_HEADER;
	LinkQueueInit(&q);
	LinkQueuePush(&q,'a');
	LinkQueuePush(&q,'b');
	LinkQueuePush(&q,'c');
	LinkQueuePush(&q,'d');

	LinkQueueTop(&q,&tmp);
	printf("expect is a,actual is %c\n",tmp);
	LinkQueuePop(&q);

	LinkQueueTop(&q,&tmp);
	printf("expect is b,actual is %c\n",tmp);
	LinkQueuePop(&q);

	LinkQueueTop(&q,&tmp);
	printf("expect is c,actual is %c\n",tmp);
	LinkQueuePop(&q);

	LinkQueueTop(&q,&tmp);
	printf("expect is d,actual is %c\n",tmp);
	LinkQueuePop(&q);
}
int main()
{
	TEST_LinkQueue();
	return 0;
}