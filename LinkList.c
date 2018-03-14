#include"LinkList.h"
#include<stdio.h>
#include<stdlib.h>
#define TestHeader printf("\n---------------------%s--------------------\n",__FUNCTION__)
void InitLinkList(LinkList** head)
{
	if(head == NULL)
	{
		return;
	}
	*head = NULL;
}
LinkList* CreateNode(LinkNodeType value)
{
	LinkList* new_node = (LinkList*)malloc(sizeof(LinkList));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}
void DestroyNode(LinkList* p)
{
	free(p);
}
void PushTailLinkList(LinkList** head,LinkNodeType value)
{
	if(head == NULL)
	{
		//非法输入
		return;
	}
	if(*head == NULL)
	{
		*head = CreateNode(value);
		return;
	}
	LinkList* cur = *head;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	cur->next = CreateNode(value);
}
void PopTailLinkList(LinkList** head)
{
	if(head == NULL)
	{
		//非法输入
		return;
	}
	if(*head == NULL)
	{
		//空链表
		return;
	}
	if((*head)->next == NULL)
	{
		*head = NULL;
		DestroyNode(*head);
		return;
	}
	LinkList* cur = *head;
	while(cur->next != NULL)
	{
		if(cur->next->next == NULL)
		{
			LinkList* deleted = cur->next;
			cur->next = NULL;
			DestroyNode(deleted);
			deleted = NULL;
			return;
		}
		cur = cur->next;
	}
}
LinkList* PushFrontLinkList(LinkList** head,LinkNodeType value)
{
	if(head == NULL)
	{
		return NULL;
	}
	if(*head == NULL)
	{
		*head = CreateNode(value);
		return (*head);
	}
	LinkList* new_node = CreateNode(value);
	new_node->next = *head;
    *head = new_node;
	return new_node;
}
void PopFrontLinkList(LinkList** head)
{
	if(head == NULL)
	{
		return;
	}
	LinkList* deleted = *head;
	if((*head)->next == NULL)
	{
		*head = NULL;
		DestroyNode(*head);
		return;
	}
	*head = deleted->next;
	DestroyNode(deleted);
	deleted = NULL;
}

