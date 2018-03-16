#include"BitMap.h"
#include<stdio.h>
#include<windows.h>
void TestInit()
{
	TEST_HEADER;
	BitMapInit(&bm,65);
	printf("capacity expect is 2,actual is %d\n",bm.capacity );
	printf(" %p \n",bm.data );
}
void TestSet()
{
	size_t i = 0;
	TEST_HEADER;
	BitMapInit(&bm,65);
	BitMapSet(&bm,64);
	BitMapSet(&bm,65);
	for(;i < bm.capacity ;i++)
	{
		printf("[%d],%d  ",i,bm.data[i] );
	}
}
void TestUnSet()
{
	size_t i = 0;
	TEST_HEADER;
	BitMapInit(&bm,65);
	BitMapSet(&bm,64);
	BitMapUnSet(&bm,64);
	for(;i < bm.capacity ;i++)
	{
		printf("[%d],%d  ",i,bm.data[i] );
	}
}
void Test()
{
	int ret = 0,ret2 = 0;
	TEST_HEADER;
	BitMapInit(&bm,65);
	BitMapSet(&bm,62);
	//BitMapSet(&bm,68);
	//BitMapUnSet(&bm,64);
	ret = BitMapTest(&bm,62);
	printf("ret expect is 1,actual is %d\n",ret);
	BitMapUnSet(&bm,62);
	ret2 = BitMapTest(&bm,62);
	printf("ret expect is 0,actual is %d\n",ret2);
}
void TestFill()
{
	size_t i = 0;
	TEST_HEADER;
	BitMapInit(&bm,65);
	BitMapFill(&bm);
	for(;i < bm.capacity ;i++)
	{
		printf("[%d],%x  ",i,bm.data[i] );
	}
}
void TestUnFill()
{
	size_t i = 0;
	TEST_HEADER;
	BitMapInit(&bm,65);
	BitMapUnFill(&bm);
	for(;i < bm.capacity ;i++)
	{
		printf("[%d],%x  ",i,bm.data[i] );
	}
}
void TestDestroy()
{
	TEST_HEADER;
	BitMapInit(&bm,65);
	BitMapDestroy(&bm);
	printf("capacity:[%d],bm->data:[%p]\n",bm.capacity ,bm.data );
}
////////////////////////////////////////////////
int main()
{
	TestInit();
	TestSet();
	TestUnSet();
	Test();
	TestFill();
	TestUnFill();
	TestDestroy();
	system("pause");
	return 0;
}