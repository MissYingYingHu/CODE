#include"SearchTree.h"
#include<Windows.h>

void TEST_SearchTreeInsert()
{
	TEST_HEADER;
	SearchTreeInit(&root);
	SearchTreeInsert(&root,'f');
	SearchTreeInsert(&root,'e');
	SearchTreeInsert(&root,'a');
	SearchTreeInsert(&root,'g');
	SearchTreeInsert(&root,'w');
	SearchTreeInsert(&root,'c');
	SearchTreeInsert(&root,'k');
	printf("��������Ľ��Ϊ��");
	PreOrder(root);
	printf("\n��������Ľ��Ϊ��");
	InOrder(root);
	printf("\n");
}
void TEST_SearchTreeFind()
{
	SearchTree* ret = NULL;
	TEST_HEADER;
	SearchTreeInit(&root);
	SearchTreeInsert(&root,'f');
	SearchTreeInsert(&root,'e');
	SearchTreeInsert(&root,'a');
	SearchTreeInsert(&root,'g');
	SearchTreeInsert(&root,'w');
	SearchTreeInsert(&root,'c');
	SearchTreeInsert(&root,'k');
	ret = SearchTreeFind(root,'e');
	printf("expect is %p,actual is %p\n",root->lchild ,ret);
}
void TEST_SearchTreeRemove()
{
	TEST_HEADER;
	SearchTreeInit(&root);
	SearchTreeInsert(&root,'f');
	SearchTreeInsert(&root,'e');
	SearchTreeInsert(&root,'a');
	SearchTreeInsert(&root,'g');
	SearchTreeInsert(&root,'w');
	SearchTreeInsert(&root,'c');
	SearchTreeInsert(&root,'k');
	SearchTreeInsert(&root,'z');
	printf("��������Ľ��Ϊ��");
	PreOrder(root);
	printf("\n��������Ľ��Ϊ��");
	InOrder(root);
	printf("\n");
	SearchTreeRemove(&root,'g');
	printf("��������Ľ��Ϊ��");
	PreOrder(root);
	printf("\n��������Ľ��Ϊ��");
	InOrder(root);
	printf("\n");
	SearchTreeRemove(&root,'e');
	printf("��������Ľ��Ϊ��");
	PreOrder(root);
	printf("\n��������Ľ��Ϊ��");
	InOrder(root);
	printf("\n");
}
int main()
{
	TEST_SearchTreeInsert();
	TEST_SearchTreeFind();
	TEST_SearchTreeRemove();
	system("pause");
	return 0;
}