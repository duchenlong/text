#define _CRT_SECURE_NO_WARNINGS 1

//给定三个整数 a, b, c，如果一个整数既不是 a 的整数倍也不是 b 的整数倍还不是 c 的整数倍，则这个数称为反倍数。
//请问在 1 至 n 中有多少个反倍数。
#if 0
#include<stdio.h>

int main()
{
	int n, a, b, c;
	int ans = 0;
	int i = 0;
	scanf("%d", &n);
	scanf("%d%d%d", &a, &b, &c);
	for (i = 1; i <= n; i++)
	{
		if (i%a == 0 || i%b == 0 || i%c == 0)
		{
			continue;
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
#endif

//在一个8x8的国际象棋棋盘的左上角放一枚棋子，每一步只允许棋子向右或向下移动一格，不允许移出棋盘，14步后可移动到棋盘的右下角。
//请问本质不同的移动方案有多少种？
//两个移动方案称为本质不同的，是指这两种方案中至少存在某一步，一种方案中是向右走，一种方案中是向下走。

#if 0
#include<stdio.h>

int ans = 0;
int a[8][8] = { 0 };
int div[2][2] = { { 0, 1 }, { 1,0 } };

void slove()
{
	if (a[7][7])
	{
		ans++;
	}
}

void dfs(int index, int x, int y)
{
	if (index == 15)
	{
		slove();
		return;
	}
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		int tx = x + div[i][0];
		int ty = y + div[i][1];
		if (tx>7 || ty > 7)
		{
			continue;
		}
		if (!a[tx][ty])
		{
			a[tx][ty] = 1;
			dfs(index + 1, tx, ty);
			a[tx][ty] = 0;
		}
	}
}

int main()
{
	a[0][0] = 1;
	dfs(1,0,0);
	printf("%d\n", ans);
}
#endif

//小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
//小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
//这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、右四小块空地扩展，这四小块空地都将变为有草的小块。
//请告诉小明，k 个月后空地上哪些地方有草。

#include<stdio.h>

char a[1050][1050] = { '\0' };
char b[1050][1050] = { '\0' };
int div[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int n=0, m=0;
int k = 0;

void visit(int x,int y)
{
	int tx = 0;
	int ty = 0;
	int i = 0,j=0;
	for (i = 0; i < 4; i++)
	{
		tx = x + div[i][0];
		ty = y + div[i][1];
		if (tx < 0 || tx >= n || ty < 1 || ty > m)
		{
			continue;
		}
		b[tx][ty] = 'g';
	}
	
}

void slove()
{
	int i = 0;
	int j = 0;
	while (k--)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (a[i][j] == 'g')
				{
					visit(i,j);
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			scanf("%c", &a[i][j]);
			b[i][j] = a[i][j];
		}
	}
	scanf("%d", &k);
	slove();
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}