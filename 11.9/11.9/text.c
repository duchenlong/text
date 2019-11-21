#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int ans = 0;
int arr[36] = { 0 };
int my_arr[36] = { 0 };
int visit[6][6] = { 0 };
int dir[4][2] = { 1, 0, 0, 1, -1, 0, 0, -1 };
int my_visit[6][6] = { 0 };
int count = 0;

//void slove_line(int x, int y)
//{
//	int i = 0;
//	int tx = 0;
//	int ty = 0;
//	for (i = 0; i<4; i++)
//	{
//		if (count == 18)
//		{
//			return;
//		}
//		tx = dir[i][0] + x;
//		ty = dir[i][1] + y;
//		if (tx<0 || tx>5 || ty<0 || ty>5)
//		{
//			continue;
//		}
//		if (!visit[tx][ty] || !my_arr[my_visit[tx][ty]])
//		{
//			continue;
//		}
//		my_arr[my_visit[tx][ty]] = 0;
//		count++;
//		slove_line(tx,ty);
//	}
//}

int slove_same()
{
	int i = 0;
	int j = 0;
	for (i = 0; i<3; i++)
	{
		for (j = 0; j<6; j++)
		{
			if (visit[i][j] + visit[5 - i][5 - j] != 1)
			{
				return 0;
			}
		}
	}
	return 1;
}

//void slove()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < 36; i++)
//	{
//		my_arr[i] = arr[i];
//	}
//	count = 0;
//	for (i = 0; i<6; i++)
//	{
//		for (j = 0; j<6; j++)
//		{
//			if (visit[i][j])
//			{
//				my_arr[my_visit[i][j]] = 0;
//				count++;
//				slove_line(i, j);
//				if (count == 18)
//				{
//					ans++;
//				}
//				return;
//			}
//		}
//	}
//}

void dfs(int index,int j)
{
	int i = 0;
	int k = j;
	if (index == 18)
	{
		if (slove_same())
		{
			//slove();
			ans++;
		}
		return;
	}
	for (i = k; i<36; i++)
	{
		if (!arr[i])
		{
			arr[i] = 1;
			int x = i / 6;
			int y = i % 6;
			visit[x][y] = 1;
			dfs(index + 1,j+1);
			visit[x][y] = 0;
			arr[i] = 0;
		}
	}
}

int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i<6; i++)
	{
		for (j = 0; j<6; j++)
		{
			my_visit[i][j] = k;
			k++;
		}
	}
	dfs(0,0);
	printf("%d\n", ans);
	return 0;
}