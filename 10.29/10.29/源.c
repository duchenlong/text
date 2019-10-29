#define _CRT_SECURE_NO_WARNINGS 1

//剪邮票
//
//如【图1.jpg】, 有12张连在一起的12生肖的邮票。
//现在你要从中剪下5张来，要求必须是连着的。
//（仅仅连接一个角不算相连）
//比如，【图2.jpg】，【图3.jpg】中，粉红色所示部分就是合格的剪取。
//
//请你计算，一共有多少种不同的剪取方法。
//
//请填写表示方案数目的整数。
//注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

#include<stdio.h>
#include<string.h>

int mip[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
int count = 0;
int have[13] = { 0 };
int visit[3][4] = { 0 };
int dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };

void find(const int x, const int y)
{
	int i = 0;
	int tx, ty;
	for (i = 0; i<4; i++)
	{
		tx = x + dir[i][0];
		ty = y + dir[i][1];
		if ((tx<0) || (tx >= 3) || (ty<0) || (ty >= 4))
		{
			continue;
		}
		if ((have[mip[tx][ty]] == 0) || visit[tx][ty])
		{
			continue;
		}
		visit[tx][ty] = 1;
		count++;
		find(tx, ty);
	}
}

int slove(const int i, const int j, const int k, const int m, const int n)
{
	count = 0;
	memset(have, 0, sizeof(have));
	int a[5] = { i, j, k, m, n };
	memset(visit, 0, sizeof(visit));
	int num = 0;
	for (num = 0; num<5; num++)
	{
		have[a[num]] = 1;
	}
	int x, y;
	x = i / 4;
	y = i % 4 - 1;
	if (i % 4 == 0)
	{
		x -= 1;
		y = 3;
	}
	count = 1;
	visit[x][y] = 1;
	find(x, y);
	if (count == 5)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int m = 0;
	int n = 0;
	int ans = 0;
	for (i = 1; i<9; i++)
	{
		for (j = i + 1; j<10; j++)
		{
			for (k = j + 1; k<11; k++)
			{
				for (m = k + 1; m<12; m++)
				{
					for (n = m + 1; n<13; n++)
					{
						if (slove(i, j, k, m, n))
						{
							ans++;
							//printf("%d %d %d %d %d\n", i, j, k, m, n);
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}