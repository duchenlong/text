#define _CRT_SECURE_NO_WARNINGS 1

//凑算式
//
//B      DEF
//A + -- - +------ - = 10
//C      GHI
//
//（如果显示有问题，可以参见【图1.jpg】）
//
//
//这个算式中A~I代表1~9的数字，不同的字母代表不同的数字。
//
//比如：
//6 + 8 / 3 + 952 / 714 就是一种解法，
//5 + 3 / 1 + 972 / 486 是另一种解法。
//
//这个算式一共有多少种解法？
//
//注意：你提交应该是个整数，不要填写任何多余的内容或说明性文字。

#include<stdio.h>
#include<string.h>

int arr[10] = { 0 };
int ans = 0;
int my_arr[10] = { 0 };

void slove()
{
	double x = arr[1] + (double)arr[2] / arr[3] + (double)(arr[4] * 100 + arr[5] * 10 + arr[6]) / (arr[7] * 100 + arr[8] * 10 + arr[9]);
	if (x == 10)
	{
		ans++;
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
	for (i = 1; i < 10; i++)
	{
		if (!my_arr[i])
		{
			my_arr[i] = 1;
			arr[index] = i;
			dfs(index + 1);
			my_arr[i] = 0;
		}
	}
}

int main()
{
	dfs(1);
	printf("%d", ans);
	return 0;
}