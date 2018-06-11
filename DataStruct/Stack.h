#pragma once
#include"seqqueue.h"

typedef char StackType;

typedef struct Stack
{
	SeqQueue q1;
	SeqQueue q2;
}Stack;

//初始化栈
void InitStack(Stack* s);

//入栈
void PushStack(Stack* s,StackType value);

//出栈
void PopStack(Stack* s);

//取栈顶元素
int TopStack(Stack* s,StackType* top);
