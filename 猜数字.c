#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
void menu()
{
	printf("------------------------------------\n");
	printf("������1.play          0.exit��������\n");
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
		printf("������");
		scanf("%d",&i);
		if(i == num)
		{
			printf("��ϲ�㣬�¶���!\n");
			break;
		}
		else
		{
			if(i > num)
			{
				printf("�´��ˣ����²�\n");
			}
			else
			{
				printf("��С��\n");
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
		printf("��ѡ��");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("����������������롣\n");
				break;
		}
	}while(input);
	system("pause");
	return 0;
}