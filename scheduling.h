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
	char* name;//PCB����
	struct PCB_Struct* next;//��һ��PCB
	int worktime;//����ʱ��
	int priconut;//������
    enum State stat;//״̬
}PCB_Struct;

void PCB_Struct_Init(PCB_Struct **head);

void PCB_Struct_Push(PCB_Struct **head,char* _name,int _worktime,int _pricount);

void PCB_Work(PCB_Struct *head);

void Display(PCB_Struct *head);
