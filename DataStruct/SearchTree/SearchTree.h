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

//��ʼ����
void SearchTreeInit(SearchTree** root);

//��ӡ����
void PreOrder(SearchTree* root);
void InOrder(SearchTree* root);

//����ڵ�
void SearchTreeInsert(SearchTree** root,SearchTreeType value);

//���ҽڵ�
SearchTree* SearchTreeFind(SearchTree* root,SearchTreeType to_find);

//ɾ���ڵ�
void SearchTreeRemove(SearchTree** root,SearchTreeType value);