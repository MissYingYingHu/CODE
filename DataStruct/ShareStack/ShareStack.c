#include"ShareStack.h"
#include<stdio.h>

void InitShareStackTop0(ShareStack* stack)
{
	if(stack == NULL)
	{
		//�Ƿ�����
		return;
	}
	stack->top0 = 0;
	stack->top1 = ShareMaxSize;
}
void PushShareStackTop0(ShareStack* stack,ShareStackType value)
{
	if(stack == NULL)
	{
		return;
	}
	if(stack->top0 >= stack->top1 )
	{
		//˵������ջ������ֱ��return
		return;
	}
	stack->data [stack->top0 ++] = value;
}
void PopShareStackTop0(ShareStack* stack)
{
	if(stack == NULL)
	{
		return;
	}
	if(stack->top0 == 0)
	{
		//˵��top1��ջ���ǿ�ջ
		return;
	}
	--stack->top0 ;
}
int TopShareStackTop0(ShareStack* stack,ShareStackType* top)
{
	if(stack == NULL)
	{
		return 0;
	}
	if(stack->top0 < 0)
	{
		return 0;
	}
	*top = stack->data [stack->top0 - 1];
	return 1;
}

//Top1
void PushShareStackTop1(ShareStack* stack,ShareStackType value)
{
	if(stack == NULL)
	{
		return;
	}
	if(stack->top1 <= stack->top0 )
	{
		return;
	}
	stack->data [stack->top1 --] = value;
}
void PopShareStackTop1(ShareStack* stack)
{
	if(stack == NULL)
	{
		return;
	}
	if(stack->top1 == ShareMaxSize)
	{
		return;
	}
	++stack->top1 ;
}
int TopShareStackTop1(ShareStack* stack,ShareStackType* top)
{
	if(stack == NULL)
	{
		return 0;
	}
	if(stack->top1 == ShareMaxSize)
	{
		return 0;
	}
	*top = stack->data [stack->top1 + 1];
	return 1;
}
