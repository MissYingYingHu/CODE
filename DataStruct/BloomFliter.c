#include"BloomFliter.h"
#include"BitMap.h"
#include<stdio.h>
size_t HashFunc0(const char *str)
{
	 size_t hash = 0;  
	 size_t ch = 0;
    while (ch = (size_t)*str++)  
   {         
       hash = hash * 131 + ch;   // Ҳ���Գ���31��131��1313��13131��131313..  
       // ����˵���˷��ֽ�Ϊλ���㼰�Ӽ����������Ч�ʣ��罫��ʽ���Ϊ��hash = hash << 7 + hash << 1 + hash + ch;  
        // ����ʵ��Intelƽ̨�ϣ�CPU�ڲ��Զ��ߵĴ���Ч�ʶ��ǲ��ģ�  
        // �ҷֱ������100�ڴε������������㣬���ֶ���ʱ�������Ϊ0�������Debug�棬�ֽ��λ�����ĺ�ʱ��Ҫ��1/3����  
        // ��ARM����RISCϵͳ��û�в��Թ�������ARM�ڲ�ʹ��Booth's Algorithm��ģ��32λ�����˷����㣬����Ч��������йأ�  
        // ������8-31λ��Ϊ1��0ʱ����Ҫ1��ʱ������  
        // ������16-31λ��Ϊ1��0ʱ����Ҫ2��ʱ������  
        // ������24-31λ��Ϊ1��0ʱ����Ҫ3��ʱ������  
        // ������Ҫ4��ʱ������  
        // ��ˣ���Ȼ��û��ʵ�ʲ��ԣ���������Ȼ��Ϊ����Ч���ϲ�𲻴�          
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