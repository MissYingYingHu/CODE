#include<stdio.h>
#include<stdlib.h>
#include"snake.h"
#include<windows.h>
//���ù��
void SetPos(int x,int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle,pos);
}
//��ӡ��ͼ
void CreateMap()
{
	int i = 0;
	for(;i<=56;i=i+2)
	{
		SetPos(i,0);
		printf(BUNDER);
		SetPos(i,26);
		printf(BUNDER);
	}
	for(i=1;i<=25;i++)
	{
		SetPos(0,i);
		printf(BUNDER);
		SetPos(56,i);
		printf(BUNDER);
	}
}
//����Ϸ�Ľ���
void ShowWelcome()
{
	SetPos(20,10);
	printf("��ӭ����̰����С��Ϸ��\n");
	SetPos(30,13);
	printf("��ʹ�á� �� �� �� �������ߵ��ƶ�����.\n");
	system("pause");
	system("cls");
}

void InitSnake(Snake* s)
{
	int i = 0;
	Node* cur = NULL;
	Node* head = (Node*)malloc(sizeof(Node));
	head->x = C;
	head->y = L;
	head->next = NULL;
	for(i = 1;i <= 4;++i)
	{
		s->pSnake = (Node*)malloc(sizeof(Node));
		s->pSnake->next = head;
		s->pSnake ->x = C + 2*i;
		s->pSnake ->y = L;
		head = s->pSnake ;
	}
	//��ӡ��
	while(head != NULL)
	{
		SetPos(head->x ,head->y );
		printf(FOOD);
		head = head->next ;
	}
	s->sleeptime = 1000;
	s->stat = ok;
	s->dir = right;
}
void InitFood(Snake* s) //�Ƚ��ѣ���װΪ����
{
	pNode pFood = NULL;
	pNode cur = NULL;
	pFood = (Node*)malloc(sizeof(Node));
again:
	cur = s->pSnake ;
	//�ж��ߵ�ʳ���λ�ã�Ҫ�ͱ߿����
	do{
		pFood->x = rand() % 53 + 2;
	}while(pFood->x  % 2 != 0);
	pFood->y = rand() % 25 + 1;
	while(cur != NULL)
	{
		if(cur->x == pFood->x && cur->y == pFood->y )
			goto again;
		cur = cur->next ;
	}
	s->pFood = pFood;
	SetPos(pFood->x ,pFood->y );
	printf(FOOD);
}
int NextIsFood(Snake* s)
{
	if(s->pSnake->x == s->pFood ->x  && s->pSnake->y == s->pFood ->y  )
	{		
		return 1;
	}
	return 0;
}
void Eat(Snake* s,pNode node)
{
	pNode cur = NULL;
	node->next = s->pSnake ;
	s->pSnake = node;
	cur = s->pSnake;
	while(cur != NULL)
	{
		SetPos(cur->x ,cur->y );
		printf(FOOD);
		cur = cur->next ;
	}
	//��ʳ����˺�Ҫ�ڴ���һ��ʳ��
	InitFood(s);
}
void NextNoFood(Snake* s,pNode node)
{
	pNode cur = NULL;
	node->next = s->pSnake ;
	s->pSnake = node;
	cur = s->pSnake ;
	while(cur->next->next != NULL)
	{
		SetPos(cur->x ,cur->y );
		printf(FOOD);
		cur = cur->next ;
	}
	SetPos(cur->next ->x ,cur->next ->y );
	printf("  ");
	free(cur->next );
	cur->next = NULL;
}
void SnakeRun(Snake* s)
{
	pNode NextNode = (Node*)malloc(sizeof(Node));
	NextNode->x = s->pSnake ->x ;
	NextNode->y = s->pSnake ->y ;
	switch(s->dir )
	{
	case up:
		NextNode->y -= 1;
		break;
	case down:
		NextNode->y += 1;
		break;
	case left:
		NextNode->x -= 2;
		break;
	case right:
		NextNode->x += 2;
		break;
	default:
		break;
	}
	if(NextIsFood(s))
	{
		Eat(s,NextNode);
		Grade(s);
	}
	else
	{
		NextNoFood(s,NextNode);
	}
}
void SnakeRun2(Snake* s)
{
	do
	{
		if(GetAsyncKeyState(VK_UP) && s->dir != down )
		{
			s->dir = up;
		}
		else if(GetAsyncKeyState(VK_DOWN) && s->dir != up )
		{
			s->dir = down;
		}
		else if(GetAsyncKeyState(VK_LEFT) && s->dir != right )
		{
			s->dir = left;
		}
		else if(GetAsyncKeyState(VK_RIGHT) && s->dir != left )
		{
			s->dir = right;
		}
		else if(GetAsyncKeyState(VK_ESCAPE))
		{
			s->stat = Exit;
		}
		//����F3���Լ���
		else if(GetAsyncKeyState(VK_F3))
		{
			if(s->sleeptime > 0)
			{
				s->sleeptime -= 50;
			}
		}
		Sleep(s->sleeptime );
		SnakeRun(s);
		KillSelf(s);
		KillWall(s);
	}while(s->stat == ok);
	GameEnd(s);
	SetPos(18,7);
	printf("�ۣ������ĵ÷��ǣ�%d",Grade(s));
}
void KillSelf(Snake* s)
{
	pNode cur = s->pSnake ->next ;
	while(cur != NULL )
	{
		if(s->pSnake ->x == cur->x && s->pSnake ->y == cur->y )
		{
			s->stat = KillBySelf;
			break;
		}
		cur = cur->next ;
	}
}
void KillWall(Snake* s)
{
	if(s->pSnake ->x == 0 || s->pSnake ->x == 56 || s->pSnake ->y == 0 || s->pSnake ->y == 26)
	{
		s->stat = KillByWall;
	}
}
void GameEnd(Snake* s)
{
	SetPos(18,12);
	switch(s->stat)
	{
	case KillBySelf:
		printf("ɵ�ӣ��Լ�ײ���Լ��ˡ�\n");
		break;
	case KillByWall:
		printf("ɵ�ӣ���ǽײ���˰ɡ�\n");
		break;
	case Exit:
		printf("�����ˣ��˳�.\n");
		break;
	default:
		break;
	}
}
int Grade(Snake* s)
{
	pNode cur = s->pSnake ;
	int count = 0;
	int t = 0;
	while(cur != NULL)
	{
		++count;
		cur = cur->next ;
		if(s->sleeptime < 1000)
		{
			t = (1000 - s->sleeptime)/5 ;
		}
	}
	if(t > 0)  //ÿ����һ�Σ��ɼ������Ӽ��ٴ�����2��
	{
		count = t * 2 + count;
	}
	return (count - 5) ;
}
