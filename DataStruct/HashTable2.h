#pragma once
#include<stddef.h>
#define HashMaxSize 1000
#define TEST_HEADER printf("\n==================%s==================\n",__FUNCTION__)
typedef int keytype;
typedef int valuetype;
typedef int (*HashFunc)(keytype key);
typedef struct HashElem
{
	keytype key;
	valuetype value;
	struct HashElem* next;
}HashElem;
typedef struct HashTable
{
	HashElem* data[HashMaxSize];
	size_t size;
	HashFunc hash_func;
}HashTable;
HashTable ht;

//初始化哈希表
void HashTableInit(HashTable* ht,HashFunc func);

int func(keytype key);

//插入(规定哈希表中不能有重复的值)
int HashInsert(HashTable* ht,keytype key,valuetype value);

//查找
int HashFind(HashTable* ht,keytype key,valuetype* value);

//删除
void HashRemove(HashTable* ht,keytype key);

//求哈希表中元素的个数
size_t HashSize(HashTable* ht);

//判空
int HashEmpty(HashTable* ht);

//销毁
void HashDestroy(HashTable* ht);