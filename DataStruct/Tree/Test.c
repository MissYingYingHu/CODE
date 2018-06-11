#include<stdio.h>
#include<string.h>
#include<windows.h>
#include"Tree.h"
#include"seqstack.h"
#include"seqqueue.h"
void TEST_PreOrder()
{
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("先序遍历结果：");
	PreOrder(root);
	printf("\n");
}
void TEST_InOrder()
{
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("中序遍历结果：");
	InOrder(root);
	printf("\n");
}
void TEST_PostOrder()
{
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("后序遍历结果：");
	PostOrder(root);
	printf("\n");
}
void TEST_LevelOrder()
{
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	LevelOrder(root);
	printf("\n");
}
void TEST_Tree()
{
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TreeNode* root = NULL;
	TEST_Header;
	TreeInit(&root);
	root = TreeCreate(arr,strlen(arr),'*');
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
}
void TEST_TreeDestroy()
{
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TreeNode* root = NULL;
	TEST_Header;
	TreeInit(&root);
	root = TreeCreate(arr,strlen(arr),'*');
	printf("先序遍历结果：");
	PreOrder(root);
	TreeDestroy(&root);
	PreOrder(root);
	printf("\n");
}
void TEST_TreeClone()
{
	TreeNode* ret = NULL;
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TreeNode* root = NULL;
	TEST_Header;
	TreeInit(&root);
	root = TreeCreate(arr,strlen(arr),'*');
	printf("结果：");
	ret = TreeClone(root);
	printf("%c ",ret->data );
}
void TEST_TreeSize()
{
	int ret = 0;
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("先序遍历结果：");
	PreOrder(root);
	printf("\n");
	ret = TreeSize(root);
	printf("expect is 7,actual is %d\n",ret);
}
void TEST_TreeLeafSize()
{
	int ret = 0;
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("先序遍历结果：");
	PreOrder(root);
	printf("\n");
	ret = TreeLeafSize(root);
	printf("expect is 3,actual is %d\n",ret);
}
void TEST_TreeKLevelSize()
{
	int ret = 0;
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("先序遍历结果：");
	PreOrder(root);
	printf("\n");
	ret = TreeKLevelSize(root,3);
	printf("%d\n",ret);
}
void TEST_TreeHeight()
{
	int ret = 0;
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("先序遍历结果：");
	PreOrder(root);
	printf("\n");
	ret = TreeHeight(root);
	printf("%d\n",ret);
}
void TEST_TreeFind()
{
	TreeNode* ret = NULL;
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TreeNode* root = NULL;
	TEST_Header;
	TreeInit(&root);
	root = TreeCreate(arr,strlen(arr),'*');
	printf("先序遍历结果：");
	PreOrder(root);
	ret = TreeFind(root,'F');
	printf("\n%p,%c\n",ret,ret->data );
}
void TEST_LChild()
{
	TreeNode* ret = NULL;
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("先序遍历结果：");
	PreOrder(root);
	ret = LChild(e);
	printf("\n%p ,%c",ret,ret->data );
}
void TEST_RChild()
{
	TreeNode* ret = NULL;
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("先序遍历结果：");
	PreOrder(root);
	ret = RChild(c);
	printf("\n%p ,%c\n",ret,ret->data );
}
void TEST_Parent()
{
	TreeNode* ret = NULL;
	TreeNode* a = CreateNode('A');
	TreeNode* b = CreateNode('B');
	TreeNode* c = CreateNode('C');
	TreeNode* d = CreateNode('D');
	TreeNode* e = CreateNode('E');
	TreeNode* f = CreateNode('F');
	TreeNode* g = CreateNode('G');
	TEST_Header;
	TreeInit(&root);
	a->lchild = b;
	a->rchild = c;
	b->lchild = d;
	b->rchild = e;
	e->lchild = g;
	c->rchild = f;
	root = a;
	printf("先序遍历结果：");
	PreOrder(root);
	ret = Parent(root,a);
	printf("\n%p,%c\n",ret,ret->data );
}
void TEST_PreOrderByLoop()
{
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TreeNode* root = NULL;
	TEST_Header;
	TreeInit(&root);
	root = TreeCreate(arr,strlen(arr),'*');
	PreOrderByLoop(root);
}
void TEST_InOrderByLoop()
{
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TreeNode* root = NULL;
	TEST_Header;
	TreeInit(&root);
	root = TreeCreate(arr,strlen(arr),'*');
	InOrderByLoop(root);
}
void TEST_PostOrderByLoop()
{
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TreeNode* root = NULL;
	TEST_Header;
	TreeInit(&root);
	root = TreeCreate(arr,strlen(arr),'*');
	PostOrderByLoop(root);
}
void TEST_TreeMirror()
{
	TreeNodeType arr[] = "ABD**EG***C*F**";
	TreeNode* root = NULL;
	TEST_Header;
	TreeInit(&root);
	root = TreeCreate(arr,strlen(arr),'*');
	TreeMirror(root);
	LevelOrder(root);
}
void TEST_IsCompleteTree()
{
	int ret = 0;
	TreeNodeType arr[] = "ABC*E**G**D**";
	TreeNode* root = NULL;
	TEST_Header;
	TreeInit(&root);
	root = TreeCreate(arr,strlen(arr),'*');
	ret = IsCompleteTree(root);
	printf("ret expect is 1,actual is %d\n",ret);
}
void TEST_ReBuildTree()
{
	TreeNodeType pre_order[] = "abdegcf";
	TreeNodeType in_order[] = "dbgeacf";
	TEST_Header;
	ReBuildTree(pre_order,strlen(pre_order),in_order,strlen(in_order));
	printf("先序：");
	PreOrder(root);
	printf("\n");
	printf("中序：");
	InOrder(root);
	printf("\n");
}
////////////////////////test///////////////////////////
int main()
{
	TEST_PreOrder();
	TEST_InOrder();
	TEST_PostOrder();
	TEST_LevelOrder();
	TEST_Tree();
	TEST_TreeDestroy();
	TEST_TreeClone();
	TEST_TreeSize();
	TEST_TreeLeafSize();
	TEST_TreeKLevelSize();
	TEST_TreeHeight();
	TEST_TreeFind();
	TEST_LChild();
	TEST_RChild();
	TEST_PreOrderByLoop();
	TEST_InOrderByLoop();
	TEST_PostOrderByLoop();
	TEST_TreeMirror();
	TEST_IsCompleteTree();
	TEST_ReBuildTree();
	system("pause");
	return 0;
}
