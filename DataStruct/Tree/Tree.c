#include"Tree.h"
#include"seqstack.h"
#include"seqstack.c"
#include"seqqueue.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void TreeInit(TreeNode** root)
{
	if(root == NULL)
	{
		return;
	}
	*root = NULL;
}
TreeNode* CreateNode(TreeNodeType value)
{
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = value;
	node->lchild = NULL;
	node->rchild = NULL;
	return node;
}
void PreOrder(TreeNode* root)
{
	if(root == NULL)
	{
		//printf("*");
		return;
	}
	printf("%c ",root->data );
	PreOrder(root->lchild );
	PreOrder(root->rchild );
}
void InOrder(TreeNode* root)
{
	if(root == NULL)
	{
		return;
	}
	InOrder(root->lchild );
	printf("%c ",root->data );
	InOrder(root->rchild );
}
void PostOrder(TreeNode* root)
{
	if(root == NULL)
	{
		return;
	}
	PostOrder(root->lchild );
	PostOrder(root->rchild );
	printf("%c ",root->data ); 
}
void LevelOrder(TreeNode* root)
{
	TreeNode* top = NULL;
	SeqQueue q;
	if(root == NULL)
	{
		return;
	}
	SeqQueueInit(&q);
	//1.先把根节点插入队列
	SeqQueuePush(&q,root);
	while(SeqQueueTop(&q,&top))
	{
		//2.循环的取队首元素
		//3.访问队首元素并出队列
		printf("%c ",top->data );
		SeqQueuePop(&q);
		//4.将队首元素的左子树和右子树节点都依次入队列
		if(top->lchild != NULL)
		{
			SeqQueuePush(&q,top->lchild );
		}
		if(top->rchild != NULL)
		{
			SeqQueuePush(&q,top->rchild );
		}
		//5.进入下一次循环，直到队列为空，说明遍历完了。
	}
}
TreeNode* _TreeCreate(TreeNodeType arr[],int size,int* index,TreeNodeType null_node)
{
	TreeNode* new_node = NULL;
	if(index == NULL)
	{
		//非法输入
		return NULL;
	}
	if((*index) >= size)
	{
		//构建完成
		return NULL;
	}
	if(arr[*index] == null_node)
	{
		return NULL;
	}
	new_node = CreateNode(arr[*index]);
	++(*index);
	new_node->lchild = _TreeCreate(arr,size,index,null_node);
	++(*index);
	new_node->rchild = _TreeCreate(arr,size,index,null_node);
	return new_node;
}
TreeNode* TreeCreate(TreeNodeType arr[], int size, TreeNodeType null_node)
{
	int index = 0;
	return _TreeCreate(arr,size,&index,null_node);
}
void DestroyNode(TreeNode* deleted)
{
	free(deleted);
}
void TreeDestroy(TreeNode** root)
{
	if(root == NULL)
	{
		return;
	}
	if(*root == NULL)
	{
		return;
	}
	DestroyNode((*root)->lchild );
	DestroyNode((*root)->rchild );
	DestroyNode(*root);
	*root = NULL;
}
TreeNode* TreeClone(TreeNode* root)
{
	TreeNode* new_node = root;
	if(root == NULL)
	{
		return NULL;
	}
	new_node->lchild = TreeClone(root->lchild );
	new_node->rchild = TreeClone(root->rchild );
	return new_node;
}
int TreeSize(TreeNode* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return 1 + TreeSize(root->lchild ) + TreeSize(root->rchild );
}
int TreeLeafSize(TreeNode* root)
{
	if(root == NULL)
	{
		return 0;
	}
	if(root->lchild == NULL && root->rchild == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->lchild ) + TreeLeafSize(root->rchild );
}
int TreeKLevelSize(TreeNode* root, int K)
{
	if(root == NULL || K < 1)
	{
		return 0;
	}
	if(K == 1)
	{
		return 1;
	}
	return TreeKLevelSize(root->lchild , K-1) + TreeKLevelSize(root->rchild ,K-1);
}
int TreeHeight(TreeNode* root)
{
	if(root == NULL)
	{
		return 0;
	}
	return TreeHeight(root->lchild ) > TreeHeight(root->rchild ) ? TreeHeight(root->lchild )+1 : TreeHeight(root->rchild )+1;
}
TreeNode* TreeFind(TreeNode* root, TreeNodeType to_find)              //wenti
{
	TreeNode* ret = NULL;
	if(root == NULL)
	{
		return NULL;
	}
	if(root->data == to_find)
	{
		return root;
	}
	ret = TreeFind(root->lchild,to_find);
	if(ret)
	{
		return ret;
	}
	return TreeFind(root->rchild ,to_find);
}
TreeNode* LChild(TreeNode* node)
{
	if(node == NULL)
	{
		return NULL;
	}
	return node->lchild ;
}
TreeNode* RChild(TreeNode* node)
{
	if(node == NULL)
	{
		return NULL;
	}
	return node->rchild ;
}
TreeNode* Parent(TreeNode* root, TreeNode* node)
{
	TreeNode* lresult = NULL;
	TreeNode* rresult = NULL;
	if(root == NULL)
	{
		return NULL;
	}
	if(root->lchild == node || root->rchild == node)
	{
		return root;
	}

	lresult = Parent(root->lchild ,node);
	rresult = Parent(root->rchild ,node);
	return lresult != NULL ? lresult : rresult;
}
void PreOrderByLoop(TreeNode* root)
{
	TreeNode* value = NULL;
	seqstack stack;
	if(root == NULL)
	{
		return;
	}
	InitStack(&stack);
	PushStack(&stack,root);
	while(1)
	{
		TopStack(&stack,&value);
		if(TopStack(&stack,&value) == 0)
		{
			//遍历完成了
			break;
		}
		printf("%c ",value->data );
		PopStack(&stack);
		//把当前元素的右子树和左子树分别入栈
		if(value->rchild != NULL)
		{
			PushStack(&stack,value->rchild );
		}
		if(value->lchild != NULL)
		{
			PushStack(&stack,value->lchild );
		}
	}
	printf("\n");
}

