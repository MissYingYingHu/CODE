#pragma once
#include"seqstack.h"

#define MAZE_ROW 6
#define MAZE_COL 6
//typedef struct Point
//{
//	int row;
//	int col;
//}Point;
typedef struct Maze
{
	int map[MAZE_ROW][MAZE_COL];	
}Maze;

void MazeInit(Maze* m);
void MazeInit2(Maze* m);
void MazeInit3(Maze* m);
void HasPath(Maze* m,Point entry);
void HasPathByLoop(Maze* m,Point entry);
void HasPathMuch(Maze* m,Point entry);
void HasPathByCycle(Maze* m,Point entry);