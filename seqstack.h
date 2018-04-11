#pragma once
#include<stddef.h>
#define TESTHEADER printf("\n*************%s************\n",__FUNCTION__)

struct TreeNode;
typedef struct TreeNode* SElemType;
//#define SElemType char

#define StackMaxSize 1000

typedef struct  seqstack 
{
	SElemType data[StackMaxSize];
	size_t size;
}seqstack;

seqstack stack;

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