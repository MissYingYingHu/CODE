#pragma once
#include"seqstack.h"

typedef char QueueType;
typedef struct Queue
{
	seqstack entry;
	seqstack exit;
}Queue;

//��ʼ������
void InitQueue(Queue* q);

//���
void PushQueue(Queue* q,QueueType value);

//����
void PopQueue(Queue* q);

//ȡ����Ԫ��
int TopQueue(Queue* q,QueueType* top);