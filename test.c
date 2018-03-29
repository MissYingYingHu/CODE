#include"Queue.h"
#include<stdio.h>
#include<windows.h>

#define TEST_HEADER printf("\n================%s================\n",__FUNCTION__)
void Test()
{
	Queue q;
	QueueType top;
	TEST_HEADER;
	InitQueue(&q);
	PushQueue(&q,'a');
	PushQueue(&q,'b');
	PushQueue(&q,'c');
	PushQueue(&q,'d');
	TopQueue(&q,&top);
	printf("top:expext a,actual is %c\n",top);

	PopQueue(&q);
	TopQueue(&q,&top);
	printf("top:expext b,actual is %c\n",top);

	PopQueue(&q);
	TopQueue(&q,&top);
	printf("top:expext c,actual is %c\n",top);

	PopQueue(&q);
	TopQueue(&q,&top);
	printf("top:expext d,actual is %c\n",top);

	PopQueue(&q);
	TopQueue(&q,&top);
	printf("top:expext d,actual is %c\n",top);

	PopQueue(&q);
	TopQueue(&q,&top);
	printf("top:expext d,actual is %c\n",top);
}
///////////////////////////////////////////////////
int main()
{
	Test();
	system("pause");
	return 0;
}