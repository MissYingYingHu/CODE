#pragma once
#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef enum flag   //为了区别是子树还是线索
{
	Child,
	Thread,
}flag;

typedef char TreeNodeType;

typedef struct ThreadNode
{
	TreeNodeType data;
	struct ThreadNode* left;
	struct ThreadNode* right;
	flag lflag;
	flag rflag;
}ThreadNode;

ThreadNode* ThreadTreeCreate(TreeNodeType arr[], size_t size, TreeNodeType invalid); 

void PreThreading(ThreadNode* root); 

void PreOrderByThreading(ThreadNode* root); 

void InThreading(ThreadNode* root); 

void InOrderByThreading(ThreadNode* root); 

void PostThreading(ThreadNode* root); 


//转化为双向链表
typedef struct TreeNode
{
	char data;
	struct TreeNode* left;
	struct TreeNode* right;
	struct TreeNode* next;
	struct TreeNode* prev;
}TreeNode;
void PreOrderConvertToList(TreeNode* root);