LinkList* FindLinkList(LinkList** head,LinkNodeType value)
{
	if(head == NULL || *head == NULL)
	{
		return NULL;
	}
	LinkList* cur = *head;
	while(cur)
	{
		if(cur->data == value)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void InsertBeforePosition(LinkList** head,LinkList* pos,LinkNodeType value)
{
	if(head == NULL || pos == NULL) 
	{
		return;
	}
	if(*head == NULL)
	{
		return;
	}
	LinkList* new_node = CreateNode(value);
	if(pos == (*head))
	{
		new_node->next = *head;
		*head = new_node;
		return;
	}
	LinkList* cur = *head;
	LinkList* pre = NULL;
	while(cur != NULL)
	{
		if(cur->data == pos->data)
		{
			pre->next = new_node;
			new_node->next = cur;
			return;		
		}
		pre = cur;
		cur = cur->next;
	}
}
void InsertAfterPosition(LinkList** head,LinkList* pos,LinkNodeType value)
{
	if(head == NULL || pos == NULL)
	{
		return;
	}
	if(*head == NULL)
	{
		return;
	}
	LinkList* new_node = CreateNode(value);
	LinkList* pos_next = pos->next;
	pos->next = new_node;
	new_node->next = pos_next;
}
void RemoveNodePosition(LinkList** head,LinkList* pos)
{
	if(head == NULL || pos == NULL)
	{
		return;
	}
	if(*head == NULL)
	{
		return;
	}
	LinkList* cur = *head;
	if(pos == *head)
	{
		*head = (*head)->next;
		DestroyNode(cur);
		cur = NULL;
		return;
	}
	while(cur->next != NULL)
	{
		if(cur->next->data == pos->data)
		{
			LinkList* deleted = cur->next;
			cur->next = pos->next;
			DestroyNode(deleted);
			deleted = NULL;
			return;
		}
		cur = cur->next;
	}
}
void EraseNodePosition(LinkList** head,LinkNodeType value)
{
	if(head == NULL || *head == NULL)
	{
		return;
	}
	LinkList* cur = *head;
	if((*head)->data == value)
	{
		(*head) = (*head)->next;
		cur = NULL;
		DestroyNode(cur);
		return;
	}
	while(cur->next != NULL)
	{
		if(cur->next->data == value)
		{
			LinkList* deleted = cur->next;
			cur->next = deleted->next;
			DestroyNode(deleted);
			deleted = NULL;
			return;
		}
		cur = cur->next;
	}
}
void RemoveAllNode(LinkList** head,LinkNodeType value)
{
	if(head == NULL || *head == NULL)
	{
		return;
	}
	LinkList* cur = *head;
	while((*head)->data == value)
	{
		if((*head)->data != value)
		{
			break;
		}
		*head = (*head)->next;
		cur = NULL;
		DestroyNode(cur);
	}
	cur = *head;
	while(cur->next != NULL)
	{
		if(cur->next->data == value)
		{
			LinkList* deleted = cur->next;
			cur->next = deleted->next;
			deleted = NULL;
			DestroyNode(deleted);
			continue;
		}
		cur = cur->next;
	}
}
int EmptyLinkList(LinkList** head)
{
	if(head == NULL)
	{
		return;
	}
	return (*head == NULL) ? 1: 0;
}
size_t SizeLinkList(LinkList* head)
{
	if(head == NULL)
	{
		return;
	}
	size_t count = 0;
	LinkList* cur = head;
	while(cur != NULL)
	{
		++count;
		cur = cur->next;
	}
	return count;
}
/////////////////////////Test/////////////////////////////////
void PrintLinkList(LinkList* head,LinkNodeType* massge)
{
	printf("%s",massge);
	if(head == NULL)
	{
		return;
	}
	LinkList* cur = head;
	while(cur)
	{
		printf("%c ",cur->data);
		cur = cur->next;
	}
	printf("\n");
}
void TestInit()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	printf("head:%p\n",head);
}
void TestPushTail()
{
	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushTailLinkList(&head,'a');
	PushTailLinkList(&head,'b');
	PushTailLinkList(&head,'c');
	PushTailLinkList(&head,'d');
	PushTailLinkList(&head,'e');
	PushTailLinkList(&head,'f');
	PrintLinkList(head,"尾插6个元素：");
}
void TestPopTail()
{

	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushTailLinkList(&head,'a');
	PushTailLinkList(&head,'b');
	PushTailLinkList(&head,'c');
	PrintLinkList(head,"尾插3个元素：");
	PopTailLinkList(&head);
	PopTailLinkList(&head);
	PrintLinkList(head,"尾删2个元素：");
	PopTailLinkList(&head);
	PrintLinkList(head,"尾删1个元素：");
}
void TestPushFront()
{
	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
	PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"头插5个元素：");
}
void TestPopFront()
{
	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
	PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"头插5个元素：");
	PopFrontLinkList(&head);
	PopFrontLinkList(&head);
	PopFrontLinkList(&head);
	PrintLinkList(head,"头删3个元素：");
	PopFrontLinkList(&head);
	PopFrontLinkList(&head);
	PrintLinkList(head,"头删2个元素：");
}
void TestFind()
{

	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
	PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"头插5个元素：");
	LinkList* ret = FindLinkList(&head,'b');
	printf("ret:%p\t%c\n",ret,ret->data);
}
void TestInsertBefore()
{

	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	LinkList* pos1 = PushFrontLinkList(&head,'e');
	LinkList* pos2 = PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	LinkList* pos3 = PushFrontLinkList(&head,'a');
	PrintLinkList(head,"头插5个元素：");
	InsertBeforePosition(&head,pos1,'q');
	InsertBeforePosition(&head,pos2,'t');
	InsertBeforePosition(&head,pos3,'w');
	PrintLinkList(head,"任意插入3个元素：");
}
void TestInsertAfter()
{

	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	LinkList* pos1 = PushFrontLinkList(&head,'e');
	LinkList* pos2 = PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	LinkList* pos3 = PushFrontLinkList(&head,'a');
	PrintLinkList(head,"头插5个元素：");
	InsertAfterPosition(&head,pos1,'q');
	InsertAfterPosition(&head,pos2,'t');
	InsertAfterPosition(&head,pos3,'w');
	PrintLinkList(head,"任意插入3个元素：");
}
void TestRemove()
{

	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	LinkList* pos1 = PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	LinkList* pos2 = PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	LinkList* pos3 = PushFrontLinkList(&head,'a');
	PrintLinkList(head,"任意插入5个元素：");
	RemoveNodePosition(&head,pos1);
	RemoveNodePosition(&head,pos2);
	RemoveNodePosition(&head,pos3);
	PrintLinkList(head,"任意删除3个元素：");
}
void TestErase()
{

	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"任意插入5个元素：");
	EraseNodePosition(&head,'a');
	EraseNodePosition(&head,'c');
	EraseNodePosition(&head,'e');
	PrintLinkList(head,"任意删除3个元素：");
}
void TestRemoveAllNode()
{
	LinkNodeType* massge = NULL;
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'e');
	PushFrontLinkList(&head,'b');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'b');
	PrintLinkList(head,"任意插入5个元素：");
	RemoveAllNode(&head,'b');
	PrintLinkList(head,"删除所有的b节点后：");
}
void TestEmpty()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	int ret1 = EmptyLinkList(&head);
	printf("ret expect is 1,actual is %d\n",ret1);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"任意插入5个元素：");
	int ret = EmptyLinkList(&head);
	printf("ret expect is 0,actual is %d\n",ret);
}
void TestSize()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"任意插入5个元素：");
	size_t ret = SizeLinkList(head);
	printf("ret expect is 5,actual is %lu\n",ret);
}
int main()
{
	TestInit();
	TestPushTail();
	TestPopTail();
	TestPushFront();
	TestPopFront();
	TestFind();
	TestInsertBefore();
	TestInsertAfter();
	TestRemove();
	TestRemoveAllNode();
	TestErase();
	TestEmpty();
	TestSize();
	return 0;
}
