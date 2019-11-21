#define _CRT_SECURE_NO_WARNINGS 1

//标题：跳蚱蜢
//
//如图 p1.png 所示：
//有9只盘子，排成1个圆圈。
//其中8只盘子内装着8只蚱蜢，有一个是空盘。
//我们把这些蚱蜢顺时针编号为 1~8
//
//每只蚱蜢都可以跳到相邻的空盘中，
//也可以再用点力，越过一个相邻的蚱蜢跳到空盘中。
//
//请你计算一下，如果要使得蚱蜢们的队形改为按照逆时针排列，
//并且保持空盘的位置不变（也就是1 - 8换位，2 - 7换位, ...），至少要经过多少次跳跃？

#include<stdio.h>

int a[9] = { 0 };
int count = 0;
int i = 0;

void Init(int* a)
{
	for (i = 0; i < 9; i++)
	{
		a[i] = i;
	}
}

int judge(int* a)
{
	int n = 0;
	int m = 8;
	for (n = 8; n >1; n--)
	{
		if (a[n] != a[n-1]-1)
		{
			return 0;
		}
		m--;
	}
	return 1;
}

void slove()
{
	int j = 0;
	int k = 0;
	while (1)
	{
		i = (k + 7) % 9;
		j = (k + 8) % 9;
		if (a[k] == 0)
		{
			if (a[i] < a[j])
			{
				a[k] = a[i];
				a[i] = 0;
				count++;
			}
			else if (a[i] - a[j]==1)
			{
				a[k] = a[j];
				a[j] = a[i];
				a[i] = 0;
				count++;
			}
			int n = 0;
			for (n = 0; n < 9; n++)
			{
				printf("%d ", a[n]);
			}
			printf("\n");
			if (judge(a))
			{
				break;
			}
		}
		k = i;
	}
}

int main()
{
	Init(a);
	slove();
	printf("%d", count);
	return 0;
}