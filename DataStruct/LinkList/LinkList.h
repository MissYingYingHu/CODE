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
int EmptyLinkList(LinkList* head);
//求链表的元素个数
size_t SizeLinkList(LinkList* head);

///////////////////////////////////////////////////////////////////
/////以下是常见面试题
//////////////////////////////////////////////////////////////////

//单链表逆序打印
void ReversePrintLinkList(LinkList* head);
//不允许遍历链表，在pos之前插入
void InsertBeforePosition1(LinkList** head,LinkList* pos,LinkNodeType value);
//约瑟夫环
LinkList* JosephCycle(LinkList* head,size_t eat);
//单链表逆置（2个方法）
void ReverseLinkList(LinkList** head);
void ReverseLinkList2(LinkList** head);
//单链表的冒泡排序
void BubbleSortLinkList(LinkList* head);
//将两个有序链表合成一个有序链表
LinkList* MergeLinkList(LinkList* head1,LinkList* head2);
//寻找链表的中间节点
LinkList* FindMidNode(LinkList* head);
//寻找链表的倒数第K个节点
LinkList* FindLastKNode(LinkList* head,size_t k);
//删除倒数第K个节点
void EraseLastKNode(LinkList** head,size_t k);
//判定单链表是否带环，若带环则返回1，否则返回0
int HasCycle(LinkList* head);
//若链表带环，求环的长度
size_t SizeCycle(LinkList* head);
//若链表带环，求环的入口
LinkList* HasCycleEntry(LinkList* head);
//判断两个链表是否相交，若相交，求出交点(列表不带环的情况)
LinkList* HasCross(LinkList* head1,LinkList* head2);
//链表带环
LinkList* HasCross2(LinkList* head1,LinkList* head2);
//求两个已排序链表中相同的元素
LinkList* SameNode(LinkList* head1,LinkList* head2);
//复杂链表的复制
typedef struct ComplexList{
	LinkNodeType data;
	struct ComplexList* next;
	struct ComplexList* random;
}ComplexList;
ComplexList* CreateComplex(LinkNodeType value);
ComplexList* CopyComplex(ComplexList* head);
