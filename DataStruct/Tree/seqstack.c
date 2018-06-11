
#include<stdio.h>
#include"seqstack.h"


void InitStack(seqstack* stack)
{
	stack->size = 0;
	stack->data[stack->size ] = 0;
}

void ShowStack(seqstack* stack)
{
	size_t i = 0;
	if(stack == NULL)
	{
		return;
	}
	printf("[ջ��]");
	for(i = 0;i < stack->size ;i++)
	{
		printf(" %c ",stack->data [i]);
	}
	printf("[ջ��]\n");
}

void PushStack(seqstack* stack,SElemType value)
{
	if(stack == NULL)
	{
		return;
	}
	if(stack->size > StackMaxSize)
	{
		//�����˸�ջ�����Χ
		return;
	}
	stack->data [stack->size++ ] = value;
}
void PopStack(seqstack* stack)
{
	if(stack == NULL)
	{
		return;
	}
	if(stack->size == 0)
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
	if(stack->size == 0)
	{
		return 0;
	}
	*value = stack->data[stack->size - 1];
	return 1;
}

//����ջ
void DestroyStack(seqstack* stack)
{
	stack->size = 0;
	stack->data[stack->size ] = 0;
}