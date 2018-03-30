#include<stdio.h>
#include"snake.h"
#include<time.h>
#include<windows.h>

int main()
{
	Snake s;
	srand(time(NULL));
	ShowWelcome();
	CreateMap();
	InitSnake(&s);
	InitFood(&s) ;
	SnakeRun2(&s);
	printf("\n");
	system("pause");
	return 0;
}