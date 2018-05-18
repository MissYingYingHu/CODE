#include<windows.h>
#include"scheduling.h"

#define Test_Header printf("\n====================%s==================\n",__FUNCTION__)


void Test_Push()
{
	PCB_Struct* head;
	Test_Header;
	PCB_Struct_Init(&head);
	PCB_Struct_Push(&head,"p1",2,1);
	PCB_Struct_Push(&head,"p2",3,5);
	PCB_Struct_Push(&head,"p3",1,3);
	PCB_Struct_Push(&head,"p4",2,4);
	PCB_Struct_Push(&head,"p5",4,2);
	Display(head);
}

void Test_Work()
{
	PCB_Struct* head;
	Test_Header;
	PCB_Struct_Init(&head);
	PCB_Struct_Push(&head,"p1",2,1);
	PCB_Struct_Push(&head,"p2",3,5);
	PCB_Struct_Push(&head,"p3",1,3);
	PCB_Struct_Push(&head,"p4",2,4);
	PCB_Struct_Push(&head,"p5",4,2);
	Display(head);
	PCB_Work(head);
}

int main()
{
	Test_Push();
	Test_Work();
	Sleep(5);
	system("pause");
	return 0;
}