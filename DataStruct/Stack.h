#pragma once
#include"seqqueue.h"

typedef char StackType;

typedef struct Stack
{
	SeqQueue q1;
	SeqQueue q2;
}Stack;

//��ʼ��ջ
void InitStack(Stack* s);

//��ջ
void PushStack(Stack* s,StackType value);

//��ջ
void PopStack(Stack* s);

//ȡջ��Ԫ��
int TopStack(Stack* s,StackType* top);
