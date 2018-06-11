#pragma once

#define BUNDER  "□"
#define FOOD  "○"
#define C 20
#define L 13
enum Dir
{
	up,
	left,
	down,
	right,
};
enum Stat
{
	ok,
	KillBySelf,
	KillByWall,
	Exit,
};
typedef struct Node
{
	int x;
	int y;
	struct Node* next;
}Node,*pNode;
typedef struct Snake
{
	pNode pSnake;   //指向蛇的指针
	pNode pFood;    
	enum Dir dir;      //蛇的运动方向
	enum Stat stat;     //蛇的状态
	int sleeptime;
}Snake,*pSnake;

//进入游戏前的界面
void ShowWelcome();

//设置光标的位置
void SetPos(int x,int y);

//初始化游戏的地图
void CreateMap();

//初始化蛇的各种状态以及初始化蛇
void InitSnake(Snake* s);

//初始化蛇的食物
void InitFood(Snake* s); //比较麻烦，封装为函数

//让蛇动起来
void SnakeRun(Snake* s);

//让用户可以控制蛇的移动
void SnakeRun2(Snake* s);

//判断蛇有没有撞到自己
void KillSelf(Snake* s);

//判断蛇有没有撞到墙
void KillWall(Snake* s);

//游戏结束
void GameEnd(Snake* s);

//统计游戏的分数
int Grade(Snake* s);