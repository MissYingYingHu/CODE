#include<stdio.h>
#include"maze.h"
#include<windows.h>

#define TEST_HEADER printf("\n==============%s===============\n",__FUNCTION__)
void MazePrint(Maze* m)
{
	int i = 0;
	int j = 0;
	for(i = 0;i < MAZE_ROW;i++)
	{
		for(j = 0;j < MAZE_COL;j++)
		{
			printf("%d   ",m->map [i][j]);
		}
		printf("\n");
	}
}
void Test1()
{
	Maze m;
	Point entry = {4,5};
	TEST_HEADER;
	MazeInit(&m);
	MazePrint(&m);
	HasPath(&m,entry);
	MazePrint(&m);
}
void Test2()
{
	Maze m;
	Point entry = {4,5};
	TEST_HEADER;
	MazeInit(&m);
	MazePrint(&m);
	HasPathByLoop(&m,entry);
	MazePrint(&m);
}
void Test3()
{
	Maze m;
	Point entry = {5,1};
	TEST_HEADER;
	MazeInit2(&m);
	MazePrint(&m);
	HasPathMuch(&m,entry);
	MazePrint(&m);
}
void Test4()
{
	Maze m;
	Point entry = {5,2};
	TEST_HEADER;
	MazeInit3(&m);
	MazePrint(&m);
	HasPathByCycle(&m,entry);
	MazePrint(&m);
}
/////////////////////////////////
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	system("pause");
	return 0;
}