#include"address_book.h"
#include<stdio.h>
#include<string.h>
#include<assert.h>



void menu()
{
	printf("----------------------------------------\n");
	printf("1.�����ϵ����Ϣ\n");
	printf("2.ɾ��ָ����ϵ����Ϣ\n");
	printf("3.����ָ����ϵ����Ϣ\n");
	printf("4.�޸�ָ����ϵ����Ϣ\n");
	printf("5.��ʾ��������Ϣ\n");
	printf("6.�����������Ϣ\n");
	printf("7.����������������ϵ����Ϣ\n");
	printf("0.�˳�\n");
	printf("----------------------------------------\n");
}
//��ʼ��
void ADDR_BOOK_Init(address_book *ADDRLIST)
{
	ADDRLIST->size = 0;
}
//���
void ADD_ADDR_BOOK(address_book *ADDRLIST)
{
	assert(ADDRLIST);
	if(ADDRLIST->size > ADDRESS_BOOK_MAX)
	{
		printf("ͨѶ¼�����������������ϵ��\n");
		return;
	}
	printf("��ʼ���\n");
	printf("����������\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].name);
	printf("�������Ա�\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].gender);
	printf("����������\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].age);
	printf("������绰����\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].tele_number);
	printf("�������ַ\n");
	scanf("%s",ADDRLIST->book[ADDRLIST->size ].address );
	printf("��ӳɹ�\n");
	ADDRLIST->size ++;
}
//��ʾ
void DISPLAY_ALL_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	size_t i = 0;
	assert(ADDRLIST);
	if(ADDRLIST->size == 0)
	{
		printf("ͨѶ¼Ϊ�ա�\n");
		return;
	}
	printf("|����|\t\t|�Ա�|\t\t|����|\t\t|�绰|\t\t\t|��ַ|\n");
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
//ɾ��ָ����ϵ��
void ERASE_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	size_t i = 0,j = 0;
	int flag = 0;
	ELEM_TYPE deleted[100];
	assert(ADDRLIST);
	if(ADDRLIST->size <=0)
	{
		printf("ͨѶ¼Ϊ��\n");
		return ;
	}
	printf("������Ҫɾ����������");
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
			printf("ɾ���ɹ���\n");
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
void FIND_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	size_t i =0;
	ELEM_TYPE find[100];
	int flag = 0;
	assert(ADDRLIST);
	if(ADDRLIST->size == 0)
	{
		printf("ͨѶ¼Ϊ�ա�\n");
	}
	printf("������Ҫ���ҵ�������");
	scanf("%s",find);
	for(i=0;i<ADDRLIST->size ;i++)
	{
		if(strcmp(ADDRLIST->book [i].name ,find) == 0)
		{
			flag = 1;
			printf("|����|\t\t|�Ա�|\t\t|����|\t\t|�绰|\t\t\t|��ַ|\n");
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
		printf("ͨѶ¼��û������ˡ�\n");
	}
}
//�޸�ָ���˵���Ϣ
void UPDATA_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	size_t i = 0;
	ELEM_TYPE updata[200];
	assert(ADDRLIST);
	if(ADDRLIST->size == 0)
	{
		printf("ͨѶ¼Ϊ�ա�\n");
		return;
	}
	printf("������Ҫ�޸ĵ��˵����֣�");
	scanf("%s",updata);
	for(i=0;i<ADDRLIST->size ;i++)
	{
		if(strcmp(ADDRLIST->book [i].name ,updata) == 0)
		{
			printf("��������������\n");
			scanf("%s",ADDRLIST->book[i].name);
			printf("�����������Ա�\n");
			scanf("%s",ADDRLIST->book[i].gender);
			printf("��������������\n");
			scanf("%s",ADDRLIST->book[i].age);
			printf("����������绰����\n");
			scanf("%s",ADDRLIST->book[i].tele_number);
			printf("�����������ַ\n");
			scanf("%s",ADDRLIST->book[i].address );
			return;
		}
	}
}
//���ͨѶ¼
void DESTROY_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	assert(ADDRLIST);
	ADDRLIST->size = 0;
}
//ͨѶ¼����������
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
		printf("ͨѶ¼Ϊ�ա�\n");
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
//������Ϣ
void SAVE_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	FILE* write = fopen(FILE_PATH,"w");
	size_t i = 0;
	assert(ADDRLIST);
	if(write == NULL)
	{
		printf("�ļ���ʧ�ܣ�%s\n",FILE_PATH);									//FILE_PATH
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
//����ͨѶ¼
void LOAD_ADDRLIST_BOOK(address_book *ADDRLIST)
{
	FILE* read = fopen(FILE_PATH,"r");
	assert(ADDRLIST);
	if(read == NULL)
	{
		printf("�ļ���ʧ�ܡ�%s\n",FILE_PATH);									//FILE_PATH
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