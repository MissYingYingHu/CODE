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
			printf("玩家赢\n");
			break;
		}
		else if( p=='Y')
		{
			printf("电脑赢\n");
			break;
		}
		else if( p =='e')
		{
			printf("平局\n");
			break;
		}
		computer(arr,row,col);
		p = win(arr,row,col);
		if( p=='M')
		{
			printf("玩家赢\n");
			break;
		}
		else if( p=='Y')
		{
			printf("电脑赢\n");
			break;
		}
		else if( p=='e')
		{
			printf("平局\n");
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
	printf("请选择：-->");
	scanf("%d",&input);
	switch(input)
	{
	case 1:
		game();
		break;
	case 0:
		break;
	default:
		printf("选择错误，请重新输入\n");
		break;
	}
	}while(input);
	return 0;
}