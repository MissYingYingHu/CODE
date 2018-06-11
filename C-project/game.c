
#include"game.h"

void init(char arr[row][col],int r,int c)//��ʼ������
{
	int i =0;
	int j =0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			arr[i][j]=' ';
		}
	}
}
void chess_border(char arr[row][col],int r,int c)//��������
{
	int i =0;
	for(i=0;i<row;i++)
	{
		printf(" %c | %c | %c \n", arr[i][0],arr[i][1],arr[i][2]);
		if(i!=2)
		{
		printf("---|---|---\n");
		}
	}
}
void player(char arr[row][col],int r,int c)//�����
{
	int i =0,j = 0;
	while(1)
	{
		printf("������������꣺\n");
		scanf("%d%d",&i,&j);
		if((i>=0)&&(i<row)&&(j>=0)&&(j<col))
		{
			if(arr[i][j]==' ')
			{
				arr[i][j]='M';
				chess_border(arr,row,col);
				break;
			}
			else
			{
			printf("�±�������������������\n");
			}
		}
		else
		{
			printf("�±�������������������\n");
		}
	
	}
}
void computer(char arr[row][col],int r,int c)//������
{
	while(1)
	{
		int i =rand()%3;
		int j =rand()%3;//�������һ������
			if(arr[i][j]==' ')
			{
				printf("������ߣ�\n");
				arr[i][j]='Y';
				chess_border(arr,row,col);
				break;
			}
	}
}
char win(char arr[row][col],int r,int c)//��Ӯ
{
	int i =0;
	int j =0;
	for(i=0;i<row;i++)
	{
	if((arr[i][0] == arr[i][1]) && (arr[i][1] == arr[i][2]) && arr[i][2]!=' ')
		{
			return arr[i][1];
		}
	}
	for(j=0;j<col;j++)
	{
	if((arr[0][j] == arr[1][j]) && (arr[1][j] == arr[2][j]) && arr[2][j]!=' ')
		{
			return arr[1][j];
		}
	}
	if((arr[0][0] == arr[1][1]) && (arr[1][1] == arr[2][2]) && arr[2][2]!=' ')
		{
			return arr[2][2];
		}
	if((arr[0][2] == arr[1][1]) && (arr[1][1] == arr[2][0]) && arr[2][0]!=' ')
		{
			return arr[2][0];
		}	
	if(equal(arr,r,c))
	{
		return 'e';
	}
	return ' ';
}
 int equal(char arr[row][col],int r,int c)//��ƽ��
{
	int i =0;
	int j =0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(arr[i][j]==' ')
			{
				return 0;
			}
		}
	}
	return 1;
}