#pragma once

#define FunctionName printf("\n**********************%s*******************\n",__FUNCTION__)

#define LElemType char
typedef struct LinkStack
{
	struct LinkStack* next;
	LElemType data;
}LinkStack;

LinkStack* Lstack;

//初始化栈
void InitStack(LinkStack** Lstack);

//打印栈
void ShowStack(LinkStack* Lstack);

//入栈
void PushStack(LinkStack** Lstack,LElemType value);

//出栈
void PopStack(LinkStack** Lstack);

//取栈顶元素
LElemType TopStack(LinkStack* Lstack);

//销毁栈
void DestroyStack(LinkStack** Lstack);