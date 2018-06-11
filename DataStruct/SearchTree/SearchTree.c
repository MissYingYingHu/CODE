#include"SearchTree.h"


void SearchTreeInit(SearchTree** root)
{
	if(root == NULL)
	{
		return;
	}
	*root = NULL;
	return;
}
void PreOrder(SearchTree* root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%c ",root->key );
	PreOrder(root->lchild );
	PreOrder(root->rchild );
}
void InOrder(SearchTree* root)
{
	if(root == NULL)
	{
		return;
	}
	InOrder(root->lchild );
	printf("%c ",root->key );
	InOrder(root->rchild );
}
SearchTree* CreateSearchTreeNode(SearchTreeType value)
{
	SearchTree* new_node = (SearchTree*)malloc(sizeof(SearchTree));
	new_node->key = value;
	new_node->lchild = NULL;
	new_node->rchild = NULL;
	return new_node;
}
void DestroyNode(SearchTree* ptr)
{
	free(ptr);
}

void SearchTreeInsert(SearchTree** root,SearchTreeType value)
{
	SearchTree* new_node = (*root);
	SearchTree* parent = NULL;
	if(root == NULL)
	{
		return;
	}
	if(*root == NULL)
	{
		*root = CreateSearchTreeNode(value);
		return;
	}
	while(new_node)
	{
		//1.�ҵ��½ڵ���Ҫ�����λ��,����¼��Ҫ����ڵ�ĸ�ĸ�ڵ�
		if(new_node->key > value)
		{
			parent = new_node;
			new_node = new_node->lchild ;
		}
		else if(new_node->key < value)
		{
			parent = new_node;
			new_node = new_node->rchild ;
		}
		else
		{
			//���Ҫ����Ľڵ���ԭ�������д��ڣ���ֱ�ӷ���
			return;
		}
	}
	if(parent == (*root))
	{
		if(parent->lchild == new_node)
		{
			parent->lchild = CreateSearchTreeNode(value);
			return;
		}
		else if(parent->rchild == new_node)
		{
			parent->rchild = CreateSearchTreeNode(value);
			return;
		}
	}
	if(parent->key > value)
	{
		parent->lchild = CreateSearchTreeNode(value);
		return;
	}
	else if(parent->key < value)
	{
		parent->rchild = CreateSearchTreeNode(value);
		return;
	}
	return;
}
SearchTree* SearchTreeFind(SearchTree* root,SearchTreeType to_find)
{
	SearchTree* cur = root;
	if(root == NULL)
	{
		//����
		return NULL;
	}
	while(cur)
	{
		if(cur->key < to_find)
		{
			cur = cur->rchild ;
		}
		else if(cur->key > to_find)
		{
			cur = cur->lchild ;
		}
		else
		{
			return cur;
		}
	}
	return NULL;
}
void SearchTreeRemove(SearchTree** root,SearchTreeType value)
{
	SearchTree* cur = *root;
	SearchTree* parent = NULL;
	SearchTree* min = NULL;
	if(root == NULL)
	{
		//�Ƿ�����
		return;
	}
	if(*root == NULL)
	{
		//����
		return;
	}
	//1.��Ҫ�ҵ���Ҫɾ�����Ǹ��ڵ㣬����¼���ĸ�ĸ�ڵ�
	while(cur)
	{
		if(cur->key < value)
		{
			parent = cur;
			cur = cur->rchild ;
		}
		else if(cur->key > value)
		{
			parent = cur;
			cur = cur->lchild; 
		}
		else
		{
			break;
		}
	}
	if(cur == NULL)
	{
		//�Ҳ���
		return;
	}
	//2.����������ۣ�
	if(cur->lchild == NULL && cur->rchild == NULL)
	{
		//a.���Ҫɾ���Ľڵ���Ҷ�ӽڵ㣬��û�����ҽڵ�
		if(parent->lchild == cur)
		{
			parent->lchild = NULL;
		}
		else
		{
			parent->rchild = NULL;
		}
		DestroyNode(cur);
		return;
	}
	else if(cur->rchild != NULL && cur->lchild == NULL)
	{
		//b.���ֻ���ҽڵ�û����ڵ㣬ɾ���ڵ�󣬾�Ҫ�Ѹýڵ��������ȫ�������ƶ�
		if(parent->lchild == cur)
		{
			parent->lchild = cur->rchild ;
			cur = NULL;
		}
		else
		{
			parent->rchild = cur->rchild ;
			cur = NULL;
		}
		DestroyNode(cur);
		return;
	}
	else if(cur->lchild != NULL && cur->rchild == NULL)
	{
		//c.���ֻ����ڵ�û���ҽڵ㣬ɾ���ڵ�󣬾�Ҫ�Ѹýڵ��������ȫ�������ƶ�
		if(parent->lchild == cur)
		{
			parent->lchild = cur->lchild ;
			cur = NULL;
		}
		else
		{
			parent->rchild = cur->lchild ;
			cur = NULL;
		}
		DestroyNode(cur);
		return;
	}
	else if(cur->lchild != NULL && cur->rchild != NULL )
	{
		//d.������ҽڵ㶼�У���Ҫ�����������ҵ���С�Ľڵ㣬����С�Ľڵ㸳ֵ��Ҫɾ���Ľڵ㣬Ȼ��ɾ����С�Ľڵ�
		min = cur->rchild ;
		while(min->lchild )
		{
			if(min->lchild ->key < cur->key )
			{
				parent = min;
				min = min->lchild ;
			}
		}
		if(parent == NULL)
		{
			cur ->key = min->key ;
			cur->rchild = NULL;
		}
		else
		{
			cur ->key = min->key ;
			parent->lchild = NULL;
		}
		DestroyNode(min);
		return;
	}
}
//void SearchTreeInsert(SearchTree** root,SearchTreeType value)
//{
//	if(root == NULL)
//	{
//		return;
//	}
//	if(*root == NULL)
//	{
//		*root = CreateSearchTreeNode(value);
//		return;
//	}
//	if((*root)->key < value)
//	{
//		SearchTreeInsert(&(*root)->rchild,value);
//	}
//	else if((*root)->key > value)
//	{
//		SearchTreeInsert(&(*root)->lchild,value);
//	}
//	else
//	{
//		return;
//	}
//}
//SearchTree* SearchTreeFind(SearchTree* root,SearchTreeType to_find)
//{
//	if(root == NULL)
//	{
//		return NULL;
//	}
//	if(root->key > to_find)
//	{
//		return SearchTreeFind(root->lchild ,to_find);
//	}
//	else if(root->key < to_find)
//	{
//		return SearchTreeFind(root->rchild ,to_find);
//	}
//	return root;
//}
//void SearchTreeRemove(SearchTree** root,SearchTreeType value)
//{
//	SearchTree* deleted = (*root);
//	SearchTree* min = NULL;
//	if(root == NULL)
//	{
//		return;
//	}
//	if((*root) ->key < value)
//	{
//		SearchTreeRemove(&(*root)->rchild ,value);
//		return;
//	}
//	if((*root) ->key > value)
//	{
//		SearchTreeRemove(&(*root)->lchild ,value);
//		return;
//	}
//	if((*root)->lchild == NULL && (*root)->rchild == NULL)
//	{
//		(*root) = NULL;
//		DestroyNode(*root);
//		return;
//	}
//	else if((*root)->lchild != NULL && (*root)->rchild == NULL)
//	{
//		(*root) = (*root)->lchild ;
//		deleted = NULL;
//		DestroyNode(deleted);
//		return;
//	}
//	else if((*root)->rchild != NULL && (*root)->lchild == NULL)
//	{
//		(*root) = (*root)->rchild ;
//		(deleted) = NULL;
//		DestroyNode(deleted);
//		return;
//	}
//	else if((*root)->rchild != NULL && (*root)->lchild != NULL)
//	{
//		min = (*root)->rchild ;
//		while(min->lchild )
//		{
//			min = min->lchild ;
//		}
//		(*root)->key = min->key ;
//		SearchTreeRemove(&min,min->key );
//		return;
//	}
//}