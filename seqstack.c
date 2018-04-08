
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
	printf("[ջ��]");
	for(i = 0;i < stack->size ;i++)
	{
		printf(" (%d,%d) ",stack->data[i].row ,stack->data[i].col);
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

//����ջ
void DestroyStack(seqstack* stack)
{
	stack->size = 0;
//	stack->data[stack->size ] = 0;
}

int SizeStack(seqstack* stack)
{
	if(stack == NULL)
	{
		return  0;
	}
	return stack->size;
}
void AssignStack(seqstack* src,seqstack* dst)
{
	int i = 0;
	if(src == NULL || dst == NULL)
	{
		return;
	}
	dst->size = src->size ;
	for(i = 0;i < src->size ;i++)
	{
		dst->data [i] = src->data [i];
	}
	//memcopy(dst,src,sizeof(seqstack));
}