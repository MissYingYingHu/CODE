#include<stdio.h>
#include"LinkStack.h"

void TEST_PushStack()
{
	FunctionName;
	InitStack(&Lstack);
	PushStack(&Lstack,'a');
	PushStack(&Lstack,'b');
	PushStack(&Lstack,'c');
	PushStack(&Lstack,'d');
	ShowStack(Lstack);
}

void TEST_PopStack()
{
	FunctionName;
	InitStack(&Lstack);
	PushStack(&Lstack,'a');
	PushStack(&Lstack,'b');
	PushStack(&Lstack,'c');
	PushStack(&Lstack,'d');
	ShowStack(Lstack);
	PopStack(&Lstack);
	PopStack(&Lstack);
	ShowStack(Lstack);
	PopStack(&Lstack);
	ShowStack(Lstack);
	PopStack(&Lstack);
	ShowStack(Lstack);
	PopStack(&Lstack);
	ShowStack(Lstack);
}
void TEST_TopStack()
{
	LElemType r ;
	FunctionName;
	InitStack(&Lstack);
	PushStack(&Lstack,'a');
	PushStack(&Lstack,'b');
	PushStack(&Lstack,'c');
	PushStack(&Lstack,'d');
	ShowStack(Lstack);
	r = TopStack(Lstack);
	printf("Õ»¶¥ÔªËØÊÇ£º%c \n",r);
}
void TEST_DestroyStack()
{
	FunctionName;
	InitStack(&Lstack);
	PushStack(&Lstack,'a');
	PushStack(&Lstack,'b');
	PushStack(&Lstack,'c');
	PushStack(&Lstack,'d');
	ShowStack(Lstack);
	DestroyStack(&Lstack);
	ShowStack(Lstack);
}
////////////////////////////////////////////////////////////
int main()
{
	TEST_PushStack();
	TEST_PopStack();
	TEST_TopStack();
	TEST_DestroyStack();
	return 0;
}