#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"game2.h"
void menu()
{
	printf("*********************************\n");
	printf("----1.play             0.exit----\n");
	printf("*********************************\n");
}
void game()
{
	char ball[ROWS][COLS]={0};//����
	char show[ROWS][COLS]={0};//չʾ��
	srand((unsigned int)time(NULL));
	initborder(ball,ROWS,COLS,'0');
	//display(ball,ROWS,COLS);//��ӡ����
	initborder(show,ROWS,COLS,'*');
	//display(show,ROW,COL);//��ӡչʾ��
	set_ball(ball,ROWS,COLS,easy_count);
	display(ball,ROWS,COLS);
	display(show,ROWS,COLS);
	print(ball,show,ROW,COL);
	is_win(show);
}
int main()
{	
	int input =0;
	do{
		menu();
		printf("��ѡ��-----��");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������\n");
			break;
		}
	}while(input);
return 0;
}