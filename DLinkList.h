#pragma once
#include<iostream>
typedef int DataType;
struct ListNode
{
	DataType _data;
	ListNode* _next;
	ListNode* _prev;
	//用初始化列表对该结构体进行初始化
	ListNode(DataType value)
		:_data(value)
		,_next(NULL)
		,_prev(NULL)
	{}
};
typedef ListNode Node;
class LinkList
{
public:
	LinkList()
		:_head(new Node(DataType()))
	{
		_head->_prev = _head;
		_head->_next = _head;
	}
	LinkList(const LinkList& L);
	LinkList& operator=(const LinkList& L);
	~LinkList();
	void PushBack(DataType value);
	void PopBack();
	Node* PushFront(DataType value);
	void PopFront();
	Node* Find(DataType to_find);
	void InsertFront(Node* pos,DataType value);
	void InsertBack(Node* pos,DataType value);
	void Erase(Node* pos);
	void DisplayList(char* msg);
private:
	Node* _head;
};