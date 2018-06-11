#include"address_book.h"
#include<stdio.h>
#include<string.h>
#include<assert.h>



void menu()
{
	printf("----------------------------------------\n");
	printf("1.添加联系人信息\n");
	printf("2.删除指定联系人信息\n");
	printf("3.查找指定联系人信息\n");
	printf("4.修改指定联系人信息\n");
	printf("5.显示所有人信息\n");
	printf("6.清空所有人信息\n");
	printf("7.以名字排序所有联系人信息\n");
	printf("0.退出\n");
	printf("----------------------------------------\n");
}
//初始化
void ADDR_BOOK_Init(address_book *ADDRLIST)
{
	ADDRLIST->size = 0;
}
//添加
void ADD_ADDR_BOOK(address_book *ADDRLIST)
{
	assert(ADDRLIST);
	if(ADDRLIST->size > ADDRESS_BOOK_MAX)
	{
		printf("通讯录已满，不可再添加联系人\n");
		return;
	}
	printf("开始添加\n");
	printf("请输入姓名\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].name);
	printf("请输入性别\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].gender);
	printf("请输入年龄\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].age);
	printf("请输入电话号码\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].tele_number);
	printf("请输入地址\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].address );
	printf("添加成功\n");
	ADDRLIST->size ++;
}
//显示
void DISPLAY_ALL_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	size_t i = 0;
	assert(ADDRLIST);
	if(ADDRLIST->size == 0)
	{
		printf("通讯录为空。\n");
		return;
	}
	printf("|姓名|\t\t|性别|\t\t|年龄|\t\t|电话|\t\t\t|地址|\n");
	for(i=0;i<ADDRLIST->size;i++)
	{
		printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n"
			,ADDRLIST->book[i].name
			,ADDRLIST->book[i].gender 
			,ADDRLIST->book[i].age 
			,ADDRLIST->book[i].tele_number 
			,ADDRLIST->book[i].address);
	}
}
//删除指定联系人
void ERASE_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	size_t i = 0,j = 0;
	int flag = 0;
	ELEM_TYPE deleted[100];
	assert(ADDRLIST);
	if(ADDRLIST->size <=0)
	{
		printf("通讯录为空\n");
		return ;
	}
	printf("请输入要删除的姓名：");
	scanf("%s",deleted);
	for(i=0;i <= ADDRLIST->size;i++)
	{
		if(strcmp(ADDRLIST->book [i].name ,deleted) == 0)
		{
			for(j=i;j < ADDRLIST->size;j++)
			{
				ADDRLIST->book[j] = ADDRLIST->book [j+1];
			}
			flag = 1;
			ADDRLIST->size --;
			printf("删除成功。\n");
			return;
		}
	}
	if(flag == 0)
	{
		printf("通讯录中没有此人.\n");
		return;
	}
}
//查找通讯录
void FIND_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	size_t i =0;
	ELEM_TYPE find[100];
	int flag = 0;
	assert(ADDRLIST);
	if(ADDRLIST->size == 0)
	{
		printf("通讯录为空。\n");
	}
	printf("请输入要查找的姓名：");
	scanf("%s",find);
	for(i=0;i<ADDRLIST->size ;i++)
	{
		if(strcmp(ADDRLIST->book [i].name ,find) == 0)
		{
			flag = 1;
			printf("|姓名|\t\t|性别|\t\t|年龄|\t\t|电话|\t\t\t|地址|\n");
		    printf("%s\t\t%s\t\t%s\t\t%s\t\t%s\n"
			,ADDRLIST->book[i].name
			,ADDRLIST->book[i].gender 
			,ADDRLIST->book[i].age 
			,ADDRLIST->book[i].tele_number 
			,ADDRLIST->book[i].address);
			return;
		}
	}
	if(flag == 0)
	{
		printf("通讯录中没有这个人。\n");
	}
}
//修改指定人的信息
void UPDATA_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	size_t i = 0;
	ELEM_TYPE updata[200];
	assert(ADDRLIST);
	if(ADDRLIST->size == 0)
	{
		printf("通讯录为空。\n");
		return;
	}
	printf("输入需要修改的人的名字：");
	scanf("%s",updata);
	for(i=0;i<ADDRLIST->size ;i++)
	{
		if(strcmp(ADDRLIST->book [i].name ,updata) == 0)
		{
			printf("请重新输入姓名\n");
			scanf("%s",ADDRLIST->book[i].name);
			printf("请重新输入性别\n");
			scanf("%s",ADDRLIST->book[i].gender);
			printf("请重新输入年龄\n");
			scanf("%s",ADDRLIST->book[i].age);
			printf("请重新输入电话号码\n");
			scanf("%s",ADDRLIST->book[i].tele_number);
			printf("请重新输入地址\n");
			scanf("%s",ADDRLIST->book[i].address );
			return;
		}
	}
}
//清空通讯录
void DESTROY_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	assert(ADDRLIST);
	ADDRLIST->size = 0;
}
//通讯录按名称排序
void swap(person* x,person* y)
{
	 person  temp = *x;
			  *x = *y;
			  *y = temp;
}
void BUBBLE_SORT_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	size_t i = 0,j = 0;
	assert(ADDRLIST);
	if(ADDRLIST->size == 0)
	{
		printf("通讯录为空。\n");
		return;
	}
	for(i=0;i<ADDRLIST->size-1;i++)
	{
		for(j=0;j<ADDRLIST->size-i-1;j++)
		{
			if(strcmp(ADDRLIST->book [j].name,ADDRLIST->book [j+1].name )>0)
			{
				swap(&ADDRLIST->book [j],&ADDRLIST->book [j+1]);
			}
		}
	}
}
//保存信息
void SAVE_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	FILE* write = fopen(FILE_PATH,"w");
	size_t i = 0;
	assert(ADDRLIST);
	if(write == NULL)
	{
		printf("文件打开失败！%s\n",FILE_PATH);									//FILE_PATH
		return;
	}
	for(i=0;i<ADDRLIST->size ;i++)
	{
		fprintf(write,"%s\t%s\t%s\t%s\t%s\n"
			,ADDRLIST->book [i].name 
			,ADDRLIST->book[i].gender 
			,ADDRLIST->book [i].age 
			,ADDRLIST->book [i].tele_number 
			,ADDRLIST->book [i].address );
	}
	fclose(write);
}
//加载通讯录
void LOAD_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	FILE* read = fopen(FILE_PATH,"r");
	assert(ADDRLIST);
	if(read == NULL)
	{
		printf("文件打开失败。%s\n",FILE_PATH);									//FILE_PATH
		return;
	}
	while(feof(read)==0)
	{
		fscanf(read,"%s\t%s\t%s\t%s\t%s\n"
			,ADDRLIST->book [ADDRLIST->size ].name 
			,ADDRLIST->book[ADDRLIST->size].gender 
			,ADDRLIST->book [ADDRLIST->size].age 
			,ADDRLIST->book [ADDRLIST->size].tele_number 
			,ADDRLIST->book [ADDRLIST->size].address );
			++ADDRLIST->size ;
	}
	fclose(read);
}