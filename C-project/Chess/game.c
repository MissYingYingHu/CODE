#include"game.h"

void init(char arr[row][col],int r,int c)//初始化数组
{
	int i =0;
	int j =0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			arr[i][j]=' ';
		}
	}
}
void chess_border(char arr[][col])//设置棋盘
{
	int i =0;
	for(i=0;i<row;i++)
	{
		printf(" %c | %c | %c | %c | %c \n", arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4]);
		if(i != (row - 1))
		{
			printf("---|---|---|---|---\n");
		}
	}
}
void player(char arr[][col],int r,int c)//玩家走
{
	int i =0,j = 0;
	while(1)
	{
		printf("请玩家输入坐标：\n");
		scanf("%d%d",&i,&j);
		if(((i - 1)>=0) && ((i - 1)<r) && ((j - 1)>=0)&&((j - 1)<c))
		{
			if(arr[i - 1][j - 1]==' ')
			{
				arr[i - 1][j - 1]='M';
				chess_border(arr);
				break;
			}
			else
			{
			printf("下标输入有误，请重新输入\n");
			}
		}
		else
		{
			printf("下标输入有误，请重新输入\n");
		}
	
	}
}
void computer(char arr[row][col])//电脑走
{
	while(1)
	{
		int i = rand()%5;
		int j = rand()%5;//随机产生一个坐标
			if(arr[i][j] == ' ')
			{
				printf("请电脑走：\n");
				arr[i][j]='Y';
				chess_border(arr);
				break;
			}
	}
}
char win(char arr[row][col],int r,int c)//判赢
{
	int i =0;
	int j =0;
	for(i=0;i<row;i++)
	{
		if((arr[i][0] == arr[i][1]) && 
			(arr[i][1] == arr[i][2]) && 
			(arr[i][2] == arr[i][3]) && 
			(arr[i][3] == arr[i][4]) &&
			arr[i][2] != ' ')
			{
				return arr[i][1];
			}
	}
	for(j=0;j<col;j++)
	{
		if((arr[0][j] == arr[1][j]) &&
			(arr[1][j] == arr[2][j]) &&
			(arr[2][j] == arr[3][j]) &&
			(arr[3][j] == arr[4][j]) &&
			arr[2][j] != ' ')
			{
				return arr[1][j];
			}
	}
	if((arr[0][0] == arr[1][1]) &&
		(arr[1][1] == arr[2][2]) &&
		(arr[2][2] == arr[3][3]) &&
		(arr[3][3] == arr[4][4]) &&
		arr[2][2]!=' ')
	{
		return arr[2][2];
	}
	if((arr[0][4] == arr[1][3]) &&
		(arr[1][3] == arr[2][2]) &&
		(arr[2][2] == arr[3][1]) &&
		(arr[3][1] == arr[4][0]) &&
		arr[2][0]!=' ')
	{
		return arr[2][0];
	}	
	if(equal(arr,r,c))
	{
		return 'e';
	}
	return ' ';
}
 int equal(char arr[row][col],int r,int c)//判平局
{
	int i =0;
	int j =0;
	for(i = 0;i < r;i++)
	{
		for(j = 0;j < c;j++)
		{
			if(arr[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
