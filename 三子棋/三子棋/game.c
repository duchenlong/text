#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//初始化棋盘
void InitBoard(char board[][ROW], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//给二维数组每个位置赋值为空格
		}
	}
}
//展示棋盘
void ShowBoard(char board[][ROW], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			printf("___|");
		}
		printf("\n");
	}
}
//玩家移动
void PlayerMove(char board[][ROW])
{
	int x=0, y=0;
	printf("请输入棋子的位置：");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if ((x > 0 && x<4) && (y>0 && y <4))//判断输入位置是否合法
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("该位置有棋子了，请重新输入！\n");
			}
		}
		else
		{
			printf("输入位置不合法，请重新输入！\n");
		}
	}
	system("cls");//清屏操作
}
//判断是否下满棋盘
int IsFull(char board[][ROW])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')//如果棋盘没有下满，返回0
			{
				return 0;
			}
		}
	}
	return 1;//棋盘下满了，返回1
}
//判断输赢
int IsWin(char board[][ROW], int row, int col)
{
	int x = 0, y = 0;
	//判断是否有横行三个相同
	for (x = 0; x < row; x++)
	{
		if (board[x][y] == board[x][y + 1] && board[x][y + 1] == board[x][y + 2] && board[x][y] != ' ')
		{
			return board[x][y];
		}
	}
	//判断/是否相同
	if (board[x][x] == board[x - 1][x - 1] && board[x - 1][x - 1] == board[x - 2][x - 2] && board[x][x] != ' ')
	{
		return board[x][x];
	}
	x = 0;
	//判断竖行是否三个相同
	for (y = 0; y < row; y++)
	{
		if (board[x][y] == board[x + 1][y] && board[x + 1][y] == board[x + 2][y] && board[x][y]!= ' ')
		{
			return board[x][y];
		}
	}
	//判断\是否相同
	if (board[x][x] == board[x + 1][x + 1] && board[x + 1][x + 1] == board[x + 2][x + 2] && board[x][x]!= ' ')
	{
		return board[x][x];
	}
	if (IsFull(board))//判断是否下满棋盘
	{
		return 1;
	}
	return 0;
}

//电脑移动
void ComputerMove(char board[][ROW])
{
	int x = 0, y = 0;
	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;
		if (board[x][y] != 'x'&&board[x][y] != 'o')
		{
			board[x][y] = 'o';
			break;
		}
	}
}