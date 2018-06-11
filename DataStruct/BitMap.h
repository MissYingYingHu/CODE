#pragma once
#include<stddef.h>

#define TEST_HEADER printf("\n==================%s=================\n",__FUNCTION__)
typedef unsigned _int64 uint64_t;
typedef struct BitMap
{
	uint64_t* data;
	size_t capacity;
}BitMap;

BitMap bm;

//初始化位图
void BitMapInit(BitMap* bm,size_t capacity);

//把index位置为1
void BitMapSet(BitMap* bm,size_t index);

//把index位置为0
void BitMapUnSet(BitMap* bm,size_t index);

//测试index值是1还是0，如果是1，就返回1.否则就返回0
int BitMapTest(BitMap* bm,size_t index);

//把所有位都置为1
void BitMapFill(BitMap* bm);

//把所有位都置为0
void BitMapUnFill(BitMap* bm);

//销毁位图
void BitMapDestroy(BitMap* bm);