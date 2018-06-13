#include"MiniStack.h"
#include<stdio.h>

void InitMiniStack(mini_stack* stack)
{
	if(stack == NULL)
	{
		return;
	}
	InitStack(&stack->data);
	InitStack(&stack->mini );
}
void PushMiniStack(mini_stack* stack,MiniStackType value)
{
	int ret = 0;
	MiniStackType min;
	MiniStackType top;
	if(stack == NULL)
	{
		return;
	}
	if(stack->mini.size == 0)
	{
		PushStack(&stack->mini,value);
		PushStack(&stack->data,value);
		return;
	}
	else
	{
		ret = TopStack(&stack->mini,&top);
		min = top < value ? top : value;
		PushStack(&stack->mini,min);
		PushStack(&stack->data,value);
	}
}
void PopMiniStack(mini_stack* stack)
{
	if(stack == NULL)
	{
		return;
	}
	PopStack(&stack->mini);
	PopStack(&stack->data);
}
int TopMiniStack(mini_stack* stack,MiniStackType* top)
{
	if(stack == NULL)
	{
		return 0;
	}
	return TopStack(&stack->mini,top);
}
/////////////////////////////////////////////////
/////////////////////////////////////////////////
/////////////////////////////////////////////////
//以下是第二种方法
void InitMini(MiniStack* stack)
{
	if(stack == NULL)
	{
		return;
	}
	InitStack(&stack->min );
}
void PushMini(MiniStack* stack,MiniType value)
{
	int ret = 0;
	MiniType top;
	MiniType min;
	if(stack == NULL)
	{
		return;
	}
	if(stack->min .size == 0)
	{
		PushStack(&stack->min ,value);
		PushStack(&stack->min ,value);
	}
	else
	{
		ret = TopStack(&stack->min ,&top);
		if(ret)
		{
			min = top < value ? top : value;
			PushStack(&stack->min ,value);
			PushStack(&stack->min ,min);
		}
	}
}
void PopMini(MiniStack* stack)
{
	if(stack == NULL)
	{
		return;
	}
	PopStack(&stack->min );
	PopStack(&stack->min );
}
int TopMini(MiniStack* stack,MiniType* top)
{
	if(stack == NULL)
	{
		return 0;
	}
	return TopStack(&stack->min ,top);
}