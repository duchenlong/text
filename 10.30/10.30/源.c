#define _CRT_SECURE_NO_WARNINGS 1


//��������(����)
//
//���µ�10������
//+ -- + -- + -- +
//| | | |
//+-- + -- + -- + -- +
//| | | | |
//+-- + -- + -- + -- +
//| | | |
//+-- + -- + -- +
//
//�������ʾ�����⣬Ҳ���Բο���ͼ1.jpg����
//
//����0~9�����֡�Ҫ���������������ֲ������ڡ�
//�����ҡ����¡��ԽǶ������ڣ�
//
//һ���ж����ֿ��ܵ�����������
//
//����д��ʾ������Ŀ��������
//ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�

#include<stdio.h>
#include<math.h>

int ans = 0;
int my_arr[10] = { 0 };
int arr[10] = { 0 };
int visit[3][4] = { 0 };
int count = 0;
int dir[8][2] = { 0, -1, 0, 1, 1, 0, -1, 0, 1, 1, 1, -1, -1, -1, -1, 1 };
//��ʾ��Χ��λ��

int judge(const int x,const int y)
{
	int i = 0;
	int tx = 0;
	int ty = 0;
	for (i = 0; i < 8; i++)
	{
		tx = x + dir[i][0];
		ty = y + dir[i][1];
		if ((tx<0) || (tx>2) || (ty<0) || (ty>3))
		{
			continue;
		}
		if (visit[tx][ty] == -10)
		{
			continue;
		}
		if (abs(visit[tx][ty] - visit[x][y] == 1))
		{
			return 0;
		}
	}
	return 1;
}

void slove()
{
	int i = 0;
	int j = 0;
	int n = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if ((i == 0 && j == 0) || (i == 2 && j == 3))
			{
				visit[i][j] = -10;
			}
			else
			{
				visit[i][j] = arr[n];
				n++;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			if ((i == 0 && j == 0) || (i == 2 && j == 3))
			{
				continue;
			}
			else
			{
				if (!judge(i,j))
				{
					return;
				}
			}
		}
	}
	ans++;
}


void dfs(int index)
{
	if (index == 10)
	{
		slove();
		return;
	}
	else
	{
		int i = 0;
		for (i = 0; i <= 9; i++)
		{
			if (!my_arr[i])
			{
				my_arr[i] = 1;
				arr[count] = i;
				count++;
				dfs(index + 1);
				arr[count] = 0;
				count--;
				my_arr[i] = 0;
			}
		}
	}
}

int main()
{
	dfs(0);
	printf("%d", ans);
	return 0;
}