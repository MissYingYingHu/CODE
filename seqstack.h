#pragma once

#define TESTHEADER printf("\n*************%s************\n",__FUNCTION__)
#define StackMaxSize 1000

typedef struct Point
{
	int row;
	int col;
}Point;
#define SElemType Point

typedef struct  seqstack 
{
	SElemType data[StackMaxSize];
	int size;
}seqstack;


//��ʼ��ջ
void InitStack(seqstack* stack);

//��ӡջ
void ShowStack(seqstack* stack);

//��ջ
void PushStack(seqstack* stack,SElemType value);

//��ջ
void PopStack(seqstack* stack);

//ȡջ��Ԫ��
int TopStack(seqstack* stack,SElemType* value);

//����ջ
void DestroyStack(seqstack* stack);

//��ջ��Ԫ�صĸ���
int SizeStack(seqstack* stack);

//�����е�һ��ջ��ֵ������һ��ջ��
void AssignStack(seqstack* src,seqstack* dst);