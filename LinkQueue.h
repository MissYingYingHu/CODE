#pragma once

#define TEST_HEADER printf("\n===============%s============\n",__FUNCTION__)

typedef char QueueNodeType;

typedef struct LinkQueueNode
{
	struct LinkQueueNode* next;
	QueueNodeType data;
}LinkQueueNode;

typedef struct LinkQueue
{
	LinkQueueNode* head;
	LinkQueueNode* tail;
}LinkQueue;

LinkQueue q;

void LinkQueueInit(LinkQueue* q);

void LinkQueuePush(LinkQueue* q,QueueNodeType value);

void LinkQueuePop(LinkQueue* q);

int LinkQueueTop(LinkQueue* q,QueueNodeType* top);