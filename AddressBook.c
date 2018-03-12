#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AddressBook.h"

//初始化通讯录
void InitAddressBook(AddrBook* addr_book)
{
	addr_book->size =0;
	addr_book->capacity =1;
	addr_book->data = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
	if(addr_book->data == NULL)
	{
		printf("空间开辟失败.\n");
		return;
	}
}
//打印通讯录
void DisplayAddressBook(AddrBook* addr_book)
{
	size_t i =0;
	if(addr_book == NULL)
	{
		return;
	}
	if(addr_book->size == 0)
	{
		printf("通讯录为空.%s\n",FILE_PATH);
		return;
	}
	printf("【姓 名】\t\t【电 话】\t\t【地 址】\n");
	for(i=0;i < addr_book->size ;i++)
	{
		printf("%s\t\t%s\t\t%s\n",addr_book->data[i].name ,
								  addr_book->data[i].tel ,
								  addr_book->data[i].add);
	}
	printf("\n");
}
void MallocPersonInfo(AddrBook* addr_book)
{
	size_t i =0;
	PersonInfo* new_book = NULL;
	if(addr_book == NULL)
	{
		return;
	}
	addr_book->capacity = 2*addr_book->capacity +1;
	new_book = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
	for(i=0;i<addr_book->size ;i++)
	{
		new_book[i] = addr_book->data [i]; 
	}
	free(addr_book->data);
	addr_book->data = new_book;	
}
//添加通讯录
void AddAddressBook(AddrBook* addr_book)
{
	if(addr_book->size >= addr_book->capacity )
	{
		MallocPersonInfo(addr_book);
	}
	printf("开始添加通讯录\n");
	printf("请输入姓名：\n");
	scanf("%s",addr_book->data[addr_book->size ].name );
	printf("请输入电话：\n");
	scanf("%s",addr_book->data[addr_book->size ].tel  );
	printf("请输入地址：\n");
	scanf("%s",addr_book->data[addr_book->size ].add  );
	printf("添加成功\n");
	++addr_book->size ;
}
//保存通讯录
void SaveAddrBook(AddrBook* addr_book)
{
	FILE* fw = fopen(FILE_PATH,"w");
	size_t i = 0;
	if(addr_book == NULL)
	{
		return;
	}
	if(fw == NULL)
	{
		printf("打开文件失败.%s\n",FILE_PATH);
		return;
	}
	for(i=0;i<addr_book->size ;i++)
	{
		fprintf(fw,"%s\t\t%s\t\t%s\n",addr_book->data[i].name,
								      addr_book->data[i].tel,
								      addr_book->data[i].add);
	}
	fclose(fw);
}
//加载通讯录
void LoadAddrBook(AddrBook* addr_book)
{
	FILE* fr = fopen(FILE_PATH,"r");
	if(addr_book->size == 0 )
	{
		return;
	}
	if(fr == NULL)
	{
		printf("打开通讯录失败,%s\n",FILE_PATH);
		return;
	}
	while(feof(fr) == 0)                          //文件结束，返回非零值；否则返回0
	{
		fscanf(fr,"%s\t\t%s\t\t%s\n",addr_book->data[addr_book->size ].name ,
									 addr_book->data[addr_book->size ].tel ,
									 addr_book->data[addr_book->size ].add);
		++addr_book->size ;
		addr_book->capacity+=addr_book->size  ;
	}
	fclose(fr);
}
//删除通讯录中的指定条目
void EraseAddrBook(AddrBook* addr_book)
{
	size_t i = 0;
	size_t j = 0;int flag = 0;
	char to_deleted[NAME_SIZE];
	if(addr_book == NULL)
	{
		return;
	}
	if(addr_book->size == 0)
	{
		printf("通讯录为空.%s\n",FILE_PATH);
		return;
	}
	printf("请输入需要删除的人的姓名：");
	scanf("%s",to_deleted);
	for(i=0;i<addr_book->size ;i++)
	{
		if(strcmp(addr_book->data [i].name ,to_deleted)==0)
		{
			for(j=i;j< addr_book->size-1;j++)
			{
				addr_book->data [j] = addr_book->data [j+1];
			}
			--addr_book->size;
			printf("删除成功.\n");
			flag = 1;
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
void FindAddrBook(AddrBook* addr_book)
{
	int flag = 0;
	size_t i = 0;
	char to_find[NAME_SIZE];
	if(addr_book == NULL)
	{
		return;
	}
	if(addr_book->size == 0)
	{
		printf("通讯录为空.%s\n",FILE_PATH);
		return;
	}
	printf("请输入想要查找的人的姓名：");
	scanf("%s",to_find);
	for(i=0;i<addr_book->size;i++)
	{
		if(strcmp(addr_book->data[i].name,to_find)==0)
		{
			printf("%s\t\t%s\t\t%s\n",addr_book->data[i].name ,
								  addr_book->data[i].tel ,
								  addr_book->data[i].add);
			printf("查找成功.\n");
			flag = 1;
			return;
		}
	}
	if(flag == 0)
	{
		printf("通讯录中没有此人.\n");
		return;
	}
}
//修改通讯录信息
void InsertAddrBook(AddrBook* addr_book)
{
	int flag = 0;
	size_t i = 0;
	char to_insert[NAME_SIZE];
	if(addr_book == NULL)
	{
		return;
	}
	if(addr_book->size == 0)
	{
		printf("通讯录为空.%s\n",FILE_PATH);
		return;
	}
	printf("请输入想要修改的人的姓名：");
	scanf("%s",to_insert);
	for(i=0;i<addr_book->size ;i++)
	{
		if(strcmp(addr_book->data[i].name,to_insert)==0)
		{
			printf("请重新输入姓名：\n");
			scanf("%s",addr_book->data[i].name );
			printf("请重新电话：\n");
			scanf("%s",addr_book->data[i].tel  );
			printf("请重新输入地址：\n");
			scanf("%s",addr_book->data[i].add  );
			printf("修改成功\n");
			flag = 1;
			return;
		}
	}
	if(flag == 0)
	{
		printf("通讯录中没有此人.\n");
		return;
	}	
}
//销毁通讯录
void DestroyAddrBook(AddrBook* addr_book)
{
	if(addr_book == NULL)
	{
		return;
	}
	addr_book->size = 0;
	addr_book->capacity =0;
	free(addr_book->data );
	addr_book->data = NULL;
}