#include"BitMap.h"
#include<stdio.h>
#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
int Capacity(size_t capacity)
{
	return capacity/(sizeof(uint64_t)*8)+1;
}
void GetOffset(size_t index,size_t* n,size_t* offset)
{
	*offset = index%(sizeof(uint64_t)*8);
	*n = index/(sizeof(uint64_t)*8);
}
void BitMapInit(BitMap* bm,size_t capacity)
{
	size_t i = 0;
	if(bm == NULL)
	{
		return;
	}
	bm->capacity = Capacity(capacity);
	bm->data = (uint64_t*)malloc(sizeof(uint64_t)*bm->capacity );
	memset(bm->data ,0,bm->capacity * sizeof(uint64_t));
}
void BitMapSet(BitMap* bm,size_t index)
{
	size_t offset = 0;
	size_t n = 0;
	if(bm == NULL)
	{
		return;
	}
	GetOffset(index,&n,&offset);
	bm->data[n] |= (1u << offset);
}
void BitMapUnSet(BitMap* bm,size_t index)
{
	size_t offset = 0;
	size_t n = 0;
	if(bm == NULL)
	{
		return;
	}
	GetOffset(index,&n,&offset);
	bm->data [n] &= ~(1u << offset);
}
int BitMapTest(BitMap* bm,size_t index)
{
	size_t offset = 0;
	size_t n = 0;
	if(bm == NULL)
	{
		return 0;
	}
	GetOffset(index,&n,&offset);
	if((bm->data [n] & (1u << offset)) == (1u << offset))
	{
		return 1;
	}
	return 0;
 }
void BitMapFill(BitMap* bm)
{
	if(bm == NULL)
	{
		return;
	}
	memset(bm->data ,0xff,sizeof(uint64_t)*bm->capacity );
}
void BitMapUnFill(BitMap* bm)
{
	if(bm == NULL)
	{
		return;
	}
	memset(bm->data ,0,sizeof(uint64_t)*bm->capacity );
}
void BitMapDestroy(BitMap* bm)
{
	if(bm == NULL)
	{
		return;
	}
	free(bm->data );
	bm->capacity = 0;
}
