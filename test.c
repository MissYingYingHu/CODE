#include<stdio.h>
#include"address_book.h"
int main()
{
	int input = 0;
	ADDR_BOOK_Init(&ADDRLIST);
	LOAD_ADDRLIST_BOOK(&ADDRLIST);
	do
	{
		menu();
		printf("请选择你的需求：");
		scanf("%d",&input);
		switch(input)
		{
		case ADDContact:
			{
				ADD_ADDR_BOOK(&ADDRLIST);
				SAVE_ADDRLIST_BOOK(&ADDRLIST);
			}
			break;
		case DELETEContact:
			ERASE_ADDRLIST_BOOK(&ADDRLIST);
			SAVE_ADDRLIST_BOOK(&ADDRLIST);
			break;
		case FINDContact:
			FIND_ADDRLIST_BOOK(&ADDRLIST);
			break;
		case UPDATAContact:
			UPDATA_ADDRLIST_BOOK(&ADDRLIST);
			SAVE_ADDRLIST_BOOK(&ADDRLIST);
			break;
		case DISPLAYContact:
			DISPLAY_ALL_ADDRLIST_BOOK(&ADDRLIST);
			break;
		case DESTROYContact:
			DESTROY_ADDRLIST_BOOK(&ADDRLIST);
			SAVE_ADDRLIST_BOOK(&ADDRLIST);
			break;
		case SORTBYNAMEContact:
			BUBBLE_SORT_ADDRLIST_BOOK(&ADDRLIST);
			SAVE_ADDRLIST_BOOK(&ADDRLIST);
			break;
		case EXIT:
			break;
		default:
			printf("输入非法，请重新输入：\n");
			break;
		}
	}while(input);
	return 0;
}