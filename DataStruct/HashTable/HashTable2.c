#include"HashTable2.h"
#include<stdio.h>
#include<stdlib.h>
int func(keytype key)
{
	return key % HashMaxSize;
}

void HashTableInit(HashTable* ht,HashFunc func)
{
	size_t i = 0;
	ht->size = 0;
	ht->hash_func = func;
	for(;i < HashMaxSize;i++)
	{
		ht->data [i] = NULL;
	}
}
HashElem* CreateNode(keytype key,valuetype value)
{
	HashElem* new_node = (HashElem*)malloc(sizeof(HashElem));
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	return new_node;
}
HashElem* HashBucket(keytype key,size_t offset)
{
	HashElem* cur = ht.data [offset];
	while(cur)
	{
		if(cur->key == key)
		{
			return cur;
		}
		cur = cur->next ;
	}
	return NULL;
}
void HashBucketFindCurAndParent(size_t offset,keytype key,HashElem** cur,HashElem** parent)
{
	(*cur) = ht.data [offset];
	while((*cur)->next != NULL )
	{
		if((*cur)->key == key)
		{
			return ;		
		}
		*parent = *cur;
		(*cur) = (*cur)->next ;
	}
}
int HashInsert(HashTable* ht,keytype key,valuetype value)
{
	size_t offset = 0;
	HashElem* cur = NULL;
	HashElem* new_node = NULL;
	if(ht == NULL)
	{
		return 0;
	}
	//1.找到要插入值的下标
	offset = ht->hash_func (key);
	//2.判断该哈希桶中是否存在该元素
	cur = HashBucket(key,offset);
	if(cur == NULL)
	{
		//3.若不存在，就要插入到哈希表中
		new_node = CreateNode(key,value);
		new_node->next = ht->data [offset];
		ht->data [offset] = new_node;
		++ht->size ;
		return 1;
	}
	else 
	{
		//4.若存在，直接返回，说明已经存在该元素，直接返回即可
		return 0;
	}
	return 0;
}
int HashFind(HashTable* ht,keytype key,valuetype* value)
{
	size_t offset = 0;
	HashElem* cur = NULL;
	if(ht == NULL || value == NULL)
	{
		return 0;
	}
	offset = ht->hash_func (key);
	cur = HashBucket(key,offset);
	if(cur == NULL)
	{
		return 0;
	}
	else
	{
		*value = cur->value ;
		return 1;
	}
	return 0;
}
void DestroyNode(HashElem* deleted)
{
	free(deleted);
}
void HashRemove(HashTable* ht,keytype key)
{
	size_t offset = 0;
	HashElem* cur = NULL;
	HashElem* to_deleted = NULL;
	HashElem* parent = NULL;
	if(ht == NULL)
	{
		return;
	}
	offset = ht->hash_func (key);
	cur = ht->data [offset];
	HashBucketFindCurAndParent(offset,key,&cur,&parent);
	if(cur == NULL )
	{
		//如果返回的当前节点为空，则不存在该节点
		return;
	}
	else if( parent == NULL)
	{
		//如果父节点为空，头结点
		ht->data [offset] = cur->next ;
		cur = NULL;
	}
	else
	{
		//否则说明该哈希桶中不止有一个元素。则运用头删的方法，删除元素
		parent->next = cur->next ;
		cur = NULL;	
	}
	--ht->size ;
	DestroyNode(cur);
}
size_t HashSize(HashTable* ht)
{
	if(ht == NULL)
	{
		return 0;
	}
	return ht->size ;
}
int HashEmpty(HashTable* ht)
{
	if(ht == NULL)
	{
		return 1;
	}
	return ht->size == 0 ? 1 : 0;
}
void HashDestroy(HashTable* ht)
{
	size_t i = 0;
	HashElem* cur = NULL;
	HashElem* deleted = NULL;
	if(ht == NULL)
	{
		return;
	}
	for(;i < HashMaxSize;i++)
	{
		if(ht->data [i] != NULL)
		{
			cur = ht->data [i];
			while(cur)
			{
				deleted = cur;
				cur = cur->next ;
				DestroyNode(deleted);
				
			}
			ht->data [i] = NULL;
		}
	}
	ht->size = 0;
	ht->hash_func = NULL;
}