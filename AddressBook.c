#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"AddressBook.h"

//��ʼ��ͨѶ¼
void InitAddressBook(AddrBook* addr_book)
{
	addr_book->size =0;
	addr_book->capacity =1;
	addr_book->data = (PersonInfo*)malloc(sizeof(PersonInfo)*addr_book->capacity);
	if(addr_book->data == NULL)
	{
		printf("�ռ俪��ʧ��.\n");
		return;
	}
}
//��ӡͨѶ¼
void DisplayAddressBook(AddrBook* addr_book)
{
	size_t i =0;
	if(addr_book == NULL)
	{
		return;
	}
	if(addr_book->size == 0)
	{
		printf("ͨѶ¼Ϊ��.%s\n",FILE_PATH);
		return;
	}
	printf("���� ����\t\t���� ����\t\t���� ַ��\n");
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
//���ͨѶ¼
void AddAddressBook(AddrBook* addr_book)
{
	if(addr_book->size >= addr_book->capacity )
	{
		MallocPersonInfo(addr_book);
	}
	printf("��ʼ���ͨѶ¼\n");
	printf("������������\n");
	scanf("%s",addr_book->data[addr_book->size ].name );
	printf("������绰��\n");
	scanf("%s",addr_book->data[addr_book->size ].tel  );
	printf("�������ַ��\n");
	scanf("%s",addr_book->data[addr_book->size ].add  );
	printf("��ӳɹ�\n");
	++addr_book->size ;
}
//����ͨѶ¼
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
		printf("���ļ�ʧ��.%s\n",FILE_PATH);
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
//����ͨѶ¼
void LoadAddrBook(AddrBook* addr_book)
{
	FILE* fr = fopen(FILE_PATH,"r");
	if(addr_book->size == 0 )
	{
		return;
	}
	if(fr == NULL)
	{
		printf("��ͨѶ¼ʧ��,%s\n",FILE_PATH);
		return;
	}
	while(feof(fr) == 0)                          //�ļ����������ط���ֵ�����򷵻�0
	{
		fscanf(fr,"%s\t\t%s\t\t%s\n",addr_book->data[addr_book->size ].name ,
									 addr_book->data[addr_book->size ].tel ,
									 addr_book->data[addr_book->size ].add);
		++addr_book->size ;
		addr_book->capacity+=addr_book->size  ;
	}
	fclose(fr);
}
//ɾ��ͨѶ¼�е�ָ����Ŀ
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
		printf("ͨѶ¼Ϊ��.%s\n",FILE_PATH);
		return;
	}
	printf("��������Ҫɾ�����˵�������");
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
			printf("ɾ���ɹ�.\n");
			flag = 1;
			return;
		}
	}
	if(flag == 0)
	{
		printf("ͨѶ¼��û�д���.\n");
		return;
	}
}
//����ͨѶ¼
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
		printf("ͨѶ¼Ϊ��.%s\n",FILE_PATH);
		return;
	}
	printf("��������Ҫ���ҵ��˵�������");
	scanf("%s",to_find);
	for(i=0;i<addr_book->size;i++)
	{
		if(strcmp(addr_book->data[i].name,to_find)==0)
		{
			printf("%s\t\t%s\t\t%s\n",addr_book->data[i].name ,
								  addr_book->data[i].tel ,
								  addr_book->data[i].add);
			printf("���ҳɹ�.\n");
			flag = 1;
			return;
		}
	}
	if(flag == 0)
	{
		printf("ͨѶ¼��û�д���.\n");
		return;
	}
}
//�޸�ͨѶ¼��Ϣ
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
		printf("ͨѶ¼Ϊ��.%s\n",FILE_PATH);
		return;
	}
	printf("��������Ҫ�޸ĵ��˵�������");
	scanf("%s",to_insert);
	for(i=0;i<addr_book->size ;i++)
	{
		if(strcmp(addr_book->data[i].name,to_insert)==0)
		{
			printf("����������������\n");
			scanf("%s",addr_book->data[i].name );
			printf("�����µ绰��\n");
			scanf("%s",addr_book->data[i].tel  );
			printf("�����������ַ��\n");
			scanf("%s",addr_book->data[i].add  );
			printf("�޸ĳɹ�\n");
			flag = 1;
			return;
		}
	}
	if(flag == 0)
	{
		printf("ͨѶ¼��û�д���.\n");
		return;
	}	
}
//����ͨѶ¼
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