#include"game2.h"

void initborder(char ball[ROWS][COLS],int row,int col,char set)
{
	int i =0;
	int j =0;
	for(i=0;i<ROWS;i++)
	{
		for(j=0;j<COLS;j++)
		{
			ball[i][j]=set;
		}
	}
}

void display(char ball[ROWS][COLS],int row,int col)
{
	int i =0;
	int j =0;
	for(j=1;j<=COL;j++)
	{
		printf("%4d",j);
	}
		printf("\n");
	for(i=1;i<=ROW;i++)
	{
		printf("%2d ",i);
		for(j=1;j<=COL;j++)
		{
			printf("%c   ",ball[i][j]);
		}
		printf("\n");
	}
}

void set_ball(char ball[ROWS][COLS],int row,int col,int count)
{	
	while(count)
	{
		int x=rand()%ROW+1;
		int y=rand()%COL+1;
		if(ball[x][y]=='0')
		{
			ball[x][y]='1';
			count--;
		}
	}
}
void print(char ball[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int x = 0;
	int y = 0;
	int q = 0;//Ϊ��һ����Ϸ����������ı���
	int w = 0;
	while(1)
	{
		is_win(show);
		printf("���������꣺");
		scanf("%d%d",&x,&y);
		if(x>=0 && x<=ROW && y>=0 && y<=COL)
			{
				if(q==0 && ball[x][y]=='1' )//&& p==0)//��֤��һ�β�������Ϸ
					{
						first_ball(ball,x,y);
						q++;
						display(show,ROWS,COLS);
					}
				else 
					if( ball[x][y]=='1' && q!=0 )
					{
						printf("��ϲ�������\n");
						display(ball,ROWS,COLS);
						break;
					}
					else 
						if(ball[x][y]=='0')
						{
							expand_ball(ball,show,x,y);
							//show[x][y]=count_ball(ball,x,y)+'0';//���Բ鿴ĳһ���׵ĸ���
							q++;
							display(show,ROWS,COLS);
						}
	}
		else
		{
			printf("�����������������\n");
		}

	}
}
void first_ball(char ball[ROWS][COLS],int x,int y)
{
	int i = 0;
	int j = 0;
	ball[i][j]='0';
	while(1)
	{
		i=rand()%ROW+1;
		j=rand()%COL+1;
		if(ball[i][j]=='0' && i!=x && j!=y)
		{
			ball[i][j]='1';
			break;
		}
	}
}
int count_ball(char ball[ROWS][COLS],int x,int y)
{
		
	return  ball[x-1][y]+
		    ball[x-1][y-1]+
			ball[x][y-1]+
			ball[x+1][y-1]+
		    ball[x+1][y]+
			ball[x+1][y+1]+
		    ball[x][y+1]+
			ball[x-1][y+1]-'0'*8;
}
void expand_ball(char ball[ROWS][COLS],char show[ROWS][COLS],int x,int y)
{
	if(x>=0 && x<=ROW && y>=0 && y<=COL)
	{
		if(count_ball(ball,x,y) == 0)
		{
			show[x][y]=' ';
			if(show[x-1][y]=='*')
			{
				expand_ball(ball,show,x-1,y);
			}
			if(show[x-1][y-1]=='*')
			{
				expand_ball(ball,show,x-1,y-1);
			}
			if(show[x][y-1]=='*')
			{
				expand_ball(ball,show,x,y-1);
			}
			if(show[x+1][y-1]=='*')
			{
				expand_ball(ball,show,x+1,y-1);
			}
			if(show[x+1][y]=='*')
			{
				expand_ball(ball,show,x+1,y);
			}
			if(show[x+1][y+1]=='*')
			{
				expand_ball(ball,show,x+1,y+1);
			}
			if(show[x][y+1]=='*')
			{
				expand_ball(ball,show,x,y+1);
			}
			if(show[x-1][y+1]=='*')
			{
				expand_ball(ball,show,x-1,y+1);
			}
		}
		else
		{
				show[x][y] = count_ball(ball,x,y)+'0';
		}
	}
}
void is_win(char show[ROWS][COLS])
{
	int c = 0;
	int i = 0;
	int j = 0;
	for(i=1;i<=ROW;i++)
	{
		for(j=1;j<=COL;j++)
		{
			if(show[i][j]=='*')
			{
				c++;
			}
		}
	}
	if(c==easy_count)
	{
		printf("��ϲ�㣬Ӯ��\n");
	}
}

