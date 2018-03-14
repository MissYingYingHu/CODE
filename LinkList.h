#pragma once
#include<stddef.h>
typedef char LinkNodeType;
typedef struct LinkList
{
	LinkNodeType data;
	struct LinkList* next;
}LinkList;
//初始化
void InitLinkList(LinkList** head);
//尾插
void PushTailLinkList(LinkList** head,LinkNodeType value);
//尾删
void PopTailLinkList(LinkList** head);
//头插
LinkList* PushFrontLinkList(LinkList** head,LinkNodeType value);
//头删
void PopFrontLinkList(LinkList** head);
//查找
LinkList* FindLinkList(LinkList** head,LinkNodeType value);
//pos之前插入
void InsertBeforePosition(LinkList** head,LinkList* pos,LinkNodeType value);
//pos之后插入
void InsertAfterPosition(LinkList** head,LinkList* pos,LinkNodeType value);
//删除指定位置的元素
void RemoveNodePosition(LinkList** head,LinkList* pos);
//删除指定值的元素
void EraseNodePosition(LinkList** head,LinkNodeType value);
//删除指定值的所有元素
void RemoveAllNode(LinkList** head,LinkNodeType value);
//判断链表是否为空
int EmptyLinkList(LinkList** head);
//求链表的元素个数
size_t SizeLinkList(LinkList* head);
