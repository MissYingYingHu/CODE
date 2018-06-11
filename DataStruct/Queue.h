#pragma once
#include"seqstack.h"

typedef char QueueType;
typedef struct Queue
{
	seqstack entry;
	seqstack exit;
}Queue;

//初始化队列
void InitQueue(Queue* q);

//入队
void PushQueue(Queue* q,QueueType value);

//出队
void PopQueue(Queue* q);

//取队首元素
int TopQueue(Queue* q,QueueType* top);