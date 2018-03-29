#include<stdio.h>
#include"seqqueue.h"

void SeqQueueInit(SeqQueue* q)
{
	if(q == NULL)
	{
		//非法输入
		return;
	}
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}
void SeqQueueDestroy(SeqQueue* q)
{
	if(q == NULL)
	{
		//非法输入
		return;
	}
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}
void SeqQueuePush(SeqQueue* q,QueueType value)
{
	if(q == NULL)
	{
		//非法输入
		return;
	}
	if(q->size >= MaxQueue)
	{
		return;
	}
	if(q->head == 0)
	{
		q->head = q->tail = value;
	}
	q->data [q->tail ++] = value;
	++q->size ;
	if(q->tail >= MaxQueue)
	{
		q->tail = 0;
	}
}
void SeqQueuePop(SeqQueue* q)
{
	if(q == NULL)
	{
		return;
	}
	if(q->head == 0)
	{
		//空队列
		return;
	}
	++q->head ;
	--q->size ;
	if(q->head >= MaxQueue)
	{
		q->head = 0;
	}
}
int SeqQueueTop(SeqQueue* q,QueueType* top)
{
	if(q == NULL)
	{
		return 0;
	}
	if(q->head == 0)
	{
		return 0;
	}
	*top = q->data [q->head ];
	return 1;
}
size_t SeqQueueSize(SeqQueue* q)
{
	if(q == NULL)
	{
		return (size_t)-1;
	}
	return q->size ;
}