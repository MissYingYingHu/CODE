#include<stdio.h>
#include"AddressBook.h"

void menu(){
	printf("\n○○○○○○○○○○○○○○○○○○○○○○○○○○○○○\n");
	printf("\n            1.打印通讯录            \n");
	printf("\n            2.添加通讯录            \n");
	printf("\n            3.删除通讯录            \n");
	printf("\n            4.查找通讯录            \n");
	printf("\n            5.修改通讯录            \n");
	printf("\n            6.销毁通讯录            \n");
	printf("\n            0.退出通讯录            \n");
	printf("\n○○○○○○○○○○○○○○○○○○○○○○○○○○○○○\n");
}
int main(){
	int input = 0;
	InitAddressBook(&addr_book);
	LoadAddrBook(&addr_book);
	do
	{
		menu();
		printf("亲，请输入您的需求：");
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
			printf("输入错误,请重新输入.");
			break;
		}
	}while(input);
	return 0;
}