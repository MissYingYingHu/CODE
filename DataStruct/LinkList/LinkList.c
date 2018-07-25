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
int EmptyLinkList(LinkList* head)
{
	return (head == NULL) ? 1: 0;
}
size_t SizeLinkList(LinkList* head)
{
	if(head == NULL)
	{
		return 0;
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
///////////////////////////////////////////////////////////////////////////////////////
////////////////以下是常见的面试题
///////////////////////////////////////////////////////////////////////////////////////
void ReversePrintLinkList(LinkList* head)
{
	if(head == NULL)
	{
		return;
	}
	else
	{
		ReversePrintLinkList(head->next);
	}
	printf("%c ",head->data);
}
void InsertBeforePosition1(LinkList** head,LinkList* pos,LinkNodeType value)
{
	//移花接木法
	if(head == NULL || pos == NULL || *head == NULL)
	{
		return;
	}
	LinkList* new_node= CreateNode(value);
	new_node->next = pos->next;
	pos->next = new_node;
	new_node->data = pos->data;
	pos->data = value;

}
LinkList* JosephCycle(LinkList* head,size_t eat)
{
	if(head == NULL || eat == 0)
	{
		return NULL;
	}
	LinkList* cur = head;
	while(cur->next != cur)
	{
		size_t e = 1;
		for(;e < eat;e++)
		{
			cur = cur->next;
		}
		printf("被吃掉的是：%c\n",cur->data);
		LinkList* deleted = cur->next;
		cur->data = deleted->data;
		cur->next = deleted->next;
		deleted = NULL;	
		DestroyNode(deleted);
	}
	return cur;
}
//把头结点的next节点拆下来，然后把它放到头结点的前一个，一个一个的删掉一个一个的插入
void ReverseLinkList(LinkList** head)
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
	LinkList* cur = *head;
	LinkList* deleted = NULL;
	while(cur->next != NULL)
	{
		LinkList* deleted = cur->next;
		cur->next = deleted->next;
		deleted->next = *head;
		*head = deleted;
	}
}
//设置3个指针，分别指向当前节点的前驱和后继,然后移动3个指针的位置。
void ReverseLinkList2(LinkList** head)
{
	if(head == NULL)
	{
		return;
	}
	if(*head == NULL)
	{
		return;
	}
	LinkList* cur = *head;
	LinkList* pre = NULL;
	while(cur != NULL)
	{
		LinkList* nex = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nex;
	}
	*head = pre;
}
void BubbleSortLinkList(LinkList* head)
{
	if(head == NULL)
	{
		return;
	}
	LinkList* cur = head;
	LinkList* cur1 = head;
	LinkList* tail = NULL;
	for(cur = head;cur != tail;cur = cur->next)
	{
		for(cur1 = head;cur1->next != tail;cur1 = cur1->next)
		{
			if(cur1->data > cur1->next->data)
			{
				LinkNodeType tmp = cur1->data;
				cur1->data = cur1->next->data;
				cur1->next->data = tmp;
			}
		}
		tail = cur1;
	}
}
LinkList* MergeLinkList(LinkList* head1,LinkList* head2)
{
	LinkList* cur1 = head1;
	LinkList* cur2 = head2;
	LinkList* beg = NULL;
	LinkList* end = NULL;
	while(cur1 != NULL && cur2 != NULL)
	{
		if(cur1->data < cur2->data)
		{
			if(beg == NULL)
			{
				beg = end =  cur1;
			}
			else
			{
				end->next = cur1;
				end = end->next;
			}
			cur1 = cur1->next;
		}
		else
		{
			if(beg == NULL)
			{
				beg = end = cur2;
			}
			else
			{
				end->next = cur2;
				end = end->next;
			}
			cur2 = cur2->next;
		}
	}
	if(cur1 != NULL)
	{
		end->next = cur1;
	}
	else
	{
		end->next = cur2;
	}
	return beg;
}
LinkList* FindMidNode(LinkList* head)
{
	if(head == NULL && head->next == NULL)
	{
		return NULL;
	}
	LinkList* slow = head;
	LinkList* quick = head;
	while(quick->next != NULL && quick->next->next != NULL)
	{
		slow = slow->next;
		quick = quick->next->next;
	}
	return slow;
}
LinkList* FindLastKNode(LinkList* head,size_t k)
{
	if(head == NULL || k == 0)
	{
		return NULL;
	}
	size_t size = SizeLinkList(head);
	if(k > size)
	{
		return NULL;
	}
	LinkList* slow = head;
	LinkList* quick = head;
	size_t i = 1;
	for(;i < k;i++)
	{
		quick = quick->next;
	}
	while(quick->next != NULL)
	{
		quick = quick->next;
		slow = slow->next;
	}
	return slow;
}
void EraseLastKNode(LinkList** head,size_t k)
{
	if(head == NULL || k == 0)
	{
		return;
	}
	if(*head == NULL)
	{
		return;
	}
	size_t size = SizeLinkList(*head);
	if(k > size)
	{
		return;
	}
	LinkList* deleted = FindLastKNode(*head,k);
	if(deleted == (*head))
	{
		*head = (*head)->next;
		DestroyNode(deleted);
		deleted = NULL;
		return;
	}
	if(k == 1)
	{
		DestroyNode(deleted);
		deleted = NULL;
		return;
	}
	LinkList* next = deleted->next;
	deleted->data = next->data;
	deleted->next = next->next;
	DestroyNode(next);
	next = NULL;
}
int HasCycle(LinkList* head)
{
	if(head == NULL)
	{
		return 0;
	}
	LinkList* slow = head;
	LinkList* quick = head;
	while(quick->next != NULL && quick->next->next != NULL)
	{
		slow = slow->next;
		quick = quick->next->next;
		if(quick == slow)
		{
			return 1;
		}
	}
	return 0;
}
size_t SizeCycle(LinkList* head)
{
	if(head == NULL)
	{
		return 0;
	}
	LinkList* slow = head;
	LinkList* quick = head;
	while(quick->next != NULL && quick->next->next != NULL)
	{
		slow = slow->next;
		quick = quick->next->next;
		if(slow == quick)
		{
			size_t count = 1;
			while(slow->next != quick)
			{
				slow = slow->next;
				++count;
			}
			return count;
		}
	}
	return 0;
}
LinkList* HasCycleEntry(LinkList* head)
{
	if(head == NULL)
	{
		return NULL;
	}
	LinkList* slow = head;
	LinkList* quick = head;
	while(quick->next != NULL && quick->next->next != NULL)
	{
		slow = slow->next;
		quick = quick->next->next;
		if(slow == quick)
		{
			slow = head;
			while(slow != quick)
			{
				quick = quick->next;
				slow = slow->next;
			}
			return slow;
		}
	}
	return NULL;
}
//两个无环链表是否相交
LinkList* HasCross(LinkList* head1,LinkList* head2)
{
  	if(head1 == NULL || head2 == NULL)
  	{
  		return NULL;
  	}
	LinkList* cur1 = head1;
	LinkList* cur2 = head2;
	size_t s1 = SizeLinkList(head1);
	size_t s2 = SizeLinkList(head2);
		if(s1 > s2)
		{
			size_t i = 0;
			for(;i < s1 - s2;++i)
			{
				cur1  =cur1->next;
			}
			while(cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}
		else
		{
			size_t i = 0;
			for(i = 0;i < s2 - s1;++i)
			{
				cur2 = cur2->next;
			}
			while(cur1 != cur2)
			{
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}
		if(cur1 != NULL)
		{
			return cur1;
		}
	return NULL;
}
LinkList* HasCross2(LinkList* head1,LinkList* head2)
{
	if(head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	LinkList* entry1 = HasCycleEntry(head1);
    LinkList* entry2 = HasCycleEntry(head2);
	if(entry1 == NULL || entry2 == NULL)
	{
		//如果两个链表中的任意一个链表不带环，则这两个链表一定不带环
		return NULL;
	}
	//如果两个链表的入口点相同，那么这两个链表一定在环外相交
	//环外相交，那么其求交点的方法就和上面的那个函数相同
	if(entry1 == entry2)
	{
		size_t s1 = 0;
		LinkList* cur1 = NULL;
		LinkList* cur2 = NULL;
		for(cur1 = head1;cur1 != entry1;cur1 = cur1->next)
		{
			++s1;
		}
		size_t s2 = 0;
		for(cur2 = head2;cur2 != entry1;cur2 = cur2->next)
		{
			++s2;
		}
		if(s1 > s2)
		{
			size_t i = 0;
			cur1 = head1;
			cur2 = head2;
			for(;i < (s1-s2);++i)
			{
				cur1 = cur1->next;
			}
			while(cur1 != entry1->next)
			{
				if(cur1 == cur2)
				{
					return cur1;
				}
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}
		else 
		{
			size_t i = 0;
			cur1 = head1;
			cur2 = head2;
			for(;i < (s2-s1);++i)
			{
				cur2 = cur2->next;
			}
			while(cur1 != entry1->next)
			{
				if(cur1 == cur2)
				{
					return cur1;
				}
				cur1 = cur1->next;
				cur2 = cur2->next;
			}
		}
	}
	//如果两个链表的入口点不相同，则一定在环内相交
	//在环内相交，那么交点就是两个链表的环的入口,所以返回任意一个交点都可以
	if(entry1 != entry2)
	{
		return entry1;
	}
	return NULL;
}
ComplexList* CreateComplex(LinkNodeType value)
{
	ComplexList* new_node = (ComplexList*)malloc(sizeof(ComplexList));
	new_node->data = value;
	new_node->next = NULL;
	new_node->random = NULL;
	return new_node;
}
size_t Distance(ComplexList* src,ComplexList* dst)
{
	if(src == NULL || dst == NULL)
	{
		return (size_t)-1;
	}
	while(src != NULL)
	{
		size_t count = 0;
		if(src == dst)
		{
			return count;
		}
		src = src->next;
		++count;
	}
	return (size_t)-1;
}
ComplexList* SetRandom(ComplexList* new_head,size_t offset)
{
	ComplexList* cur = new_head;
	while(offset)
	{
		if(cur == NULL)
		{
			return NULL;
		}
		cur = cur->next;
		--offset;
	}
	return cur;
}
ComplexList* CopyComplex(ComplexList* head)
{
	if(head == NULL) 
	{
		return NULL;
	}
	ComplexList* cur = head;
	ComplexList* new_head = NULL;
	ComplexList* new_tail = NULL;
	//1.先把复杂链表中的每个节点copy到新的链表中
	for(;cur != NULL;cur = cur->next)
	{
		ComplexList* new_node = CreateComplex(cur->data);
		if(new_head == NULL)
		{
			new_head = new_tail = new_node;
		}
		else
		{
			new_tail->next = new_node;
			new_tail = new_tail->next;
		}
	}
	ComplexList* new_cur = new_head; 
	for(cur = head;cur != NULL && new_cur != NULL;cur = cur->next,new_cur = new_cur->next)
	{
		if(cur->random == NULL)
		{
			new_cur->random = NULL;
			continue;
		}
		//2.然后求出每个节点random的偏移量
		size_t offset = Distance(head,cur->random);
		//3.把没个节点的random指针指到正确的位置
		new_cur->random = SetRandom(new_head,offset);
	}
	return new_head;
}
ComplexList* CopyComplex2(ComplexList* head)
{
	if(head == NULL)
	{
		return NULL;
	}
	//方法二：
	//1.把没个节点copy一下插到它的后面
	ComplexList* cur = head;
	for(;cur != NULL;cur = cur->next->next)
	{
		ComplexList* new_node = CreateComplex(cur->data);
		cur->next = new_node->next;
		cur->next = new_node;
	}
	//2.把原节点的random指针指向新节点的random
	for(cur = head;cur != NULL;cur = cur->next->next)
	{
		if(cur->random == NULL)
		{
			cur->next->random = NULL;
			continue;
		}
		cur->next->random = cur->random->next;
	}
	//3.把复制的所有节点都拆下来放到新的链表中
	ComplexList* new_head = NULL;
	ComplexList* new_tail = NULL;
	for(cur = head;cur != NULL;cur = cur->next)
	{
		ComplexList* deleted = cur->next;
		cur->next = deleted->next;
		if(new_head == NULL)
		{
			new_head = new_tail = deleted;
		}
		else
		{
			new_tail->next = deleted;
			new_tail = new_tail->next;
		}
	}
	return new_head;
}
LinkList* SameNode(LinkList* head1,LinkList* head2)
{
	if(head1 == NULL || head2 == NULL)
	{
		return NULL;
	}
	LinkList* cur1 = head1;
	LinkList* cur2 = head2;
	LinkList* head = NULL;
	LinkList* tail = NULL;
	while(cur1 != NULL && cur2 != NULL)
	{
		if(cur1->data < cur2->data)
		{
			cur1 = cur1->next;
		}
		else if(cur1->data > cur2->data)
		{
			cur2 = cur2->next;
		}
		else
		{
			LinkList* new_node = CreateNode(cur1->data);
			if(head == NULL)
			{
				head = tail = new_node;
			}
			else
			{
				tail->next = new_node;
				tail = tail->next;
			}
		   	cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}
	return head;
}
/////////////////////////Test/////////////////////////////////
void PrintLinkList(LinkList* head,LinkNodeType* massage)
{
	printf("%s",massage);
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
	PrintLinkList(head,"头插5个元素：");
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
	PrintLinkList(head,"头插5个元素：");
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
	PrintLinkList(head,"头插13个元素：");
	RemoveAllNode(&head,'b');
	PrintLinkList(head,"删除所有的b节点后：");
}
void TestEmpty()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	int ret1 = EmptyLinkList(head);
	printf("ret expect is 1,actual is %d\n",ret1);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"任意插入5个元素：");
	int ret = EmptyLinkList(head);
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
	PrintLinkList(head,"头插5个元素：");
	size_t ret = SizeLinkList(head);
	printf("ret expect is 5,actual is %lu\n",ret);
}
//////////////////////////////////
void TestReversePrint()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"头插5个元素：");
	ReversePrintLinkList(head);
	printf("\n");
}
void TestInsertBeforePosition()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	LinkList* pos1 = PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
    LinkList* pos2 = PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	LinkList* pos3 = PushFrontLinkList(&head,'a');
	PrintLinkList(head,"头插5个元素：");
	InsertBeforePosition1(&head,pos1,'q');
	InsertBeforePosition1(&head,pos2,'w');
	InsertBeforePosition1(&head,pos3,'y');
	PrintLinkList(head,"头，中间，尾部分别插入一个个元素：");
}
void TestJosephCycle()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	LinkList* end = PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	LinkList* beg = PushFrontLinkList(&head,'a');
	end->next = beg;
//	PrintLinkList(head,"头插5个元素：");
	LinkList* ret = JosephCycle(head,3);
	printf("The surviver is %c:%p\n",ret->data,ret);
}
void TestReverse()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"头插5个元素：");
    ReverseLinkList(&head);
	PrintLinkList(head,"逆置后的链表为");
}
void TestReverse2()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'c');
	PushFrontLinkList(&head,'b');
	PushFrontLinkList(&head,'a');
	PrintLinkList(head,"头插5个元素：");
    ReverseLinkList2(&head);
	PrintLinkList(head,"逆序后的链表为：");
}
void TestBubbleSort()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'g');
	PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'a');
	PushFrontLinkList(&head,'f');
	PushFrontLinkList(&head,'u');
	PushFrontLinkList(&head,'t');
	PrintLinkList(head,"头插8个元素：");
	BubbleSortLinkList(head);
	PrintLinkList(head,"排序后的链表为：");
}
void TestMerge()
{
	LinkList* head;
	LinkList* head1;
	LinkList* head2;
	TestHeader;
	InitLinkList(&head1);
	InitLinkList(&head2);
	PushFrontLinkList(&head1,'z');
	PushFrontLinkList(&head1,'y');
	PushFrontLinkList(&head1,'x');
	PushFrontLinkList(&head1,'v');
    PushFrontLinkList(&head1,'n');
	PushFrontLinkList(&head1,'c');
	PushFrontLinkList(&head1,'a');
	PushFrontLinkList(&head2,'k');
	PushFrontLinkList(&head2,'c');
	PushFrontLinkList(&head2,'b');
	PrintLinkList(head1,"头插4个元素：");
	PrintLinkList(head2,"头插3个元素：");
	head = MergeLinkList(head1,head2);
	PrintLinkList(head,"合成后的链表为：");
}
void TestFindMidNode()
{

	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'g');
	PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'a');
	PushFrontLinkList(&head,'f');
	PushFrontLinkList(&head,'u');
	//PushFrontLinkList(&head,'t');
	PrintLinkList(head,"头插8个节点：");
	LinkList* mid = FindMidNode(head);
	printf("mid:%c\n",mid->data);
}
void TestFindLastKNode()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'g');
	PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'a');
	PushFrontLinkList(&head,'f');
	PushFrontLinkList(&head,'u');
	PushFrontLinkList(&head,'t');
	PrintLinkList(head,"头插8个节点：");
	LinkList* key = FindLastKNode(head,5);
	if(key == NULL)
	{	
		printf("key:%p\n",key);
	}
	else
	{
		printf("key:%c\n",key->data);
	}
}
void TestEraseLastKNode()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'g');
	PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'a');
	PushFrontLinkList(&head,'f');
	PushFrontLinkList(&head,'u');
	PushFrontLinkList(&head,'t');
	PrintLinkList(head,"头插8个节点：");
	EraseLastKNode(&head,5);	
	PrintLinkList(head,"删除倒数第5个节点：");
	EraseLastKNode(&head,7);	
	PrintLinkList(head,"删除头个节点：");
	EraseLastKNode(&head,1);	
	PrintLinkList(head,"删除最后一个个节点：");
}
void TestHasCycle()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	LinkList* e = PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'g');
	PushFrontLinkList(&head,'d');
	LinkList* p = PushFrontLinkList(&head,'a');
	PushFrontLinkList(&head,'f');
	PushFrontLinkList(&head,'u');
	PushFrontLinkList(&head,'t');
	e->next = p;
