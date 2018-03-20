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

//Top0的相关操作
//初始化栈
void InitShareStackTop0(ShareStack* stack);

//入栈
void PushShareStackTop0(ShareStack* stack,ShareStackType value);

//出栈
void PopShareStackTop0(ShareStack* stack);

//取栈首元素
int TopShareStackTop0(ShareStack* stack,ShareStackType* top);

//Top1的相关操作
//入栈
void PushShareStackTop1(ShareStack* stack,ShareStackType value);

//出栈
void PopShareStackTop1(ShareStack* stack);

//取栈首元素
int TopShareStackTop1(ShareStack* stack,ShareStackType* top);