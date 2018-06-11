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

//初始化栈
void InitStack(seqstack* stack);

//打印栈
void ShowStack(seqstack* stack);

//入栈
void PushStack(seqstack* stack,SElemType value);

//出栈
void PopStack(seqstack* stack);

//取栈顶元素
int TopStack(seqstack* stack,SElemType* value);

//销毁栈
void DestroyStack(seqstack* stack);