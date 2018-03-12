#include<stdio.h>
#include"AddressBook.h"

void menu(){
	printf("\n������������������������������\n");
	printf("\n            1.��ӡͨѶ¼            \n");
	printf("\n            2.���ͨѶ¼            \n");
	printf("\n            3.ɾ��ͨѶ¼            \n");
	printf("\n            4.����ͨѶ¼            \n");
	printf("\n            5.�޸�ͨѶ¼            \n");
	printf("\n            6.����ͨѶ¼            \n");
	printf("\n            0.�˳�ͨѶ¼            \n");
	printf("\n������������������������������\n");
}
int main(){
	int input = 0;
	InitAddressBook(&addr_book);
	LoadAddrBook(&addr_book);
	do
	{
		menu();
		printf("�ף���������������");
		scanf("%d",&input);
		switch(input)
		{
		case DISPLAY:DisplayAddressBook(&addr_book);
			break;
		case ADD: AddAddressBook(&addr_book);
				  SaveAddrBook(&addr_book);
			break;
		case ERASE:EraseAddrBook(&addr_book);
				   SaveAddrBook(&addr_book);
			break;
		case FIND:FindAddrBook(&addr_book);
			break;
		case INSERT:InsertAddrBook(&addr_book);
		        	SaveAddrBook(&addr_book);
			break;
		case DESTROY:DestroyAddrBook(&addr_book);
					 SaveAddrBook(&addr_book);
			break;
		case EXIT:
			break;
		default:
			printf("�������,����������.");
			break;
		}
	}while(input);
	return 0;
}