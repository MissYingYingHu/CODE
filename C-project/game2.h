#ifndef _GAME2_H__
#define _GAME2_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 10
#define COL 10
#define ROWS ROW+2
#define COLS COL+2
#define easy_count 98

void initborder(char ball[ROWS][COLS],int row,int col,char set);
void display(char ball[ROWS][COLS],int row,int col);
void set_ball(char ball[ROWS][COLS],int row,int col,int count);
void print(char ball[ROWS][COLS],char show[ROWS][COLS],int row,int col);
int count_ball(char ball[ROWS][COLS],int row,int col);
void expand_ball(char ball[ROWS][COLS],char show[ROW][COL],int x,int y);
void first_ball(char ball[ROWS][COLS],int x,int y);
void is_win(char show[ROWS][COLS]);


#endif //_GAME2_H__