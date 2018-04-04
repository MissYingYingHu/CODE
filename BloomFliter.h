#pragma once

#include"BitMap.h"

#define HashFuncMaxSize 2
#define HashFuncCapacity 1024
typedef size_t (*HashFunc)(const char*);

typedef struct BloomFliter
{
	BitMap bitmap;
	HashFunc HashFunc[HashFuncMaxSize];
}BloomFliter;

//初始化布隆过滤器
void BloomFliterInit(BloomFliter* bf);

//布隆过滤器的插入
void BloomFliterInsert(BloomFliter* bf,const char* str);

//判断是否存在
int BloomFliterExist(BloomFliter* bf,const char* str);

//销毁布隆过滤器
void BloomFliterDestroy(BloomFliter* bf);