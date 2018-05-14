#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
struct LinkNode
{
    T data;
    LinkNode<T>* _prev;
    LinkNode<T>* _next;

    LinkNode(T value)
        :data(value)
        ,_prev(NULL)
        ,_next(NULL)
    {}
};
template<class T>
class LinkList
{
public:
    typedef LinkNode<T> Node;
    LinkList();
    LinkList(const LinkList<T>& l);
    LinkList<T>& operator=(const LinkList<T>& l); 
    void Insert(Node* pos,const T& value);
    void PushBack(const T& value);
    void PushFront(const T& value);
    void Erase(Node* pos);
    void PopBack();
    void PopFront();
    T& Front();
    bool Empty();
    void clear();
    ~LinkList();
    void Show(const char* msg);
protected:
    Node* _head;
};
