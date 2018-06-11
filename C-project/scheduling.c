#include"scheduling.h"

PCB_Struct* CreateNode(char* _name,int _worktime,int _pricount)
{
	PCB_Struct* new_PCB = (PCB_Struct*)malloc(sizeof(PCB_Struct));
	new_PCB->name = _name;
	new_PCB->next = NULL;
	new_PCB->worktime = _worktime;
	new_PCB->priconut = _pricount;
	new_PCB->stat = EXIT;
	return new_PCB;
}

void PCB_Struct_Init(PCB_Struct **head)
{
	if(head == NULL)
	{
		return;
	}
	*head = CreateNode("p0",0,0);
}


void PCB_Struct_Push(PCB_Struct **head,char* _name,int _worktime,int _pricount)
{
	PCB_Struct* new_PCB = NULL;
	PCB_Struct* cur = (*head)->next;
	if(head == NULL)
	{
		return;
	}
	new_PCB = CreateNode(_name,_worktime,_pricount);
	if((*head)->next == NULL)
	{
		(*head)->next = new_PCB;
		new_PCB->next = (*head);
		return;
	}
	while(cur->next != (*head))
	{
		cur = cur->next;
	}
	cur->next = new_PCB;
	new_PCB->next = (*head);
}

void Display(PCB_Struct *head)
{
	PCB_Struct* cur = NULL;
	if(head == NULL)
	{
		return;
	}
	printf("\n");
	cur = head->next;
	while(cur != head)
	{
		printf("[名称:%s]	[运行时间:%d]		[优先数:%d] \n",cur->name,cur->worktime,cur->priconut);
		cur = cur->next;
	}
}

void PCB_Struct_Pop(PCB_Struct* head,PCB_Struct* deleted,PCB_Struct* prev)
{
	if(prev != head || (prev == head && deleted->next != head))
	{
		//进程数一定不是一个
		prev->next = deleted->next ;
		free(deleted);
		deleted = NULL;
	}
	else
	{
		//现在只有一个进程
		free(deleted);
		deleted = NULL;
		prev->next = NULL;
	}
}

PCB_Struct* Confirm_Pri(PCB_Struct* head,PCB_Struct** max,PCB_Struct** prev)
{
	PCB_Struct* cur = head->next;
	if(max == NULL)
	{
		return NULL;
	}
	while(cur != head)
	{
		if(cur->priconut > (*max)->priconut )
		{
			(*max) = cur;
		}
		cur = cur->next;
	}
	cur = head;
	while(cur->next != (*max))
	{
		cur = cur->next ;
	}
	(*prev) = cur;
	return (*max);
}

void PCB_Work(PCB_Struct *head)
{
	PCB_Struct* cur = head->next;
	PCB_Struct* prev = head;
	PCB_Struct* _pre = NULL;
	PCB_Struct* deleted = NULL;
	while(1)
	{
		printf("\n===================\n");
		if(Confirm_Pri(head,&cur,&_pre) == NULL)
		{
			return;
		}
		prev = _pre;
		if(cur->priconut == 0 && cur->worktime != 0)
		{
			//如果优先级为0而执行时间不为0
						printf("此时我的优先级最高.[名称:%s] [优先级:%d] [执行时间:%d]\n",cur->name ,cur->priconut ,cur->worktime );
			--cur->worktime;
			cur->priconut = 0;
		}
		else if(cur->priconut != 0 && cur->worktime == 0)
		{
			//如果优先级不为0而执行时间为0 就说明该进程已经执行结束
			cur->stat = EXIT;
			cur->priconut = 0;
		}
		else if(cur->worktime != 0 && cur->priconut != 0)
		{
			printf("此时我的优先级最高.[名称:%s] [优先级:%d] [执行时间:%d]\n",cur->name ,cur->priconut ,cur->worktime );
			--cur->priconut;
			--cur->worktime;
		}
		if(cur->worktime == 0)
		{
			//此时该进程已经执行结束,应该删除该进程
			deleted = cur;
			cur = cur->next ;
			deleted->stat = EXIT;
			if(deleted->next == head && prev == head)
			{
				PCB_Struct_Pop(head,deleted,prev);
				break;
			}
			PCB_Struct_Pop(head,deleted,prev);
		}
		if(cur->next != head)
		{
			cur = cur->next;
		}
		else
		{
			cur = head->next;
		}
		Display(head);
	}
}