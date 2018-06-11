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

//��ʼ����ϣ��
void HashTableInit(HashTable* ht,HashFunc func);

int func(keytype key);

//����(�涨��ϣ���в������ظ���ֵ)
int HashInsert(HashTable* ht,keytype key,valuetype value);

//����
int HashFind(HashTable* ht,keytype key,valuetype* value);

//ɾ��
void HashRemove(HashTable* ht,keytype key);

//���ϣ����Ԫ�صĸ���
size_t HashSize(HashTable* ht);

//�п�
int HashEmpty(HashTable* ht);

//����
void HashDestroy(HashTable* ht);