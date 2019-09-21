#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 3
#define COL 3
//��ʼ������
void InitBoard(char board[][ROW], int row, int col);
//չʾ����
void ShowBoard(char board[][ROW], int row, int col);
//����ƶ�
void PlayerMove(char board[][ROW]);
//�ж���Ӯ
int IsWin(char board[][ROW], int row, int col);
//�����ƶ�
void ComputerMove(char board[][ROW]);
//�ж��Ƿ���������
int IsFull(char board[][ROW]);
#endif