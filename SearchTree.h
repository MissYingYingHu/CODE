#pragma once

#include<stdio.h>
#include<stdlib.h>

#define TEST_HEADER  printf("\n===================%s=================\n",__FUNCTION__)

typedef char SearchTreeType;

typedef struct SearchTree
{
	SearchTreeType key;
	struct SearchTree* lchild;
	struct SearchTree* rchild;
}SearchTree;

SearchTree *root;

//初始化树
void SearchTreeInit(SearchTree** root);

//打印树：
void PreOrder(SearchTree* root);
void InOrder(SearchTree* root);

//插入节点
void SearchTreeInsert(SearchTree** root,SearchTreeType value);

//查找节点
SearchTree* SearchTreeFind(SearchTree* root,SearchTreeType to_find);

//删除节点
void SearchTreeRemove(SearchTree** root,SearchTreeType value);