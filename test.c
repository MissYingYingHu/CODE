#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"


void game()
{
	char p = 0;
	char arr[row][col]={0};
	init(arr,row,col);
	chess_border(arr,row,col);
	srand((unsigned int)time(NULL));
	while(1)
	{
		player(arr,row,col);
		p = win(arr,row,col);
		if( p=='M')
		{
			printf("���Ӯ\n");
			break;
		}
		else if( p=='Y')
		{
			printf("����Ӯ\n");
			break;
		}
		else if( p =='e')
		{
			printf("ƽ��\n");
			break;
		}
		computer(arr,row,col);
		p = win(arr,row,col);
		if( p=='M')
		{
			printf("���Ӯ\n");
			break;
		}
		else if( p=='Y')
		{
			printf("����Ӯ\n");
			break;
		}
		else if( p=='e')
		{
			printf("ƽ��\n");
			break;
		}
	}
}
void menu()
{
printf("-----------------------------------\n");
printf("@@@  1.play             0.exit  @@@\n");
printf("-----------------------------------\n");
}
int main()
{
	int input = 0;
	do
	{
	menu();
	printf("��ѡ��-->");
	scanf("%d",&input);
	switch(input)
	{
	case 1:
		game();
		break;
	case 0:
		break;
	default:
		printf("ѡ���������������\n");
		break;
	}
	}while(input);
	return 0;
}