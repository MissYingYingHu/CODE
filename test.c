#include"BloomFliter.h"
#include<stdio.h>
#include<windows.h>

void TestInit()
{
	BloomFliter bf;
	TEST_HEADER;
	BloomFliterInit(&bf);
}
void TestInsert()
{
	char *str = "beautiful";
	BloomFliter bf;
	TEST_HEADER;
	BloomFliterInit(&bf);
	BloomFliterInsert(&bf,str);
}
void TestExist()
{
	int ret = 0;
	char *str = "beautiful";
	BloomFliter bf;
	TEST_HEADER;
	BloomFliterInit(&bf);
	BloomFliterInsert(&bf,str);
	ret = BloomFliterExist(&bf,"beautiful");
	printf("ret expect is 1,actual is %d\n",ret);
}
void TestDestroy()
{
	char *str = "beautiful";
	BloomFliter bf;
	TEST_HEADER;
	BloomFliterInit(&bf);
	BloomFliterInsert(&bf,str);
	BloomFliterDestroy(&bf);
}
int main()
{
	TestInit();
	TestInsert();
	TestExist();
	TestDestroy();
	system("pause");
	return 0;
}