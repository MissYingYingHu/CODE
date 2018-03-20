#pragma once

#include<stddef.h>
#define ShareMaxSize 1000
typedef char ShareStackType;
typedef struct ShareStack
{
	ShareStackType data[ShareMaxSize];
	size_t top0;
	size_t top1;
}ShareStack;

//Top0����ز���
//��ʼ��ջ
void InitShareStackTop0(ShareStack* stack);

//��ջ
void PushShareStackTop0(ShareStack* stack,ShareStackType value);

//��ջ
void PopShareStackTop0(ShareStack* stack);

//ȡջ��Ԫ��
int TopShareStackTop0(ShareStack* stack,ShareStackType* top);

//Top1����ز���
//��ջ
void PushShareStackTop1(ShareStack* stack,ShareStackType value);

//��ջ
void PopShareStackTop1(ShareStack* stack);

//ȡջ��Ԫ��
int TopShareStackTop1(ShareStack* stack,ShareStackType* top);