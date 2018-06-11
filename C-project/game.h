#ifndef _GAME_H__
#define _GAME_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define row 3
#define col 3

	void init(char arr[row][col],int r,int c);
	void chess_border(char arr[row][col],int r,int c);
	void player(char arr[row][col],int r,int c);
	void computer(char arr[row][col],int r,int c);
	char win(char arr[row][col],int r,int c);
	int equal(char arr[row][col],int r,int c);

#endif//_GAME_H__