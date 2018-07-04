#ifndef _GAME_H__
#define _GAME_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define row 5
#define col 5

	void init(char arr[row][col],int r,int c);
	void chess_border(char arr[row][col]);
	void player(char arr[row][col],int r,int c);
	void computer(char arr[row][col]);
	char win(char arr[row][col],int r,int c);
	int equal(char arr[row][col],int r,int c);

#endif//_GAME_H__
