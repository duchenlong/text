#define _CRT_SECURE_NO_WARNINGS 1

//����һ�� n �� m �еı�����ǿ���ʹ�������ķ�ʽ������������������������ǳ���õı��Ϊһ����������
//���磬һ�� 4 �� 5 �е������������£�
//1 2 3 4 5
//14 15 16 17 6
//13 20 19 18 7
//12 11 10 9 8

#include<stdio.h>

int a[1005][1005] = { 0 };
int b[1005][1005] = { 0 };
int n = 0;
int m = 0;
int s = 0;
int count = 1;


void slove()
{
	int i = 1;
	int x = 0;
	int y = 0;
	int flag = 1;
	while (count!=n*m+1)
	{
		if (x >= 0 && y >= 0 && x < n && y < m&&!b[x][y])
		{
			a[x][y] = count;
			b[x][y] = 1;
			count++;
		}
		else
		{
			flag = 0;
			++s;
		}
		if (s % 4 == 0)
		{
			if (!flag)
			{
				flag = 1;
				x++;;
			}
			y++;
		}
		else if (s % 4 == 1)
		{
			if (!flag)
			{
				flag = 1;
				y--;
			}
			x++;
		}
		else if (s % 4 == 2)
		{
			if (!flag)
			{
				flag = 1;
				x--;
			}
			y--;
		}
		else
		{
			if (!flag)
			{
				flag = 1;
				y++;
			}
			x--;
		}
	}
}

int main()
{
	int r, c;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &r, &c);
	slove();
	printf("%d\n", a[r - 1][c - 1]);
	return 0;
}