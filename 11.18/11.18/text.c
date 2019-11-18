#define _CRT_SECURE_NO_WARNINGS 1

//�ܴ����ߵ�ˮ����������С��Ҳ׼�����һ����ˮ��ˮ����
//С���������ޣ���ֻ����һ�����������ڽ���һ���򵥵�ˮ����
//С�����ȿ�̽�˵��Σ�����������һ��ˮԴ����������ˮ������㡣���⣬С����������һЩ�㣬�������λ�ú͸߶ȡ��������С�������ĵ�֮��ľ��벻���� d �Ҹ߶Ȳ�ͬ��С���Ϳ�����������֮�佨��һ��ˮ������ˮ�Ӹߴ�����ʹ�����һ�εĳ���Ϊ����֮���ֱ�߾��루����������Ĳ��ƽ������������Ĳ��ƽ�����ϸ߶Ȳ��ƽ�����ٿ�ƽ��������
//С���ƻ�ֻ��һ����ˮ������������֧��ˮ��������ˮ����Ӱ��ķ�Χ��ˮ���ĳ�������أ�С��ϣ��ˮ�������ܳ���
//��ע�⣬ˮ�������ˮԴ��ʼ�ޣ����Ҹ߶�Ӧ���ݼ���ˮ���Ĳ�ͬ�ο��ܽ��棨�����ż��ɣ�

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