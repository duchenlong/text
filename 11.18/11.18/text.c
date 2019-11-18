#define _CRT_SECURE_NO_WARNINGS 1

//受大西线调水工程启发，小明也准备设计一条调水的水渠。
//小明经费有限，他只能在一块有限区域内建立一条简单的水渠。
//小明首先勘探了地形，在这块地中有一处水源，必须用作水渠的起点。另外，小明还测量了一些点，包括点的位置和高度。如果两个小明测量的点之间的距离不超过 d 且高度不同，小明就可以在这两点之间建立一段水渠，让水从高处流向低处，这一段的长度为两点之间的直线距离（即将横坐标的差的平方加上纵坐标的差的平方加上高度差的平方后再开平方根）。
//小明计划只修一条主水渠，不建立分支的水渠。由于水渠能影响的范围与水渠的长度正相关，小明希望水渠尽可能长。
//请注意，水渠必须从水源开始修，并且高度应当递减。水渠的不同段可能交叉（建个桥即可）

#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int n;

typedef struct node
{
	int x;
	int y;
	int h;
}node;

typedef struct arr
{
	node a[1000];
	int size;
}arr;

void swap(node* p1, node* p2)
{
	int tmp = p1->x;
	p1->x = p2->x;
	p2->x = tmp;

	tmp = p1->y;
	p1->y = p2->y;
	p2->y = tmp;

	tmp = p1->h;
	p1->h = p2->h;
	p2->h = tmp;
}

void my_sqort(arr* pw)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pw->size - 1; i++)
	{
		for (j = 0; j < pw->size - i - 1; j++)
		{
			if (pw->a[j].x>pw->a[j + 1].x)
			{
				swap(&pw->a[j], &pw->a[j + 1]);
			}
			if (pw->a[j].x == pw->a[j + 1].x)
			{
				if (pw->a[j].y>pw->a[j + 1].y)
				{
					swap(&pw->a[j], &pw->a[j + 1]);
				}
			}
			if (pw->a[j].x == pw->a[j + 1].x)
			{
				if (pw->a[j].y == pw->a[j + 1].y)
				{
					if (pw->a[j].h > pw->a[j + 1].h)
					{
						swap(&pw->a[j], &pw->a[j + 1]);
					}
				}
			}
		}
	}
}

int main()
{
	double ans = 0.0;
	arr* water;
	arr* ws;
	int i = 0;
	int num = 0;
	int d = 0;
	double count;
	scanf("%d", &n);
	water = (arr*)malloc(sizeof(arr));
	ws = (arr*)malloc(sizeof(arr));
	water->size = 0;
	num = n;
	while (num--)
	{
		scanf("%d%d%d", &water->a[water->size].x, &water->a[water->size].y, &water->a[water->size].h);
		water->size++;
	}
	scanf("%d", &d);
	my_sqort(water);
	ws->a[0].x=water->a[0].x;
	ws->a[0].y = water->a[0].y;
	ws->a[0].h = water->a[0].h;
	ws->size = 1;
	for (i = 1; i < water->size; i++)
	{
		if (water->a[i].h > ws->a[ws->size-1].h)
		{
			if (ws->size - 1 != 1)
			{
				i--;
				ws->size--;
			}
			continue;
		}
		int tx = abs(water->a[i].x - ws->a[ws->size - 1].x);
		int ty = abs(water->a[i].y - ws->a[ws->size - 1].y);
		int th = abs(water->a[i].h - ws->a[ws->size - 1].h);
		count = (double)sqrt(tx*tx + ty*ty+th*th);
		if (count <= d)
		{
			ws->size++;
			ans += count;
			if (i != water->size - 1)
			{
				if (water->a[i + 1].x != water->a[i].x)
				{
					ws->a[ws->size - 1].x = water->a[i].x;
					ws->a[ws->size - 1].y = water->a[i].y;
					ws->a[ws->size - 1].h = water->a[i].h;
				}
			}
		}
		
	}
	printf("%.2lf\n", ans);
	return 0;
}