
#include"Thread.h"

//invalid 表示空节点
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
	//1.如果子树的根节点的左子树为空，就把根节点左子树指向前驱节点
	//2.如果子树的根节点的右子树为空，就把根节点的右子树指向根节点
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
	ThreadNode* prev = NULL; //保存前一个节点
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
	//1.找到最左侧的元素
	while(cur != NULL && cur->lflag == Child)
	{
		cur = cur->left ;
	}
	while(cur != NULL)
	{
		printf("%c ",cur->data );
		if(cur->rflag == Thread)
		{
			//2.如果当前节点的右子树是线索，就让右子树指向右子树
			cur = cur->right ;
		}
		else
		{
			//3.否则，就把当前元素指向右子树，遍历寻找该节点最左侧的节点
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
	//1.处理左子树
	if(root->lflag == Child)
	{
		_PostThreading(root->left ,prev);
	}
	//2.处理右子树
	if(root->rflag == Child)
	{
		_PostThreading(root->right ,prev);
	}	
	//3.处理根节点
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
	//处理根节点
	root->prev = (*prev);
	if((*prev) != NULL)
	{
		(*prev)->next = root;
	}
	//处理左子树
	_PreOrderConvertToList(root->left ,prev);
	//处理右子树
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