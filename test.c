#include"Thread.h"

#include<windows.h>
#define TEST_HESDER printf("\n====================%s====================\n",__FUNCTION__)
void PreOrder(ThreadNode* root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%c ",root->data );
	if(root->lflag == Child)
	{
		PreOrder(root->left );
	}
	if(root->rflag == Child)
	{
		PreOrder(root->right );
	}
}
void InOrder(ThreadNode* root)
{
	if(root == NULL)
	{
		return;
	}
	if(root->lflag == Child)
	{
	InOrder(root->left );
	}
	printf("%c ",root->data );
	if(root->rflag == Child)
	{
		InOrder(root->right );
	}
}
void TestTreeCreate()
{
	ThreadNode* root;
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TEST_HESDER;
	root = ThreadTreeCreate(arr,strlen(arr) , '*');
	printf("先序：");
	PreOrder(root);
	printf("\n");
	printf("中序：");
	InOrder(root);
	printf("\n");
}
void TestPreThreading()
{
	ThreadNode* root;
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TEST_HESDER;
	root = ThreadTreeCreate(arr,strlen(arr) , '*');
	PreThreading(root);
	printf("先序：");
	PreOrder(root);
	printf("\n");
	printf("中序：");
	InOrder(root);
	printf("\n");
}
void TestPreOrderByThreading()
{
	ThreadNode* root;
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TEST_HESDER;
	root = ThreadTreeCreate(arr,strlen(arr) , '*');
	PreThreading(root);
	PreOrderByThreading(root);
}
void TestInThreading()
{
	ThreadNode* root;
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TEST_HESDER;
	root = ThreadTreeCreate(arr,strlen(arr) , '*');
	InThreading(root);
	printf("先序：");
	PreOrder(root);
	printf("\n");
	printf("中序：");
	InOrder(root);
	printf("\n");
}
void TestInOrderByThreading()
{
	ThreadNode* root;
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TEST_HESDER;
	root = ThreadTreeCreate(arr,strlen(arr) , '*');
	InThreading(root);
	InOrderByThreading(root);
}
void TestPostThreading()
{
	ThreadNode* root;
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TEST_HESDER;
	root = ThreadTreeCreate(arr,strlen(arr) , '*');
	PostThreading(root);
	printf("先序：");
	PreOrder(root);
	printf("\n");
	printf("中序：");
	InOrder(root);
	printf("\n");
}
int main()
{
	TestTreeCreate();
	TestPreThreading();
	TestPreOrderByThreading();
	TestInThreading();
	TestInOrderByThreading();
	TestPostThreading();
	system("pause");
	return 0;
}