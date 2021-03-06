#include<stdio.h>
#include"maze.h"

void MazeInit(Maze* m)
{
	int i = 0;
	int j = 0;
	int map[MAZE_ROW][MAZE_COL] = {{0,1,0,0,0,0},
								   {0,0,1,0,1,0},
								   {0,0,1,0,0,0},
								   {0,0,1,1,1,0},
								   {0,0,1,0,1,1},							
								   {0,0,1,0,0,0}};
	if(m == NULL)
	{
		return;
	}
	for(;i < MAZE_ROW;i++)
	{
		for(j = 0;j < MAZE_COL;j++)
		{
			m->map [i][j] = map[i][j]; 
		}
	}
}
void MazeInit2(Maze* m)
{
	int i = 0;
	int j = 0;
	int map[MAZE_ROW][MAZE_COL] = {{0,1,0,0,0,0},{0,1,1,1,1,1},{0,1,0,0,0,0},{0,1,0,0,0,0},{0,1,1,1,1,1},											{0,1,0,0,0,0}};
	if(m == NULL)
	{
		return;
	}
	for(;i < MAZE_ROW;i++)
	{
		for(j = 0;j < MAZE_COL;j++)
		{
			m->map [i][j] = map[i][j]; 
		}
	}
}
void MazeInit3(Maze* m)
{
	int i = 0;
	int j = 0;
	int map[MAZE_ROW][MAZE_COL] = {{0,1,0,0,0,0},
								   {0,0,1,1,1,0},
								   {0,0,1,0,1,0},
								   {1,1,1,1,1,0},
								   {0,0,1,0,1,1},							
								   {0,0,1,0,0,0}};
	if(m == NULL)
	{
		return;
	}
	for(;i < MAZE_ROW;i++)
	{
		for(j = 0;j < MAZE_COL;j++)
		{
			m->map [i][j] = map[i][j]; 
		}
	}
}
int Exist(Maze* m,Point cur)
{
	//1.是否在地图上
	//2.改点的值是否为 1
	if(cur.col < 0 || cur.row < 0 || cur.col > MAZE_COL || cur.row > MAZE_ROW)
	{
		return 0;
	}
	else
	{
		if(m->map[cur.row ][cur.col ] == 1)
		{
			return 1;
		}
	}
	return 0;
}
void Mark(Maze* m,Point cur)
{
	m->map [cur.row ][cur.col ] = 2;
}
int Exit(Maze* m,Point cur,Point entry)
{
	if(cur.col == 0 || cur.row == 0 || cur.col == MAZE_COL - 1 || cur.row == MAZE_ROW - 1)
	{
		if(cur.col == entry.col && cur.row == entry.row )
		{
			return 0;
		}
		return 1;
	}
	return 0;
}
void _HasPath(Maze* m,Point cur,Point entry)
{
	Point up = {0,0};
	Point right = {0,0};
	Point down = {0,0};
	Point left = {0,0};
	//1.判断当前节点是否存在
	if( Exist(m,cur) == 0)
	{
		return;
	}
	//2.标记当前节点是走过的节点（走过的记为2）
	Mark(m,cur);
	//3.判断是否是出口点（①要落在边缘上②并且不是入口点）
	if(Exit(m,cur,entry))
	{
		printf("Success.\n");
		return;
	}
	//4.按照顺时针方向探测周围的点，如果周围节点不为1，直接返回返回
		up.row = cur.row - 1;
		up.col = cur.col ;
		_HasPath(m,up,entry);

		right.row = cur.row ;
		right.col = cur.col + 1;
		_HasPath(m,right,entry);

		down.row = cur.row + 1;
		down.col = cur.col ;
		_HasPath(m,down,entry);

		left.row = cur.row ;
		left.col = cur.col - 1;
		_HasPath(m,left,entry);
		return;
}
void HasPath(Maze* m,Point entry)
{
	if(m == NULL)
	{
		return;
	}
	//第一个entry当做当前节点，第二个entry记为迷宫入口
	_HasPath(m,entry,entry);
}
//非递归版的简单迷宫
void _HasPathByLoop(Maze* m,Point cur,Point entry)
{
	seqstack stack;
	Point value = {0,0};
	Point up = {0,0};
	Point right = {0,0};
	Point down = {0,0};
	Point left = {0,0};
	InitStack(&stack);
	//1.判断当前点是否能存在
	if(Exist(m,entry) == 0)
	{
		return;
	}
	//2.标记入口点走过了，将入口点入栈
	Mark(m,entry);
	PushStack(&stack,entry);
	//3.进入循环，取栈顶元素为当前点（看当前栈顶元素是否是出口，如果是出口，就直接返回）
	while(TopStack(&stack,&value))
	{
		if(Exit(m,value,entry))
		{
			printf("Success.\n");
			return;
		}
		//4.按照一定的顺序判断当前点的4个邻接点能否落脚
		up = value;
		up.row -= 1;
		//5.如果某个邻接点能够落脚，就将当前点标记，然后入栈
		//  入栈后，则又进入一个循环
		if(Exist(m,up))
		{
			Mark(m,up);
			PushStack(&stack,up);
			continue;
		}
		right = value;
		right.col += 1 ;
		if(Exist(m,right))
		{
			Mark(m,right);
			PushStack(&stack,right);
			continue;
		}
		down = value;
		down.row += 1;
		if(Exist(m,down))
		{
			Mark(m,down);
			PushStack(&stack,down);
			continue;
		}
		left = value;
		left.col -= 1 ;
		if(Exist(m,left))
		{
			Mark(m,left);
			PushStack(&stack,left);
			continue;
		}
		//6.如果当前点的所有邻接点都不能落脚，就应该把该元素出栈，然后进入循环再次判断
		PopStack(&stack);
	}
}
void HasPathByLoop(Maze* m,Point entry)
{
	if(m == NULL)
	{
		return;
	}
	_HasPathByLoop(m,entry,entry);
}
/////////////////////////////////////////////////////
////多出口的简单迷宫不带环:求最短路线////////////////
void shortPath(Maze* m,Point cur,Point entry,seqstack* _short,seqstack* _cur)
{
	Point up = {0,0};
	Point right = {0,0};
	Point down = {0,0};
	Point left = {0,0};
	//1.判断当前点能否落脚
	if(Exist(m,cur) == 0)
	{
		return;
	}
	//2.如果可以落脚，标记当前点,并把当前点入栈到_cur这个栈
	Mark(m,cur);
	PushStack(_cur,cur);
	if(Exit(m,cur,entry))
	{
		//3.判断当前点是不是出口，如果是出口，比较_short和_cur的长短，或者_short为空，如果_short比较短，就把_cur			替换到_short中
		if((SizeStack(_cur) < SizeStack(_short)) || (SizeStack(_short) == 0))
		{
			AssignStack(_cur,_short);
			printf("找到了一条相对较短的路线\n");
			ShowStack(_short);
			printf("short:%d  cur:%d\n",_short->size,_cur->size );
		}
		//让_cur出栈，返回到上一层，找其它的出口
		PopStack(_cur);
	}
	//4.看是否是出口，递归的调用该函数，完成邻接点的探测
	up = cur;
	up.row -= 1;
	shortPath(m,up,entry,_short,_cur);
	right = cur;
	right.col += 1;
	shortPath(m,right,entry,_short,_cur);
	down = cur;
	down.row += 1;
	shortPath(m,down,entry,_short,_cur);
	left = cur;
	left.col -= 1;
	shortPath(m,left,entry,_short,_cur);
	//5.如果邻接点都不能落脚，就把当前点出栈
	PopStack(_cur);
	return;
}
void HasPathMuch(Maze* m,Point entry)
{
	seqstack _short;
	seqstack _cur;
	InitStack(&_short);
	InitStack(&_cur);
	if(m == NULL)
	{
		return;
	}
	shortPath(m,entry,entry,&_short,&_cur);
	printf("最短的路线是：\n");
	ShowStack(&_short);
}
//带环的多出口的迷宫
int ExistByCycle(Maze* m,Point cur,Point pre)
{
	//1.是否在地图上
	//2.改点的值是否为 1
	//3.判定当前点的值和前一个点的值的大小
	if(cur.col < 0 || cur.row < 0 || cur.col > MAZE_COL || cur.row > MAZE_ROW)
	{
		return 0;
	}
	if(m->map[cur.row ][cur.col ] == 1)
	{
		return 1;
	}
	if(pre.row >0 && pre.row < MAZE_ROW && pre.col > 0 && pre.col < MAZE_COL)
	{
		if(m->map[cur.row ][cur.col ] == 1 && m->map [cur.row ][cur.col ] - 1 > m->map [pre.row ][pre.col ])
		{
			return 1;
		}
	}
	return 0;
}
void MarkByCycle(Maze* m,Point cur,Point pre)
{
	if(pre.row < 0 || pre.col < 0 || pre.row >= MAZE_ROW || pre.col >= MAZE_COL)
	{
		m->map [cur.row  ][cur.col] = 2;
		return;
	}
	m->map [cur.row ][cur.col ] = m->map [pre.row ][pre.col ] + 1;
}
void _HasPathByCycle(Maze* m,Point cur,Point pre,Point entry,seqstack* _short,seqstack* _cur)
{
	Point up = {0,0};
	Point right = {0,0};
	Point down = {0,0};
	Point left = {0,0};
	//1.判定当前点能否落脚
	if(ExistByCycle(m,cur,pre) == 0)
	{
		return;
	}
	//2.如果可以落脚，就标记当前点，把当前点入栈到_cur
	MarkByCycle(m,cur,pre);
	PushStack(_cur,cur);
	if(Exit(m,cur,entry))
	{
		//3.判定当前点是否是出口
		//  如果_cur比较短，就替换给_short
		if((SizeStack(_cur) < SizeStack(_short)) || (SizeStack(_short) == 0))
		{
			AssignStack(_cur,_short);
			printf("找到了一条相对较短的路线\n");
			ShowStack(_short);
			printf("short:%d  cur:%d\n",_short->size,_cur->size );
		}
		//	出栈，进入下一轮的递归找其它出口
		PopStack(_cur);
	}
	//4.如果不是出口，就要遍历周围的点
	up = cur;
	up.row -= 1;
	_HasPathByCycle(m,up,cur,entry,_short,_cur);
	right = cur;
	right.col += 1;
	_HasPathByCycle(m,right,cur,entry,_short,_cur);
	down = cur;
	down.row += 1;
	_HasPathByCycle(m,down,cur,entry,_short,_cur);
	left = cur;
	left.col -= 1;
	_HasPathByCycle(m,left,cur,entry,_short,_cur);
	//5.四周探测完了，就出栈
	PopStack(_cur);
	return;
}
void HasPathByCycle(Maze* m,Point entry)
{
	seqstack _short;
	seqstack _cur;
	Point pre = {-1,-1};
	InitStack(&_short);
	InitStack(&_cur);
	if(m == NULL)
	{
		return;
	}
	_HasPathByCycle(m,entry,pre,entry,&_short,&_cur);
}
