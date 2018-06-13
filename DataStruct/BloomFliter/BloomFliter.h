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

//��ʼ����¡������
void BloomFliterInit(BloomFliter* bf);

//��¡�������Ĳ���
void BloomFliterInsert(BloomFliter* bf,const char* str);

//�ж��Ƿ����
int BloomFliterExist(BloomFliter* bf,const char* str);

//���ٲ�¡������
void BloomFliterDestroy(BloomFliter* bf);