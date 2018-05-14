#include"List.h"

template<class T>
LinkList<T>::LinkList()
    :_head(new Node(T()))
{
    _head->_next = _head;
    _head->_prev = _head;
}

template<class T>
LinkList<T>::LinkList(const LinkList<T>& l)
     :_head(new Node(T())) 
{
    _head->_next = _head;
    _head->_prev = _head;

    Node* cur = l._head->_next;
    while(cur != l._head)
    {
        Node* new_node = new Node(cur->data);
        Node* prev = _head->_prev;

        new_node->_next = _head;
        _head->_prev = new_node;

        prev->_next = new_node;
        new_node->_prev = prev;
        cur = cur->_next;
    }
}

template<class T>
LinkList<T>& LinkList<T>::operator=(const LinkList<T>& l)
{
    if(this != &l)
    {
        clear();
        Node* cur = l._head->_next;
        while(cur != l._head)
        {
            Node* new_node = new Node(cur->data);
            Node* prev = _head->_prev;

            new_node->_next = _head;
            _head->_prev = new_node;

            prev->_next = new_node;
            new_node->_prev = prev;
            cur = cur->_next;
        }
    }
    return *this;
}

template<class T>
void LinkList<T>::Insert(Node* pos,const T& value)
{
    assert(pos);
    Node* prev_node = pos->_prev;
    Node* new_node = new Node(value);
    prev_node->_next = new_node;
    new_node->_prev = prev_node;
    new_node->_next = pos;
    pos->_prev = new_node;
}

template<class T>
void LinkList<T>::PushBack(const T& value)
{
   Insert(_head,value); 
}

template<class T>
void LinkList<T>::PushFront(const T& value)
{
    Insert(_head->_next,value);
}

template<class T>
void LinkList<T>::Erase(Node* pos)
{
    assert(pos);
    assert(pos != _head);
    if(_head->_next == _head)
    {
        return;
    }
    Node* prev = pos->_prev;
    Node* next = pos->_next;
    prev->_next = next;
    next->_prev = prev;
    delete pos;
}

template<class T>
void LinkList<T>::PopBack()
{
    if(_head->_next == _head)
    {
        return;
    }
    Erase(_head->_prev);
}

template<class T>
void LinkList<T>::PopFront()
{
    if(_head->_next == _head)
    {
        return;
    }
    Erase(_head->_next);
}

template<class T>
T& LinkList<T>::Front()
{
    return (_head->_next)->data;
}

template<class T>
bool LinkList<T>::Empty()
{
    return _head->_next == _head;
}

template<class T>
void LinkList<T>::clear()
{
    if(_head->_next == _head)
    {
        return;
    }
    Node* cur = _head->_next;
    while(cur != _head)
    {
        Node* next = cur->_next;
        _head->_next = next;
        next->_prev = _head;
        delete cur;
        cur = next;
    }
}


template<class T>
LinkList<T>::~LinkList()
{
    clear();
    delete _head;
    _head = NULL;
}

template<class T>
void LinkList<T>::Show(const char* msg)
{
    cout<<msg<<"  ";
    Node* cur = _head->_next;
    while(cur != _head)
    {
        cout<<cur<<":"<<cur->data<<"  ";
        cur = cur->_next;
    }
    cout<<endl;
}
