
#include<stdio.h>
#include"seqstack.h"


void InitStack(seqstack* stack)
{
	if(stack == NULL)
	{
		return;
	}
	stack->size = 0;
}

void ShowStack(seqstack* stack)
{
	int i = 0;
	if(stack == NULL)
	{
		return;
	}
	printf("[栈底]");
	for(i = 0;i < stack->size ;i++)
	{
		printf(" %c ",stack->data [i]);
	}
	printf("[栈顶]\n");
}

void PushStack(seqstack* stack,SElemType value)
{
	if(stack == NULL)
	{
		return;
	}
	if(stack->size > StackMaxSize)
	{
		//超出了该栈的最大范围
		return;
	}
	stack->data [stack->size ] = value;
	++stack->size;
}
void PopStack(seqstack* stack)
{
	if(stack == NULL)
	{
		return;
	}
	if(stack->size <= 0)
	{
		return;
	}
	--stack->size;
}
int TopStack(seqstack* stack,SElemType* value)
{
	if(stack == NULL || value == NULL)
	{
		return 0;
	}
	if(stack->size <= 0)
	{
		return 0;
	}
	*value = stack->data[stack->size - 1];
	return 1;
}

//销毁栈
void DestroyStack(seqstack* stack)
{
	stack->size = 0;
	stack->data[stack->size ] = 0;
}