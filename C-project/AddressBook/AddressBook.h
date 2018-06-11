#pragma once

#define NAME_SIZE  100
#define TEL_SIZE  100
#define ADD_SIZE  200
#define TEXTHEADER  printf("\n---------------------%s--------------------\n",__FUNCTION__)
#define FILE_PATH "Dbook.txt"
enum{
	DISPLAY = 1, 
	ADD = 2, 
	ERASE = 3, 
	FIND = 4, 
	INSERT = 5,
	DESTROY = 6,
	EXIT = 0 
};
typedef struct PersonInfo{
	char name[NAME_SIZE];
	char tel[TEL_SIZE];
	char add[ADD_SIZE];
}PersonInfo;
typedef struct AddrBook{
	PersonInfo* data;
	size_t size;
	size_t capacity;
}AddrBook;

AddrBook addr_book;
void InitAddressBook(AddrBook* addr_book);
void DisplayAddressBook(AddrBook* addr_book);
void AddAddressBook(AddrBook* addr_book);
void MallocPersonInfo(AddrBook* addr_book);
void SaveAddrBook(AddrBook* addr_book);
void LoadAddrBook(AddrBook* addr_book);
void EraseAddrBook(AddrBook* addr_book);
void FindAddrBook(AddrBook* addr_book);
void InsertAddrBook(AddrBook* addr_book); 
void DestroyAddrBook(AddrBook* addr_book); 