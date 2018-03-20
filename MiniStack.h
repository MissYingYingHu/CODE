#pragma once

#include"seqstack.h"

typedef char MiniStackType;
typedef struct mini_stack
{
	seqstack data;
	seqstack mini;
}mini_stack;

//��ʼ����Сջ
void InitMiniStack(mini_stack* stack);

//��ջ
void PushMiniStack(mini_stack* stack,MiniStackType value);

//��ջ
void PopMiniStack(mini_stack* stack);

//ȡջ��Ԫ��
int TopMiniStack(mini_stack* stack,MiniStackType* top);
//����2
//ʹ��ͬһ��ջ����һ��Ԫ��һ����ջ2�أ���С��Ԫ�صڶ�����ջ���ϴ��Ԫ�ص�һ����ջ

typedef struct MiniStack
{
	seqstack min;
}MiniStack;
typedef char MiniType;
void InitMini(MiniStack* stack);

void PushMini(MiniStack* stack,MiniType value);

void PopMini(MiniStack* stack);

int TopMini(MiniStack* stack,MiniType* top);