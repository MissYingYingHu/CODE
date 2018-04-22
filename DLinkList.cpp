#include"DLinkList.h"

LinkList::LinkList (const LinkList& L)
	:_head(new Node(L._head ->_data))
{
	_head->_prev = _head;
	_head->_next = _head;
	Node* cur = (Node*)L._head->_next;
	while(cur != L._head )
	{
		Node* new_node = new Node(DataType(cur->_data ));
		Node* pre = _head->_prev;
		pre->_next = new_node;
		new_node->_prev = pre;
		_head->_prev = new_node;
		new_node->_next = _head;
		cur = cur->_next ;
	}
}
LinkList& LinkList::operator=(const LinkList& L)
{
	if(this->_head != L._head)
	{
		while(_head->_next != _head)
		{
			Node* deleted = _head->_next ;
			_head->_next = deleted->_next ;
			deleted->_next ->_prev = _head;
		}
		Node* cur = (Node*)L._head ->_next ;
		while(cur != L._head )
		{
			Node* new_node = new Node(cur->_data);
			Node* nex = _head->_next ;
			_head->_next = new_node;
			new_node->_prev = _head;
			new_node->_next = nex;
			nex->_prev = new_node;
			cur = cur->_next ;
		}
	}
	return *this;
}
LinkList::~LinkList ()
{
	if(_head == NULL)
	{
		return;
	}
	Node* cur = _head;
	while(_head->_next != _head)
	{
		Node* deleted = _head->_next ;
		_head->_next = deleted->_next ;
		deleted->_prev = _head;
		delete deleted;
		deleted = NULL;
	}
	delete _head;
	_head = NULL;
}
void LinkList::PushBack(DataType value)
{
	if(this->_head == NULL)
	{
		return ;
	}
	Node* new_node = new Node(value);
	Node* pre = _head->_prev ;
	pre->_next = new_node;
	new_node->_prev = pre;
	new_node->_next = _head;
	_head->_prev = new_node;
}
void LinkList::PopBack ()
{
	if(this->_head == NULL)
	{
		return;
	}
	if(_head->_next == _head)
	{
		return;
	}
	Node* deleted = _head->_prev ;
	_head->_prev = deleted->_prev ;
	deleted->_prev ->_next = _head;
	delete deleted;
	deleted = NULL;
}
Node* LinkList::PushFront (DataType value)
{
	if(_head == NULL)
	{
		return NULL;
	}
	Node* new_node = new Node(value);
	Node* nex = _head->_next ;
	_head->_next = new_node;
	new_node->_prev = _head;
	new_node->_next = nex;
	nex->_prev = new_node;
	return new_node;
}
void LinkList::PopFront ()
{
	if(_head == NULL)
	{
		return;
	}
	if(_head->_next == _head)
	{
		return;
	}
	Node* deleted = _head->_next ;
	_head->_next = deleted->_next ;
	deleted->_next ->_prev = _head;
	delete  deleted;
	deleted = NULL;
}
Node* LinkList::Find (DataType to_find)
{
	if(_head == NULL)
	{
		return NULL;
	}
	if(_head->_next == _head)
	{
		//空链表，直接返回
		return NULL;
	}
	Node* cur = _head->_next ;
	while(cur != _head)
	{
		if(cur->_data == to_find)
		{
			return cur;
		}
		cur = cur->_next ;
	}
	return NULL;
}
//1.在该位置的前面插入节点
void LinkList::InsertFront (Node* pos,DataType value)
{
	if(_head == NULL || pos == NULL)
	{
		return;
	}
	if(_head->_next == _head)
	{
		return;
	}
	Node* new_node = new Node(value);
	Node* pre = pos->_prev ;
	pos->_prev = new_node;
	new_node->_next = pos;
	new_node->_prev = pre;
	pre->_next = new_node;
}
//2.在该位置的后面插入节点
void LinkList::InsertBack (Node* pos,DataType value)
{
	if(_head == NULL || pos == NULL)
	{
		return;
	}
	if(_head->_next == _head)
	{
		return;
	}
	Node* new_node = new Node(value);
	Node* nex = pos->_next ;
	pos->_next = new_node;
	new_node->_next = pos;
	new_node->_next = nex;
	nex->_prev = new_node;
}
void LinkList:: Erase(Node* pos)
{
	if(_head == NULL || pos == NULL)
	{
		return;
	}
	if(_head->_next == _head)
	{
		return;
	}
	Node* pre = pos->_prev ;
	pre->_next = pos->_next ;
	pos->_next ->_prev = pre;
	delete pos;
	pos = NULL;
}
