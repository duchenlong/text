#include<stdio.h>

#define MAX 0xffff
#define MAX_ARR 200005

typedef struct Side
{
	int _from;
	int _to;
	int _key;
}Side;

Side side[MAX_ARR] = { 0 };
int dis[MAX_ARR] = { 0 };
int path[MAX_ARR] = { 0 };

void BellMan(int n, int m)
{
	int i = 0, j = 0;
	int key = 0;
	int temp = 0;
	Side p;

	for (i = 2; i <= n; i++)
	{
		dis[i] = MAX;
	}
	dis[1] = 0;

	for (i = 1; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			p = side[j];
			temp = dis[p._from] + p._key;
			if (temp < dis[p._to])
			{
				dis[p._to] = temp;
			}
		}
	}
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);

	int i = 0;
	for (i = 0; i < m; i++)
	{
		scanf("%d%d%d", &side[i]._from, &side[i]._to, &side[i]._key);
	}

	BellMan(n, m);
	for (i = 2; i <= n; i++)
	{
		printf("%d\n", dis[i]);
	}
	return 0;
}
