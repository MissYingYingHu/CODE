#pragma once
#include<stdio.h>
#include<stdlib.h>


enum State
{
	EXIT,
	RUN,
};

typedef struct PCB_Struct
{
	char* name;//PCB名称
	struct PCB_Struct* next;//下一个PCB
	int worktime;//运行时间
	int priconut;//优先数
    enum State stat;//状态
}PCB_Struct;

void PCB_Struct_Init(PCB_Struct **head);

void PCB_Struct_Push(PCB_Struct **head,char* _name,int _worktime,int _pricount);

void PCB_Work(PCB_Struct *head);

void Display(PCB_Struct *head);
