#include"BloomFliter.h"
#include"BitMap.h"
#include<stdio.h>
size_t HashFunc0(const char *str)
{
	 size_t hash = 0;  
	 size_t ch = 0;
    while (ch = (size_t)*str++)  
   {         
       hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313..  
       // 有人说将乘法分解为位运算及加减法可以提高效率，如将上式表达为：hash = hash << 7 + hash << 1 + hash + ch;  
        // 但其实在Intel平台上，CPU内部对二者的处理效率都是差不多的，  
        // 我分别进行了100亿次的上述两种运算，发现二者时间差距基本为0（如果是Debug版，分解成位运算后的耗时还要高1/3）；  
        // 在ARM这类RISC系统上没有测试过，由于ARM内部使用Booth's Algorithm来模拟32位整数乘法运算，它的效率与乘数有关：  
        // 当乘数8-31位都为1或0时，需要1个时钟周期  
        // 当乘数16-31位都为1或0时，需要2个时钟周期  
        // 当乘数24-31位都为1或0时，需要3个时钟周期  
        // 否则，需要4个时钟周期  
        // 因此，虽然我没有实际测试，但是我依然认为二者效率上差别不大          
    }  
    return hash;  
}
size_t HashFunc1(const char str[])
{
	size_t hash = 0;
	size_t ch = 0;
    while (ch = (size_t)*str++)  
    {  
        hash = 65599 * hash + ch;         
        //hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;  
    }  
    return hash;  
}
void BloomFliterInit(BloomFliter* bf)
{
	char *str = NULL;
	if(bf == NULL)
	{
		return;
	}
	BitMapInit(&(bf->bitmap) ,HashFuncCapacity);
	bf->HashFunc [0] = HashFunc0;
	bf->HashFunc [1] = HashFunc1;
}
void BloomFliterInsert(BloomFliter* bf,const char* str)
{
	size_t i = 0;
	size_t offset = 0;
	if(bf == NULL || str == NULL)
	{
		return;
	}
	for(;i < HashFuncMaxSize;i++)
	{
		offset = bf->HashFunc[i](str) % HashFuncCapacity;
		BitMapSet(&(bf->bitmap),offset);
	}
}
int BloomFliterExist(BloomFliter* bf,const char* str)
{
	size_t i = 0;
	size_t index = 0;
	int ret = 0;
	if(bf == NULL || str == NULL)
	{
		return 0;
	}
	for(;i < HashFuncMaxSize;i++)
	{
		index = bf->HashFunc [i](str) % HashFuncCapacity;
		ret = BitMapTest(&bf->bitmap ,index);
		if(ret == 0)
		{
			return 0;
		}
	}
	return 1;
}
void BloomFliterDestroy(BloomFliter* bf)
{
	size_t i = 0;
	if(bf == NULL)
	{
		return;
	}
	BitMapDestroy(&bf->bitmap);
	for(;i < HashFuncMaxSize;i++)
	{
		bf->HashFunc [i] = NULL;
	}
}