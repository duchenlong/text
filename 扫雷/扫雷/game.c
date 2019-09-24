#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//初始化棋盘
void InitBorad(char board[][ROWS], int row, int col, int set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;	
		}
	}
}

//打印棋盘
void show(char board[][ROWS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("====================================\n");
	for (j = 0; j <= col-2; j++)
	{
		printf(" %d", j);
	}
	printf("\n");
	for (i = 1; i < row-1; i++)
	{
		printf(" %d ", i);
		for (j = 1; j < col-1; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//设置雷
void SetMine(char mine[][ROWS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 0, j = 0;
	printf("请输入侦查的位置： ");
	scanf("%d%d", &i, &j);
	int count = 0;
	do
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if ((mine[x][y] == '0') && ((x != i) && (y != j)))
		{
			mine[x][y] = '1';
			count++;
		}
	} while (MINE_NUM > count);
}

//判断一个位置周围有多少雷
int Saomiao(char mine[][COLS], int i, int j)
{
	return mine[i][j - 1]
		+ mine[i][j + 1]
		+ mine[i - 1][j - 1]
		+ mine[i - 1][j]
		+ mine[i - 1][j + 1]
		+ mine[i + 1][j - 1]
		+ mine[i + 1][j]
		+ mine[i + 1][j + 1] - 8 * '0';
}


//展开附近没有雷的区域
void PutZhan(char mine[][ROWS], char mineInfo[][ROWS], int i, int j)
{
	if (Saomiao(mine, i, j) == 0)//表示该位置附近没有雷，可以展开
	{
		mineInfo[i][j] = '0';
		if ((i - 1) >= 1 && (i - 1) <= ROW && (j - 1) >= 1 && (j - 1) <= COL&&mineInfo[i - 1][j - 1] == '*')
			PutZhan(mine, mineInfo, i - 1, j - 1);
		if ((i) >= 1 && (i) <= ROW && (j - 1) >= 1 && (j - 1) <= COL&&mineInfo[i][j - 1] == '*')
			PutZhan(mine, mineInfo, i, j - 1);
		if ((i + 1) >= 1 && (i + 1) <= ROW && (j - 1) >= 1 && (j - 1) <= COL&&mineInfo[i + 1][j - 1] == '*')
			PutZhan(mine, mineInfo, i + 1, j - 1);
		if ((i + 1) >= 1 && (i + 1) <= ROW && (j) >= 1 && (j) <= COL&&mineInfo[i + 1][j] == '*')
			PutZhan(mine, mineInfo, i + 1, j);
		if ((i + 1) >= 1 && (i + 1) <= ROW && (j + 1) >= 1 && (j + 1) <= COL&&mineInfo[i + 1][j + 1] == '*')
			PutZhan(mine, mineInfo, i + 1, j + 1);
		if ((i) >= 1 && (i) <= ROW && (i + 1) >= 1 && (j + 1) <= COL&&mineInfo[i][j + 1] == '*')
			PutZhan(mine, mineInfo, i, j + 1);
		if ((i - 1) >= 1 && (i - 1) <= ROW && (j + 1) >= 1 && (j + 1) <= COL&&mineInfo[i - 1][j + 1] == '*')
			PutZhan(mine, mineInfo, i - 1, j + 1);
		if ((i - 1) >= 1 && (i - 1) <= ROW && (j) >= 1 && (j) <= COL&&mineInfo[i - 1][j] == '*')
			PutZhan(mine, mineInfo, i - 1, j);
	}
	else
	{
		mineInfo[i][j] = Saomiao(mine, i, j) + '0';//返回该位置周围雷的数量
	}
}

//判断雷是不是都排出来了
int isWin(char mineInfo[][ROWS], int row, int col)
{
	int count = 0;//记录没有排出来位置的个数
	int i = 0, j = 0;
	for (i = 1; i < row - 1; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if (mineInfo[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}

//扫雷
void FindMine(char mine[][ROWS], char mineInfo[][ROWS], int row, int col)
{
	int i = 0, j = 0;
	while (isWin(mineInfo,ROWS,COLS)> MINE_NUM)
	{
		printf("请输入侦查的位置： ");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= 9 && j >= 1 && j <= 9)
		{
			if (mineInfo[i][j] != '0')
			{
				if (mine[i][j] == '0')
				{
					int num = Saomiao(mine, i, j);
					mineInfo[i][j] = num + '0';//输入位置附近雷的数量
					if (mineInfo[i][j] == '0')
					{
						PutZhan(mine, mineInfo, i, j);//将一片都没有雷的地区展开
					}
					//show(mine, ROWS, COLS);
					show(mineInfo, ROWS, COLS);//每走完一步，打印新的棋盘
				}
				else
				{
					printf("砰~~被炸死了\n");
					break;
				}
			}
			else
			{
				printf("该位置已经被发现\n");
			}
			
		}
		else
		{
			printf("请输入合法的位置！请重新输入~\n");
		}
		
	}
	
}