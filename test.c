#include"Stack.h"
#include<stdio.h>
#include<windows.h>
//#define TEST_HEADER printf("\n====================%s====================\n",__FUNCTION__)

void Test()
{
	StackType top;
	Stack s;
	TEST_HEADER;
	InitStack(&s);
	PushStack(&s,'a');
	PushStack(&s,'b');
	PushStack(&s,'c');
	PushStack(&s,'d');
	TopStack(&s,&top);
	printf("top:expect is d,actual is %c\n",top);

	PopStack(&s);
	TopStack(&s,&top);
	printf("top:expect is c,actual is %c\n",top);

	PopStack(&s);
	TopStack(&s,&top);
	printf("top:expect is b,actual is %c\n",top);

	PopStack(&s);
	TopStack(&s,&top);
	printf("top:expect is a,actual is %c\n",top);
}
int main()
{
	Test();
	system("pause");
	return 0;
}