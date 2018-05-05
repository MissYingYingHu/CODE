
#include"Thread.h"

//invalid ��ʾ�սڵ�
ThreadNode* CreateThreadNode(TreeNodeType value)
{
	ThreadNode* new_node = (ThreadNode*)malloc(sizeof(ThreadNode));
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->lflag = Child;
	new_node->rflag = Child;
	return new_node;
}
ThreadNode*  _ThreadTreeCreate(TreeNodeType arr[],size_t size,size_t* index,TreeNodeType invalid)
{
	ThreadNode* new_node = NULL;
	if(index == NULL || *index >= size)
	{
		return NULL;
	}
	if(arr[*index] == invalid)
	{
		return NULL;
	}
	new_node = CreateThreadNode(arr[*index]);
	++(*index);
	new_node->left = _ThreadTreeCreate(arr,size,index,invalid);
	++(*index);
	new_node->right = _ThreadTreeCreate(arr,size,index,invalid);
	return new_node;
}
ThreadNode* ThreadTreeCreate(TreeNodeType arr[], size_t size, TreeNodeType invalid)
{
	size_t index = 0;
	return _ThreadTreeCreate(arr,size,&index,invalid);
}
void _PreThreading(ThreadNode *root,ThreadNode** prev)
{
	if(root == NULL || prev == NULL)
	{
		return;
	}
	//1.��������ĸ��ڵ��������Ϊ�գ��ͰѸ��ڵ�������ָ��ǰ���ڵ�
	//2.��������ĸ��ڵ��������Ϊ�գ��ͰѸ��ڵ��������ָ����ڵ�
	if(root->left == NULL)
	{
		root->left = (*prev);
		root->lflag = Thread;
	}
	if(*prev != NULL && (*prev)->right == NULL)
	{
		(*prev)->right = root;
		(*prev)->rflag = Thread;
	}
	(*prev) = root;
	if(root->lflag == Child)
	{
		_PreThreading(root->left ,prev);
	}
	if(root->rflag == Child)
	{
		_PreThreading(root->right ,prev);
	}
	return;
}
void PreThreading(ThreadNode* root)
{
	ThreadNode* prev = NULL; //����ǰһ���ڵ�
	if(root == NULL)
	{
		return;
	}
	_PreThreading(root,&prev);
}
void PreOrderByThreading(ThreadNode* root)
{
	ThreadNode* cur = root;
	if(root == NULL)
	{
		return;
	}
	while(cur != NULL)
	{
		while(cur->lflag == Child)
		{
			printf("%c ",cur->data );
			cur = cur->left ;
		}
		printf("%c ",cur->data );
		cur = cur->right ;
	}
}
void _InThreadNode(ThreadNode* root,ThreadNode** prev)
{
	if(root == NULL || prev == NULL)
	{
		return;
	}
	if(root->lflag == Child)
	{
		_InThreadNode(root->left ,prev);
	}
	if(root->left == NULL)
	{
		root->left = (*prev);
		root->lflag = Thread;
	}
	if((*prev) != NULL && (*prev)->right == NULL)
	{
		(*prev)->right = root;
		(*prev)->rflag = Thread;
	}
	(*prev) = root;
	if(root->rflag == Child)
	{
		_InThreadNode(root->right ,prev);
	}
}
void InThreading(ThreadNode* root)
{
	ThreadNode* prev = NULL;
	if(root == NULL)
	{
		return;
	}
	_InThreadNode(root,&prev);
}
void InOrderByThreading(ThreadNode* root)
{
	ThreadNode* cur = NULL;
	if(root == NULL)
	{
		return;
	}
	cur = root;
	//1.�ҵ�������Ԫ��
	while(cur != NULL && cur->lflag == Child)
	{
		cur = cur->left ;
	}
	while(cur != NULL)
	{
		printf("%c ",cur->data );
		if(cur->rflag == Thread)
		{
			//2.�����ǰ�ڵ��������������������������ָ��������
			cur = cur->right ;
		}
		else
		{
			//3.���򣬾Ͱѵ�ǰԪ��ָ��������������Ѱ�Ҹýڵ������Ľڵ�
			cur = cur->right ;
			while(cur != NULL && cur->lflag == Child)
			{
				cur = cur->left ;
			}
		}
	}
}
void _PostThreading(ThreadNode* root,ThreadNode** prev)
{
	if(root == NULL || prev == NULL)
	{
		return;
	}
	//1.����������
	if(root->lflag == Child)
	{
		_PostThreading(root->left ,prev);
	}
	//2.����������
	if(root->rflag == Child)
	{
		_PostThreading(root->right ,prev);
	}	
	//3.������ڵ�
	if(root->left == NULL)
	{
		root->left = (*prev);
		root->lflag = Thread;
	}
	if(*prev != NULL && (*prev)->right == NULL)
	{
		(*prev)->right = root;
		(*prev)->rflag = Thread;
	}
	(*prev) = root;
}
void PostThreading(ThreadNode* root)
{
	ThreadNode* prev = NULL;
	if(root == NULL)
	{
		return;
	}
	_PostThreading(root,&prev);
}

void _PreOrderConvertToList(TreeNode* root,TreeNode** prev)
{
	if(root== NULL || prev == NULL)
	{
		return;
	}
	//������ڵ�
	root->prev = (*prev);
	if((*prev) != NULL)
	{
		(*prev)->next = root;
	}
	//����������
	_PreOrderConvertToList(root->left ,prev);
	//����������
	_PreOrderConvertToList(root->right ,prev);
}
void PreOrderConvertToList(TreeNode* root)
{
	TreeNode* prev = NULL;
	if(root == NULL)
	{
		return;
	}
	_PreOrderConvertToList(root,&prev);
}