#pragma once
#include<stddef.h>
#define ADDRESS_BOOK_MAX    1000
#define ELEM_TYPE     char 
#define FILE_PATH     "book.txt"

typedef struct person{
	ELEM_TYPE name[100];
	ELEM_TYPE gender[100];
	ELEM_TYPE age[100];
	ELEM_TYPE tele_number[100];
	ELEM_TYPE address[100];
}person;

typedef struct address_book
{
	person  book[ADDRESS_BOOK_MAX];
	size_t size;
}address_book;

address_book ADDRLIST;

enum{
	ADDContact = 1,
	DELETEContact = 2,
	FINDContact = 3,
	UPDATAContact = 4,
	DISPLAYContact = 5,
	DESTROYContact = 6,
	SORTBYNAMEContact = 7,
	EXIT = 0

};

void menu();
void ADDR_BOOK_Init(address_book *ADDRLIST);
void ADD_ADDR_BOOK(address_book *ADDRLIST);
void DISPLAY_ALL_ADDRLIST_BOOK(address_book *ADDRLIST);
void ERASE_ADDRLIST_BOOK(address_book *ADDRLIST);
void SAVE_ADDRLIST_BOOK(address_book *ADDRLIST);
void LOAD_ADDRLIST_BOOK(address_book *ADDRLIST);
void FIND_ADDRLIST_BOOK(address_book *ADDRLIST);
void UPDATA_ADDRLIST_BOOK(address_book *ADDRLIST);
void DESTROY_ADDRLIST_BOOK(address_book *ADDRLIST);
void BUBBLE_SORT_ADDRLIST_BOOK(address_book *ADDRLIST);
void swap(person* x,person* y);