void InOrderByLoop(TreeNode* root)
{
	seqstack stack;
	TreeNode* value = NULL;
	TreeNode* cur = NULL;
	if(root == NULL)
	{
		return;
	}
	InitStack(&stack);
	cur = root;
	while(1)
	{
		while(cur != NULL)
		{
			PushStack(&stack,cur);
			cur = cur->lchild ;
		}
		TopStack(&stack,&value);
		if(TopStack(&stack,&value) == 0)
		{
			break;
		}
		printf("%c ",value->data );
		PopStack(&stack);
		cur = value->rchild ;
	}
}
void PostOrderByLoop(TreeNode* root)
{
	seqstack stack;
	TreeNode* value = NULL;
	TreeNode* cur = NULL;
	TreeNode* pre = NULL;
	if(root == NULL)
	{
		return;
	}
	InitStack(&stack);
	cur = root;
	while(1)
	{
		while(cur != NULL)
		{
			PushStack(&stack,cur);
			cur = cur->lchild ;
		}
		TopStack(&stack,&value);
		if(TopStack(&stack,&value) == 0)
		{
			break;
		}
		if(value->rchild == NULL || value->rchild == pre)
		{
			//栈顶元素的右子树为空或者右子树已经访问过
			printf("%c ",value->data );
			PopStack(&stack);
			pre = value;
		}
		else
		{
			cur = value->rchild ;
		}
	}
}
void TreeMirror(TreeNode* root)
{
	TreeNode* tmp = NULL;
	if(root == NULL)
	{
		return;
	}
	tmp = root->lchild ;
	root->lchild = root->rchild ;
	root->rchild = tmp;
	TreeMirror(root->lchild );
	TreeMirror(root->rchild );
}
int IsCompleteTree(TreeNode* root)
{
	//空树也是完全二叉树
	int flag = 0;   //判断当前进入哪个阶段
	TreeNode* cur = NULL;
	SeqQueue q;
	if(root == NULL)
	{
		return 0;
	}
	SeqQueueInit(&q);
	SeqQueuePush(&q,root);
	while(1)
	{
		SeqQueueTop(&q,&cur);
		if(cur == NULL)
		{
			break;
		}
		//访问当前节点

		if(cur->lchild != NULL && cur->rchild != NULL)
		{
			SeqQueuePush(&q,cur->lchild );
			SeqQueuePush(&q,cur->rchild );
			flag = 0;
		}
		else if(cur->lchild == NULL && cur->rchild != NULL)
		{
			return 0;
		}
		else if(cur->lchild != NULL && cur->rchild == NULL)
		{
			SeqQueuePush(&q,cur->lchild );
			flag = 1;
		}
		else if(cur->lchild == NULL && cur->rchild == NULL)
		{
			flag = 1;
		}
		if(flag == 1)
		{
			if(cur->lchild == NULL && cur->rchild == NULL)
			{
				//两个都为空，说明目前为止，还满足完全二叉树的条件	
				return 1;
			}
			if(cur->lchild || cur->rchild )
			{
				return 0;
			}
		}
		SeqQueuePop(&q);
	}
	return 1;
}
size_t Find(TreeNodeType arr[],size_t left,size_t right,TreeNodeType to_find)
{
	size_t i = left;
	for(;i < right;i++)
	{
		if(arr[i] = to_find)
		{
			return i;
		}
	}
	return (size_t)-1;
}
TreeNode* _ReBuildTree(TreeNodeType pre_order[],size_t pre_order_size,size_t* index,
					TreeNodeType in_order[],size_t in_order_left,size_t in_order_right)
{
	TreeNode* new_node = NULL;
	size_t cur_root_in_order_index = 0;
	if(in_order_left >= in_order_right)
	{
		//区间为空
		return NULL;
	}
	if(*index >= pre_order_size || index != NULL)
	{
		//先序遍历结束了，树也就还原完成
		return NULL;
	}
	new_node = CreateNode(pre_order[*index]);
	cur_root_in_order_index = Find(in_order,in_order_left,in_order_right,pre_order[*index]);
	assert(cur_root_in_order_index != (size_t)-1);
	++(*index);
	new_node->lchild  = _ReBuildTree(pre_order,pre_order_size,index,in_order,
					in_order_left,cur_root_in_order_index);
	new_node->rchild  = _ReBuildTree(pre_order,pre_order_size,index,in_order,
					cur_root_in_order_index,in_order_right);
	return new_node;
}
//通过树的先序和中序还原一棵树
TreeNode* ReBuildTree(TreeNodeType pre_order[],size_t pre_order_size,TreeNodeType in_order[],size_t in_order_size)
{
	size_t index = 0;
	_ReBuildTree(pre_order,pre_order_size,&index,in_order,0,in_order_size);
}
