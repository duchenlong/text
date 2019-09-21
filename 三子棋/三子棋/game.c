#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
//��ʼ������
void InitBoard(char board[][ROW], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//����ά����ÿ��λ�ø�ֵΪ�ո�
		}
	}
}
//չʾ����
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
//����ƶ�
void PlayerMove(char board[][ROW])
{
	int x=0, y=0;
	printf("���������ӵ�λ�ã�");
	while (1)
	{
		scanf("%d%d", &x, &y);
		if ((x > 0 && x<4) && (y>0 && y <4))//�ж�����λ���Ƿ�Ϸ�
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("��λ���������ˣ����������룡\n");
			}
		}
		else
		{
			printf("����λ�ò��Ϸ������������룡\n");
		}
	}
	system("cls");//��������
}
//�ж��Ƿ���������
int IsFull(char board[][ROW])
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')//�������û������������0
			{
				return 0;
			}
		}
	}
	return 1;//���������ˣ�����1
}
//�ж���Ӯ
int IsWin(char board[][ROW], int row, int col)
{
	int x = 0, y = 0;
	//�ж��Ƿ��к���������ͬ
	for (x = 0; x < row; x++)
	{
		if (board[x][y] == board[x][y + 1] && board[x][y + 1] == board[x][y + 2] && board[x][y] != ' ')
		{
			return board[x][y];
		}
	}
	//�ж�/�Ƿ���ͬ
	if (board[x][x] == board[x - 1][x - 1] && board[x - 1][x - 1] == board[x - 2][x - 2] && board[x][x] != ' ')
	{
		return board[x][x];
	}
	x = 0;
	//�ж������Ƿ�������ͬ
	for (y = 0; y < row; y++)
	{
		if (board[x][y] == board[x + 1][y] && board[x + 1][y] == board[x + 2][y] && board[x][y]!= ' ')
		{
			return board[x][y];
		}
	}
	//�ж�\�Ƿ���ͬ
	if (board[x][x] == board[x + 1][x + 1] && board[x + 1][x + 1] == board[x + 2][x + 2] && board[x][x]!= ' ')
	{
		return board[x][x];
	}
	if (IsFull(board))//�ж��Ƿ���������
	{
		return 1;
	}
	return 0;
}

//�����ƶ�
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