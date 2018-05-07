#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
void menu()
{
	printf("------------------------------------\n");
	printf("￥￥￥1.play          0.exit￥￥￥￥\n");
	printf("------------------------------------\n");
}
void game()
{
	int i=0;
	int num=0;
	srand((unsigned int)time(NULL));
	num=rand()%10;

	while(1)
	{
		printf("猜数：");
		scanf("%d",&i);
		if(i == num)
		{
			printf("恭喜你，猜对啦!\n");
			break;
		}
		else
		{
			if(i > num)
			{
				printf("猜大了，重新猜\n");
			}
			else
			{
				printf("猜小了\n");
			}
		}
	}
}
int main()
{
	int input =0;
	do
	{
		menu();
		printf("请选择：");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("输入错误，请重新输入。\n");
				break;
		}
	}while(input);
	system("pause");
	return 0;
}