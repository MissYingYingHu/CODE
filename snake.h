#pragma once

#define BUNDER  "��"
#define FOOD  "��"
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
	pNode pSnake;   //ָ���ߵ�ָ��
	pNode pFood;    
	enum Dir dir;      //�ߵ��˶�����
	enum Stat stat;     //�ߵ�״̬
	int sleeptime;
}Snake,*pSnake;

//������Ϸǰ�Ľ���
void ShowWelcome();

//���ù���λ��
void SetPos(int x,int y);

//��ʼ����Ϸ�ĵ�ͼ
void CreateMap();

//��ʼ���ߵĸ���״̬�Լ���ʼ����
void InitSnake(Snake* s);

//��ʼ���ߵ�ʳ��
void InitFood(Snake* s); //�Ƚ��鷳����װΪ����

//���߶�����
void SnakeRun(Snake* s);

//���û����Կ����ߵ��ƶ�
void SnakeRun2(Snake* s);

//�ж�����û��ײ���Լ�
void KillSelf(Snake* s);

//�ж�����û��ײ��ǽ
void KillWall(Snake* s);

//��Ϸ����
void GameEnd(Snake* s);

//ͳ����Ϸ�ķ���
int Grade(Snake* s);