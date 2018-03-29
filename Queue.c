#include"Queue.h"
#include<stdio.h>

void InitQueue(Queue* q)
{
	if(q == NULL)
	{
		return;
	}
	InitStack(&q->entry);
	InitStack(&q->exit);
}
void PushQueue(Queue* q,QueueType value)
{
	int ret = 0;
	QueueType top;
	if(q == NULL)
	{
		return;
	}
	while(TopStack(&q->exit,&top))
	{
		PushStack(&q->entry ,top);
		PopStack(&q->exit );
	}
	PushStack(&q->entry ,value);
}
void PopQueue(Queue* q)
{
	QueueType top;
	if(q == NULL)
	{
		return;
	}
	if(q->entry .size == 0 && q->exit .size == 0)
	{
		return;
	}
	while(TopStack(&q->entry ,&top))
	{
		PushStack(&q->exit ,top);
		PopStack(&q->entry );
	}
	PopStack(&q->exit);
}
int TopQueue(Queue* q,QueueType* top)
{
	QueueType value;
	if(q == NULL)
	{
		return 0;
	}
	while(TopStack(&q->entry ,&value))
	{
		PushStack(&q->exit ,value);
		PopStack(&q->entry);
	}
	return TopStack(&q->exit ,top);
}