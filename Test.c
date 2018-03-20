#include"ShareStack.h"
#include<stdio.h>
#include<windows.h>

#define TEST_HEADER printf("\n================%s=================\n",__FUNCTION__)

void TestTop0()
{
	ShareStack stack;
	ShareStackType top;
	TEST_HEADER;
	InitShareStackTop0(&stack);
	PushShareStackTop0(&stack,'a');
	PushShareStackTop0(&stack,'b');
	PushShareStackTop0(&stack,'c');
	PushShareStackTop0(&stack,'d');
	TopShareStackTop0(&stack,&top);
	printf("top:expect is d,actual is %c\n",top);
	PopShareStackTop0(&stack);

	TopShareStackTop0(&stack,&top);
	printf("top:expect is c,actual is %c\n",top);
	PopShareStackTop0(&stack);

	TopShareStackTop0(&stack,&top);
	printf("top:expect is b,actual is %c\n",top);
	PopShareStackTop0(&stack);

	TopShareStackTop0(&stack,&top);
	printf("top:expect is a,actual is %c\n",top);
	//PopShareStackTop0(&stack);
}
void TestTop1()
{
	ShareStack stack;
	ShareStackType top;
	TEST_HEADER;
	InitShareStackTop0(&stack);
	PushShareStackTop1(&stack,'a');
	PushShareStackTop1(&stack,'b');
	PushShareStackTop1(&stack,'c');
	PushShareStackTop1(&stack,'d');
	TopShareStackTop1(&stack,&top);
	printf("top:expect is d,actual is %c\n",top);
	PopShareStackTop1(&stack);

	TopShareStackTop1(&stack,&top);
	printf("top:expect is c,actual is %c\n",top);
	PopShareStackTop1(&stack);

	TopShareStackTop1(&stack,&top);
	printf("top:expect is b,actual is %c\n",top);
	PopShareStackTop1(&stack);

	TopShareStackTop1(&stack,&top);
	printf("top:expect is a,actual is %c\n",top);
	PopShareStackTop0(&stack);
}
int main()
{
	TestTop0();
	TestTop1();
	system("pause");
	return 0;
}