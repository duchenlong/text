#define _CRT_SECURE_NO_WARNINGS 1

//标题：迷宫
//
//X星球的一处迷宫游乐场建在某个小山坡上。
//它是由10x10相互连通的小房间组成的。
//
//房间的地板上写着一个很大的字母。
//我们假设玩家是面朝上坡的方向站立，则：
//L表示走到左边的房间，
//R表示走到右边的房间，
//U表示走到上坡方向的房间，
//D表示走到下坡方向的房间。
//
//X星球的居民有点懒，不愿意费力思考。
//他们更喜欢玩运气类的游戏。这个游戏也是如此！
//
//开始的时候，直升机把100名玩家放入一个个小房间内。
//玩家一定要按照地上的字母移动。
//
//迷宫地图如下：
//------------
//UDDLUULRUL
//UURLLLRRRU
//RRUURLDLRD
//RUDDDDUUUU
//URUDLLRRUU
//DURLRLDLRL
//ULLURLLRDU
//RDLULLRDDD
//UUDDUDUDLL
//ULRDLUURRR
//------------
//
//请你计算一下，最后，有多少玩家会走出迷宫 ?
//而不是在里边兜圈子。
//
//请提交该整数，表示走出迷宫的玩家数目，不要填写任何多余的内容

#include<stdio.h>
#include<string.h>

char* arr = "UDDLUULRULUURLLLRRRURRUURLDLRDRUDDDDUUUUURUDLLRRUUDURLRLDLRLULLURLLRDURDLULLRDDDUUDDUDUDLLULRDLUURRR";
int i = 0;
int j = 0;
char a[10][10];
int ans = 0;
int visit[10][10];

int walk(const int people)
{
	memset(visit,0,sizeof(visit));
	int x = people / 10;
	int y = people % 10;
	while (1)
	{
		if (visit[x][y])
		{
			return 0;
		}
		visit[x][y] = 1;
		switch (a[x][y])
		{
		case 'L':
			--y;
			break;
		case 'R':
			++y;
			break;
		case 'U':
			--x;
			break;
		case 'D':
			++x;
			break;
		}
		if (x<0 || x>9 || y<0 || y>9)
		{
			return 1;
		}
	}
}

void slove()
{
	int people = 1;
	for (people = 1; people <= 100; people++)
	{
		if (walk(people))
		{
			ans++;
		}
	}
}

int main()
{
	int count = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			a[i][j] = arr[count];
			count++;
		}
	}
	slove();
	printf("%d", ans);
	return 0;
}