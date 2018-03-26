#include"HashTable2.h"
#include<stdio.h>
#include<windows.h>
void PrintHash(HashTable* ht)
{
	HashElem* cur = NULL;
	size_t i = 0;
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
				printf("[%d] key is %d,value is %d.",i,cur->key ,cur->value);
				cur = cur->next ;
			}
			printf("\n");
		}
	}
}

void TESTInit()
{
	size_t i = 0;
	TEST_HEADER;
	HashTableInit(&ht,&func);
	for(;i < HashMaxSize;i++)
	{
		if(ht.data [i] != NULL)
		{
			printf("%d is errror!\n",i);
		}
	}
	printf("size expect is 0,actual is %d.\n",ht.size );
	printf("hash_func expect is %p,actual is %p.\n",func,ht.hash_func );
}
void TESTInsert()
{
	TEST_HEADER;
	HashTableInit(&ht,&func);
	HashInsert(&ht,1,100);
	HashInsert(&ht,2,200);
	HashInsert(&ht,1001,300);
	HashInsert(&ht,1002,400);
	HashInsert(&ht,1001,500);
	PrintHash(&ht);
}
void TESTFind()
{
	int ret = 0;
	int value = 0;
	TEST_HEADER;
	HashTableInit(&ht,&func);
	HashInsert(&ht,1,100);
	HashInsert(&ht,2,200);
	HashInsert(&ht,1001,300);
	HashInsert(&ht,1002,400);
	HashInsert(&ht,1001,500);
	PrintHash(&ht);
	ret = HashFind(&ht,1001,&value);
	printf("ret expect is 1,actual is %d.\n",ret);
	printf("value expect is 300,actual is %d\n",value);
}
void TESTRemove()
{
	TEST_HEADER;
	HashTableInit(&ht,&func);
	HashInsert(&ht,1,100);
	HashInsert(&ht,2,200);
	HashInsert(&ht,1001,300);
	HashInsert(&ht,1002,400);
	HashInsert(&ht,1003,500);
	PrintHash(&ht);
	printf("\n");
	HashRemove(&ht,1001);
	PrintHash(&ht);
	printf("\n");
	HashRemove(&ht,1002);
	PrintHash(&ht);
	printf("\n");
	HashRemove(&ht,1003);
	PrintHash(&ht);

}
void TESTSize()
{
	size_t ret = 0;
	TEST_HEADER;
	HashTableInit(&ht,&func);
	HashInsert(&ht,1,100);
	HashInsert(&ht,2,200);
	HashInsert(&ht,1001,300);
	HashInsert(&ht,1002,400);
	HashInsert(&ht,1003,500);
	PrintHash(&ht);
	ret = HashSize(&ht);
	printf("size is %d\n",ret);
}

void TESTEmpty()
{
	size_t ret = 0;
	TEST_HEADER;
	HashTableInit(&ht,&func);
	HashInsert(&ht,1,100);
	HashInsert(&ht,2,200);
	HashInsert(&ht,1001,300);
	HashInsert(&ht,1002,400);
	HashInsert(&ht,1003,500);
	PrintHash(&ht);
	ret = HashEmpty(&ht);
	printf("expect is 0,actual is %d\n",ret);
}
void TESTDestroy()
{
	size_t i = 0;
	TEST_HEADER;
	HashTableInit(&ht,&func);
	HashInsert(&ht,1,100);
	HashInsert(&ht,2,200);
	HashInsert(&ht,1001,300);
	HashInsert(&ht,1002,400);
	HashInsert(&ht,1003,500);
	PrintHash(&ht);
	HashDestroy(&ht);
	for(;i < HashMaxSize;i++)
	{
		if(ht.data [i] != NULL)
		{
			while(ht.data [i]->next )
			{
				printf("%d is errror!\n",i);
				ht.data [i] = ht.data[i]->next ;
			}
			//printf("%d is errror!\n",i);
		}
	}
	printf("size expect is 0,actual is %d.\n",ht.size );
	printf("hash_func expect is NULL,actual is %p.\n",ht.hash_func );
}
int main()
{
	TESTInit();
	TESTInsert();
	TESTFind();
	TESTRemove();
	TESTSize();
	TESTEmpty();
	TESTDestroy();
	system("pause");
	return 0;
}