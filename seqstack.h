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

//求栈中元素的个数
int SizeStack(seqstack* stack);

//把其中的一个栈赋值到另外一个栈中
void AssignStack(seqstack* src,seqstack* dst);