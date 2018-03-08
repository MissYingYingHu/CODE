#include<stdio.h>
#include"LinkQueue.h"
#include<stdio.h>
#include<stdlib.h>
void LinkQueueInit(LinkQueue* q)
{
	if(q == NULL)
	{
		//非法输入
		return;
	}
	q->head = NULL;
	q->tail = NULL;
}
LinkQueueNode* CreateLinkNode(QueueNodeType value)
{
	LinkQueueNode* new_node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}
void LinkQueuePush(LinkQueue* q,QueueNodeType value)
{
	LinkQueueNode* new_node = NULL;
	if(q == NULL)
	{
		return;
	}
	new_node = CreateLinkNode(value);
	if(q->head == NULL)
	{
		q->head = q->tail = new_node;
		return;
	}
	q->tail->next = new_node;
	q->tail = q->tail ->next;
}
void DestroyNode(LinkQueueNode* ptr)
{
	free(ptr);
}
void LinkQueuePop(LinkQueue* q)
{
	LinkQueueNode* to_deleted = NULL;
	if(q == NULL)
	{
		//非法输入
		return;
	}
	if(q->head == NULL)
	{
		//空队列
		return;
	}
	to_deleted = q->head ;
	if(q->head == q->tail )
	{
		DestroyNode(to_deleted);
		q->head = q->tail = NULL;
		return;
	}
	q->head = to_deleted->next;
	DestroyNode(to_deleted);
}
int LinkQueueTop(LinkQueue* q,QueueNodeType* top)
{
	if(q == NULL || top == NULL)
	{
		return 0;
	}
	if(q->head == NULL)
	{
		return 0;
	}
	*top = q->head->data ;
	return 1;
}