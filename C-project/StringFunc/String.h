#pragma once
#include<stdio.h>
#include<stddef.h>
char* my_strcpy(char* dest,const char* src);
char* my_strcat(char* dest,const char* src);
char* my_strchr(const char* str,char c);//找第一个出现该字符的位置
char* my_strrchr(const char* str,char c);//找最后一个出现该字符的位置
char* my_strstr(const char* src,const char* sub);
void* my_memcpy(void* dest,const void* src,size_t size);
void* my_memmove(void* dest,const void* src,size_t size);

