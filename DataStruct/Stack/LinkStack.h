#pragma once

#define FunctionName printf("\n**********************%s*******************\n",__FUNCTION__)

#define LElemType char
typedef struct LinkStack
{
	struct LinkStack* next;
	LElemType data;
}LinkStack;

LinkStack* Lstack;

//��ʼ��ջ
void InitStack(LinkStack** Lstack);

//��ӡջ
void ShowStack(LinkStack* Lstack);

//��ջ
void PushStack(LinkStack** Lstack,LElemType value);

//��ջ
void PopStack(LinkStack** Lstack);

//ȡջ��Ԫ��
LElemType TopStack(LinkStack* Lstack);

//����ջ
void DestroyStack(LinkStack** Lstack);