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

//��ʼ��λͼ
void BitMapInit(BitMap* bm,size_t capacity);

//��indexλ��Ϊ1
void BitMapSet(BitMap* bm,size_t index);

//��indexλ��Ϊ0
void BitMapUnSet(BitMap* bm,size_t index);

//����indexֵ��1����0�������1���ͷ���1.����ͷ���0
int BitMapTest(BitMap* bm,size_t index);

//������λ����Ϊ1
void BitMapFill(BitMap* bm);

//������λ����Ϊ0
void BitMapUnFill(BitMap* bm);

//����λͼ
void BitMapDestroy(BitMap* bm);