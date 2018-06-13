#include<stdio.h>
#include<stdlib.h>
#include"LinkStack.h"

//��ʼ��ջ
void InitStack(LinkStack** Lstack)
{
	*Lstack = NULL;
}
//��ӡջ
void ShowStack(LinkStack* Lstack)
{
	LinkStack* cur = Lstack;
	if(cur == NULL)
	{
		printf("��ջ\n");
		return;
	}
	printf("[ջ��]");
	for(;cur != NULL;cur=cur->next )
	{
		printf("%c ",cur->data );
	}
	printf("[ջ��]\n");
}
LinkStack* CreateNode(LElemType value)
{
	LinkStack* new_node = (LinkStack*)malloc(sizeof(LinkStack));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}
//��ջ
void PushStack(LinkStack** Lstack,LElemType value)
{
	LinkStack* cur = *Lstack;
	if(Lstack == NULL)
	{
		return;
	}
	if(*Lstack == NULL)
	{
		*Lstack = CreateNode(value);
		return;
	}
	while(cur->next != NULL)
	{
		cur = cur->next ;
	}
	cur->next  = CreateNode(value);
}
void DestroyNode(LinkStack* to_deleted)
{
	free(to_deleted);
}
//��ջ
void PopStack(LinkStack** Lstack)
{
	LinkStack* cur = *Lstack;
	LinkStack* to_deleted = NULL;
	if(Lstack == NULL)
	{
		return;
	}
	if(*Lstack == NULL)
	{
		printf("��ջ\n");
		return;
	}
	if((*Lstack)->next == NULL)
	{
		DestroyNode(*Lstack);
		(*Lstack) = NULL;
		return;
	}
	while(cur->next != NULL)
	{
		if(cur->next ->next == NULL)
		{
			to_deleted = cur->next ;
			cur->next = NULL;
			DestroyNode(to_deleted);
			to_deleted = NULL;
			return;
		}
		cur = cur->next ;
	}
}
//ȡջ��Ԫ��
LElemType TopStack(LinkStack* Lstack)
{
	LinkStack* cur = Lstack;
	if(Lstack == NULL)
	{
		return -1;
	}
	while(cur->next != NULL)
	{
		cur = cur->next ;
	}
	return cur->data ;
}
//����ջ
void DestroyStack(LinkStack** Lstack)
{
	if(Lstack == NULL)
	{
		return;
	}
	(*Lstack)=NULL;
}