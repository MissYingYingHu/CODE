#pragma once

#include"seqstack.h"

typedef char MiniStackType;
typedef struct mini_stack
{
	seqstack data;
	seqstack mini;
}mini_stack;

//初始化最小栈
void InitMiniStack(mini_stack* stack);

//入栈
void PushMiniStack(mini_stack* stack,MiniStackType value);

//出栈
void PopMiniStack(mini_stack* stack);

//取栈顶元素
int TopMiniStack(mini_stack* stack,MiniStackType* top);
//方法2
//使用同一个栈，把一个元素一次入栈2回，较小的元素第二次入栈，较大的元素第一次入栈

typedef struct MiniStack
{
	seqstack min;
}MiniStack;
typedef char MiniType;
void InitMini(MiniStack* stack);

void PushMini(MiniStack* stack,MiniType value);

void PopMini(MiniStack* stack);

int TopMini(MiniStack* stack,MiniType* top);