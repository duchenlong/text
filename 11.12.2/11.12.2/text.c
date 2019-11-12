#define _CRT_SECURE_NO_WARNINGS 1

//标题：算式900
//
//
//小明的作业本上有道思考题：
//
//看下面的算式：
//
//(□□□□ - □□□□)*□□ = 900
//
//其中的小方块代表0~9的数字，这10个方块刚好包含了0~9中的所有数字。
//注意：0不能作为某个数字的首位。
//
//小明经过几天的努力，终于做出了答案！如下：
//(5012 - 4987) * 36 = 900
//
//用计算机搜索后，发现还有另外一个解，本题的任务就是：请你算出这另外的一个解。

#include<stdio.h>

int a[10] = { 0 };
int my_a[10] = { 0 };
int ans = 0;

void slove()
{
	if (a[0] == 0||a[4]==0||a[8]==0)
	{
		return;
	}
	if ((((a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3]) - (a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[7]))*(a[8] * 10 + a[9])) == 900)
	{
		int j = 0;
		for (j = 0; j < 10; j++)
		{
			printf("%d ", a[j]);
		}
		printf("\n");
	}
}

void dfs(int index)
{
	if (index == 10)
	{
		slove();
		return;
	}
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (!my_a[i])
		{
			my_a[i] = 1;
			a[index] = i;
			dfs(index + 1);
			my_a[i] = 0;
		}
	}
}

int main()
{
	dfs(0);
	return 0;
}