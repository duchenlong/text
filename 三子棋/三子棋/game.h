#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3
//初始化棋盘
void InitBoard(char board[][ROW], int row, int col);
//展示棋盘
void ShowBoard(char board[][ROW], int row, int col);
//玩家移动
void PlayerMove(char board[][ROW]);
//判断输赢
int IsWin(char board[][ROW], int row, int col);
//电脑移动
void ComputerMove(char board[][ROW]);
//判断是否下满棋盘
int IsFull(char board[][ROW]);
#endif