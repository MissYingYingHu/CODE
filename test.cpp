#include"DLinkList.h"
using namespace std;
#include<windows.h>
void LinkList::DisplayList(char* mag)
{
	if(this->_head == NULL)
	{
		return;
	}
	cout<<mag;
	Node* cur = _head->_next ;
	cout<<"head	";
	while(cur != _head)
	{
		cout<<	cur->_data<<"	";
		cur = cur->_next ;
	}
	cout<<endl;
}
//////////////////////////////Test////////////////////////////////////
#define TEST_HEADER printf("\n------------------%s------------------\n",__FUNCTION__)
void TestPushBack()
{
	LinkList L1;
	TEST_HEADER;
	L1.PushBack (2);
	L1.PushBack (3);
	L1.PushBack (4);
	L1.PushBack (5);
	L1.DisplayList ("β���ĸ��ڵ㣺");
}
void TestPopBack()
{
	LinkList L1;
	TEST_HEADER;
	L1.PushBack (2);
	L1.PushBack (3);
	L1.PushBack (4);
	L1.PushBack (5);
	L1.DisplayList ("β���ĸ��ڵ㣺");
	L1.PopBack ();
	L1.DisplayList ("βɾ1���ڵ㣺");
	L1.PopBack ();
	L1.PopBack ();
	L1.PopBack ();
	L1.DisplayList ("βɾ3���ڵ㣺");
}
void TestPushFront()
{
	LinkList L1;
	TEST_HEADER;
	L1.PushFront (2);
	L1.PushFront (3);
	L1.PushFront (4);
	L1.PushFront (5);
	L1.DisplayList ("ͷ���ĸ��ڵ㣺");
}
void TestPopFront()
{
	LinkList L1;
	TEST_HEADER;
	L1.PushBack (2);
	L1.PushBack (3);
	L1.PushBack (4);
	L1.PushBack (5);
	L1.DisplayList ("β���ĸ��ڵ㣺");
	L1.PopFront ();
	L1.DisplayList ("ͷɾ1���ڵ㣺");
	L1.PopFront ();
	L1.PopFront ();
	L1.DisplayList ("ͷɾ2���ڵ㣺");
	L1.PopFront ();
	L1.DisplayList ("ͷɾ3���ڵ㣺");
}
void TestFind()
{
	LinkList L1;
	TEST_HEADER;
	L1.PushFront (2);
	ListNode* pos = L1.PushFront (3);
	L1.PushFront (4);
	L1.PushFront (5);
	L1.DisplayList ("β���ĸ��ڵ㣺");
	ListNode* Find = L1.Find (3);
	cout<<"actual:"<<Find<<endl;
	cout<<"expect:"<<pos<<endl;
	ListNode* Find1 = L1.Find (7);
	cout<<"actual:"<<Find1<<endl;
	cout<<"expect:"<<NULL<<endl;
}
void TestInsertFront()
{
	LinkList L1;
	TEST_HEADER;
	ListNode* pos1 = L1.PushFront (2);
	L1.PushFront (3);
	L1.PushFront (4);
	ListNode* pos = L1.PushFront (5);
	L1.DisplayList ("ͷ���ĸ��ڵ㣺");
	L1.InsertFront (pos1,6);
	L1.DisplayList ("����һ���ڵ㣺");
	L1.InsertFront (pos,7);
	L1.DisplayList ("����һ���ڵ㣺");
}
void TestInsertBack()
{
	LinkList L1;
	TEST_HEADER;
	ListNode* pos1 = L1.PushFront (2);
	L1.PushFront (3);
	L1.PushFront (4);
	ListNode* pos = L1.PushFront (5);
	L1.DisplayList ("ͷ���ĸ��ڵ㣺");
	L1.InsertBack (pos1,6);
	L1.DisplayList ("����һ���ڵ㣺");
	L1.InsertBack (pos,7);
	L1.DisplayList ("����һ���ڵ㣺");
}
void TestErase()
{
	LinkList L1;
	TEST_HEADER;
	ListNode* pos1 = L1.PushFront (2);
	L1.PushFront (3);
	L1.PushFront (4);
	ListNode* pos = L1.PushFront (5);
	L1.DisplayList ("ͷ���ĸ��ڵ㣺");
	L1.Erase (pos1);
	L1.DisplayList ("����һ���ڵ㣺");
	L1.Erase(pos);
	L1.DisplayList ("����һ���ڵ㣺");
}
void TestLinkList()
{
	LinkList L1;
	TEST_HEADER;
	L1.PushFront (2);
	L1.PushFront (3);
	L1.PushFront (4);
	L1.PushFront (5);
	L1.DisplayList ("ͷ���ĸ��ڵ㣺");
	LinkList L2(L1);
	L2.DisplayList ("ͷ���ĸ��ڵ㣺");
}
void Test()
{
	LinkList L1;
	TEST_HEADER;
	L1.PushFront (2);
	L1.PushFront (3);
	L1.PushFront (4);
	L1.PushFront (5);
	L1.DisplayList ("ͷ���ĸ��ڵ㣺");
	LinkList L2;
	L2.PushFront (4);
	L2.PushFront (5);
	L2.DisplayList ("ͷ�������ڵ㣺");
	L2 = L1;
	L2.DisplayList ("ͷ���ĸ��ڵ㣺");
}
int main()
{
	TestPushBack();
	TestPopBack();
	TestPushFront();
	TestPopFront();
	TestFind();
	TestInsertFront();
	TestInsertBack();
	TestErase();
	TestLinkList();
	Test();
	system("pause");
	return 0;
}