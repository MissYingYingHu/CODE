#include"MiniStack.h"
#include<stdio.h>
#include<windows.h>

#define TEST_HEADER printf("\n===================%s==================\n",__FUNCTION__)
void Test()
{
	mini_stack stack;
	MiniStackType top;
	int ret = 0;
	int ret1 = 0;
	int ret2 = 0;
	TEST_HEADER;
	InitMiniStack(&stack);
	PushMiniStack(&stack,'e');
	PushMiniStack(&stack,'s');
	PushMiniStack(&stack,'a');
	PushMiniStack(&stack,'c');
	PushMiniStack(&stack,'b');
	ret = TopMiniStack(&stack,&top);
	//printf("ret expect is 1,actual is %d\n",ret);
	printf("top expect is a,actual is %c\n",top);
	PopMiniStack(&stack);
	PopMiniStack(&stack);
	PopMiniStack(&stack);
	ret1 = TopMiniStack(&stack,&top);
	//printf("ret expect is 1,actual is %d\n",ret1);
	printf("top expect is e,actual is %c\n",top);
	PopMiniStack(&stack);

	ret2 = TopMiniStack(&stack,&top);
	//printf("ret expect is 1,actual is %d\n",ret2);
	printf("top expect is e,actual is %c\n",top);
	PopMiniStack(&stack);
}
void Test2()
{
	MiniStack stack;
	MiniType top;
	int ret = 0;
	TEST_HEADER;
	InitMini(&stack);
	PushMini(&stack,'e');
	PushMini(&stack,'s');
	PushMini(&stack,'a');
	PushMini(&stack,'c');
	PushMini(&stack,'b');
	ret = TopMini(&stack,&top);
	//printf("ret expect is 1,actual is %d\n",ret);
	printf("top expect is a,actual is %c\n",top);
	PopMini(&stack);
	PopMini(&stack);
	PopMini(&stack);
	ret = TopMini(&stack,&top);
	//printf("ret expect is 1,actual is %d\n",ret);
	printf("top expect is e,actual is %c\n",top);
	PopMini(&stack);
	TopMini(&stack,&top);
	printf("top expect is e,actual is %c\n",top);
}
int main()
{
	Test();
	Test2();
	system("pause");
	return 0;
}