#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9

#define MINE_NUM 10

#define ROWS ROW+2
#define COLS COL+2

//≥ı ºªØ∆Â≈Ã
void InitBorad(char board[][ROWS], int row, int col,int set);
//¥Ú”°∆Â≈Ã
void show(char board[][ROWS], int row, int col);
//…Ë÷√¿◊
void SetMine(char board[][ROWS], int row, int col);
//…®¿◊
void FindMine(char mine[][ROWS], char mineInfo[][ROWS], int row, int col);


#endif