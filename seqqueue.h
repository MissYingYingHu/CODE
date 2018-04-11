#pragma once

#define TEST_HEADER printf("\n==================%s================\n",__FUNCTION__)
 
//typedef char QueueType;
struct TreeNode;
typedef struct TreeNode* QueueType;

#define MaxQueue 1000

typedef struct SeqQueue
{
	QueueType data[MaxQueue];
	int head;
	int tail;
	int size;
}SeqQueue;

SeqQueue q;

void SeqQueueInit(SeqQueue* q);

void SeqQueueDestroy(SeqQueue* q);

void SeqQueuePush(SeqQueue* q,QueueType value);

void SeqQueuePop(SeqQueue* q);

int SeqQueueTop(SeqQueue* q,QueueType* top);