#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

//��ʼ������
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

//��ӡ����
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

//������
void SetMine(char mine[][ROWS], int row, int col)
{
	int x = 0;
	int y = 0;
	int i = 0, j = 0;
	printf("����������λ�ã� ");
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

//�ж�һ��λ����Χ�ж�����
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


//չ������û���׵�����
void PutZhan(char mine[][ROWS], char mineInfo[][ROWS], int i, int j)
{
	if (Saomiao(mine, i, j) == 0)//��ʾ��λ�ø���û���ף�����չ��
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
		mineInfo[i][j] = Saomiao(mine, i, j) + '0';//���ظ�λ����Χ�׵�����
	}
}

//�ж����ǲ��Ƕ��ų�����
int isWin(char mineInfo[][ROWS], int row, int col)
{
	int count = 0;//��¼û���ų���λ�õĸ���
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

//ɨ��
void FindMine(char mine[][ROWS], char mineInfo[][ROWS], int row, int col)
{
	int i = 0, j = 0;
	while (isWin(mineInfo,ROWS,COLS)> MINE_NUM)
	{
		printf("����������λ�ã� ");
		scanf("%d%d", &i, &j);
		if (i >= 1 && i <= 9 && j >= 1 && j <= 9)
		{
			if (mineInfo[i][j] != '0')
			{
				if (mine[i][j] == '0')
				{
					int num = Saomiao(mine, i, j);
					mineInfo[i][j] = num + '0';//����λ�ø����׵�����
					if (mineInfo[i][j] == '0')
					{
						PutZhan(mine, mineInfo, i, j);//��һƬ��û���׵ĵ���չ��
					}
					//show(mine, ROWS, COLS);
					show(mineInfo, ROWS, COLS);//ÿ����һ������ӡ�µ�����
				}
				else
				{
					printf("��~~��ը����\n");
					break;
				}
			}
			else
			{
				printf("��λ���Ѿ�������\n");
			}
			
		}
		else
		{
			printf("������Ϸ���λ�ã�����������~\n");
		}
		
	}
	
}