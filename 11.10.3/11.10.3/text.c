#define _CRT_SECURE_NO_WARNINGS 1

//标题： k倍区间
//
//给定一个长度为N的数列，A1, A2, ... AN，
//如果其中一段连续的子序列Ai, Ai + 1, ... Aj(i <= j)之和是K的倍数，
//我们就称这个区间[i, j]是K倍区间。
//
//你能求出数列中总共有多少个K倍区间吗？
//
//输入
//---- -
//第一行包含两个整数N和K。(1 <= N, K <= 100000)
//以下N行每行包含一个整数Ai。(1 <= Ai <= 100000)
//
//输出
//---- -
//输出一个整数，代表K倍区间的数目。

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, k;
	int i = 0, j = 0;
	int ans = 0;
	int* a;
	int sum = 0;
	scanf("%d%d", &n, &k);
	a = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = i; j < n; j++)
		{
			sum += a[j];
			if (sum%k == 0)
			{
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}