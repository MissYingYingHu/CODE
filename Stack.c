#include"Stack.h"
#include<stdio.h>

void InitStack(Stack* s)
{
	if(s == NULL)
	{
		return;
	}
	SeqQueueInit(&s->q1);
	SeqQueueInit(&s->q2);
}
void PushStack(Stack* s,StackType value)
{
	SeqQueue* entry = NULL;
	if(s == NULL)
	{
		return;
	}
	entry = SeqQueueSize(&s->q1 ) > 0 ? (&s->q1) : (&s->q2);
	SeqQueuePush(entry,value);
}
void PopStack(Stack* s)
{
	size_t q1 = 0;
	size_t q2 = 0;
	StackType top;
	SeqQueue* output = NULL;
	SeqQueue* input = NULL;
	if(s == NULL)
	{
		return;
	}
	q1 = SeqQueueSize(&s->q1 );
	q2 = SeqQueueSize(&s->q2 );
	if(q1 == 0 && q2 == 0)
	{
		//两个都是空栈
		return;
	}
	output = SeqQueueSize(&s->q1 ) > 0 ? &s->q1 : &s->q2 ;
	input = SeqQueueSize(&s->q1 ) == 0 ? &s->q1 : &s->q2 ;
	while(SeqQueueSize(output ) > 1)
	{
		SeqQueueTop(output ,&top);
		SeqQueuePush(input,top);
		SeqQueuePop(output);
	}
	SeqQueuePop(output);
}
// 入栈：a,b,c,d  ---> 出栈：d,c,b,a 
//       d -----> a,b,c
int TopStack(Stack* s,StackType* top)
{
	StackType value;
	size_t q1 = 0;
	size_t q2 = 0;
	SeqQueue* output = NULL;
	SeqQueue* input = NULL;
	if(s == NULL)
	{
		return 0;
	}
	q1 = SeqQueueSize(&s->q1 );
	q2 = SeqQueueSize(&s->q2 );
	if(q1 == 0 && q2 == 0)
	{
		//两个都是空栈
		return 0;
	}
	output = SeqQueueSize(&s->q1 ) > 0 ? &s->q1 : &s->q2 ;
	input = SeqQueueSize(&s->q1 ) == 0 ? &s->q1 : &s->q2 ;
	while(SeqQueueSize(output ) > 1)
	{
		SeqQueueTop(output ,&value);
		SeqQueuePush(input,value);
		SeqQueuePop(output);
	}
	SeqQueueTop(output ,&value);
	*top = value;
	SeqQueuePush(input,value);
	return 1;
}