//	PrintLinkList(head,"头插8个节点：");
	int ret = HasCycle(head);
	printf("ret expext is 1,actual is %d\n",ret);	
}
void TestSizeCycle()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	LinkList* e = PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'g');
	PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'a');
	PushFrontLinkList(&head,'f');
	PushFrontLinkList(&head,'u');
	LinkList* p = PushFrontLinkList(&head,'t');
	e->next = p;
	int ret = SizeCycle(head);
	printf("环中有%d个节点：\n",ret);
}
void TestHasCycleEntry()
{
	LinkList* head;
	TestHeader;
	InitLinkList(&head);
	LinkList* e = PushFrontLinkList(&head,'e');
    PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'g');
	PushFrontLinkList(&head,'d');
	PushFrontLinkList(&head,'a');
	PushFrontLinkList(&head,'f');
	PushFrontLinkList(&head,'u');
	LinkList* p = PushFrontLinkList(&head,'t');
	e->next = p;
	LinkList* entry = HasCycleEntry(head);
	if(entry == NULL)
	{
		printf("该链表无环。entry:%p\n",entry);
	}
	else
	{
		printf("entry:%c\n",entry->data);
	}
}
void TestHasCross()
{
	LinkList* head1;
	LinkList* head2;
	TestHeader;
	InitLinkList(&head1);
	InitLinkList(&head2);
	PushFrontLinkList(&head1,'z');
    PushFrontLinkList(&head1,'n');
	LinkList* p = PushFrontLinkList(&head1,'c');
	PushFrontLinkList(&head1,'a');
    LinkList* q = PushFrontLinkList(&head2,'k');
    PushFrontLinkList(&head2,'c');
	PushFrontLinkList(&head2,'b');
	//q->next = p;
	PrintLinkList(head1,"头插4个元素：");
	PrintLinkList(head2,"头插3个元素：");
	LinkList* cross = HasCross(head1,head2);
	if(cross == NULL)
	{
		printf("不相交。cross:%p\n",cross);
	}
	else
	{
		printf("cross:%c\n",cross->data);
	}
}
void TestHasCross2()
{
	LinkList* head1;
	LinkList* head2;
	TestHeader;
	InitLinkList(&head1);
	InitLinkList(&head2);
	LinkList* g = PushFrontLinkList(&head1,'z');
    PushFrontLinkList(&head1,'n');
	LinkList* p = PushFrontLinkList(&head1,'c');
	PushFrontLinkList(&head1,'a');
	PushFrontLinkList(&head1,'t');
	PushFrontLinkList(&head1,'i');
	LinkList* k = PushFrontLinkList(&head1,'o');
	PushFrontLinkList(&head1,'p');
    LinkList* q = PushFrontLinkList(&head2,'k');
    PushFrontLinkList(&head2,'c');
	PushFrontLinkList(&head2,'b');
	g->next = k;
	q->next = p;
	LinkList* cross = HasCross2(head1,head2);
	if(cross == NULL)
	{
		printf("不相交。cross:%p\n",cross);
	}
	else
	{
		printf("cross:%c\n",cross->data);
	}
}
void TestSameNode()
{
	LinkList* head1;
	LinkList* head2;
	TestHeader;
	InitLinkList(&head1);
	InitLinkList(&head2);
	PushFrontLinkList(&head1,'z');
    PushFrontLinkList(&head1,'y');
    PushFrontLinkList(&head1,'x');
    PushFrontLinkList(&head1,'v');
	PushFrontLinkList(&head1,'c');
	PushFrontLinkList(&head1,'a');
    PushFrontLinkList(&head2,'v');
    PushFrontLinkList(&head2,'g');
    PushFrontLinkList(&head2,'c');
    PushFrontLinkList(&head2,'b');
	PushFrontLinkList(&head2,'a');
	PrintLinkList(head1,"头插6个元素：");
	PrintLinkList(head2,"头插5个元素：");
	LinkList* head = SameNode(head1,head2);
	PrintLinkList(head,"打印相同的元素：");
}
void TestCopyComplex()
{
	TestHeader;
	ComplexList* a = CreateComplex('a');
	ComplexList* b = CreateComplex('b');
	ComplexList* c = CreateComplex('c');
	ComplexList* d = CreateComplex('d');
	a->next = b;
	b->next = c;
	c->next = d;
	d->next = NULL;
	a->random = c;
	b->random = a;
	c->random = NULL;
	d->random = d;
	ComplexList* ret = CopyComplex2(a);
	//CopyComplex2(a);
	printf("head:%p\t%c\n",ret,ret->data);
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
	TestReversePrint();
	TestInsertBeforePosition();
	TestJosephCycle();
	TestReverse();
	TestReverse2();
	TestBubbleSort();
	TestMerge();
	TestFindMidNode();
	TestFindLastKNode();
	TestEraseLastKNode();
	TestHasCycle();
	TestSizeCycle();
	TestHasCycleEntry();
	TestHasCross();
	TestHasCross2();
	TestSameNode();
	TestCopyComplex();
	return 0;
}
