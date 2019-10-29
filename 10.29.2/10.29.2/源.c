#define _CRT_SECURE_NO_WARNINGS 1

//煤球数目
//
//有一堆煤球，堆成三角棱锥形。具体：
//第一层放1个，
//第二层3个（排列成三角形），
//第三层6个（排列成三角形），
//第四层10个（排列成三角形），
//....
//如果一共有100层，共有多少个煤球？
//
//请填表示煤球总数目的数字。
//注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
//
#if 0
#include<stdio.h>

int main()
{
	int i = 0;
	int num = 0;
	int a[101] = { 0 };
	for (i = 1; i < 101; i++)
	{
		a[i] = a[i - 1] + i;
		num += a[i];
	}
	printf("%d", num);

	return 0;
}
#endif

//凑算式
//
//     B      DEF
//A + -- - +------ - = 10
//     C      GHI
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

#if 0
#include<stdio.h>
#include<string.h>

int  arr[10] = { 0 };
int ans = 0;
int visit[10] = { 0 };


int judge(int* arr)
{
	double x = arr[1] + (double)arr[2] / arr[3] + (double)(arr[4] * 100 + arr[5] * 10 + arr[6]) / (arr[7] * 100 + arr[8] * 10 + arr[9]);
	if (x == 10)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int a, b, c, d, e, f, g, h, i;
	for (a = 1; a <= 9; a++)
	{
		memset(arr, 0, sizeof(arr));
		arr[a] = 1;
		for (b = 1; b <= 9; b++)
		{
			memset(arr, 0, sizeof(arr));
			arr[a] = 1;
			if (arr[b] == 1)
			{
				continue;
			}
			arr[b] = 1;
			for (c = 1; c <= 9; c++)
			{
				memset(arr, 0, sizeof(arr));
				arr[a] = 1;
				arr[b] = 1;
				if (arr[c] == 1)
				{
					continue;
				}
				arr[c] = 1;
				for (d = 1; d <= 9; d++)
				{
					memset(arr, 0, sizeof(arr));
					arr[a] = 1;
					arr[b] = 1;
					arr[c] = 1;
					if (arr[d] == 1)
					{
						continue;
					}
					arr[d] = 1;
					for (e = 1; e <= 9; e++)
					{
						memset(arr, 0, sizeof(arr));
						arr[a] = 1;
						arr[b] = 1;
						arr[c] = 1;
						arr[d] = 1;
						if (arr[e] == 1)
						{
							continue;
						}
						arr[e] = 1;
						for (f = 1; f <= 9; f++)
						{
							memset(arr, 0, sizeof(arr));
							arr[a] = 1;
							arr[b] = 1;
							arr[c] = 1;
							arr[d] = 1;
							arr[e] = 1;
							if (arr[f] == 1)
							{
								continue;
							}
							arr[f] = 1;
							for (g = 1; g <= 9; g++)
							{
								memset(arr, 0, sizeof(arr));
								arr[a] = 1;
								arr[b] = 1;
								arr[c] = 1;
								arr[d] = 1;
								arr[e] = 1;
								arr[f] = 1;
								if (arr[g] == 1)
								{
									continue;
								}
								arr[g] = 1;
								for (h = 1; h <= 9; h++)
								{
									memset(arr, 0, sizeof(arr));
									arr[a] = 1;
									arr[b] = 1;
									arr[c] = 1;
									arr[d] = 1;
									arr[e] = 1;
									arr[f] = 1;
									arr[g] = 1;
									if (arr[h] == 1)
									{
										continue;
									}
									arr[h] = 1;
									for (i = 1; i <= 9; i++)
									{
										memset(arr, 0, sizeof(arr));
										arr[a] = 1;
										arr[b] = 1;
										arr[c] = 1;
										arr[d] = 1;
										arr[e] = 1;
										arr[f] = 1;
										arr[g] = 1;
										arr[h] = 1;
										if (arr[i] == 1)
										{
											continue;
										}
										arr[i] = 1;
										visit[1] = a;
										visit[2] = b;
										visit[3] = c;
										visit[4] = d;
										visit[5] = e;
										visit[6] = f;
										visit[7] = g;
										visit[8] = h;
										visit[9] = i;
										if (judge(visit))
										{
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
#endif
//抽签
//
//X星球要派出一个5人组成的观察团前往W星。
//其中：
//A国最多可以派出4人。
//B国最多可以派出2人。
//C国最多可以派出2人。
//....
//
//那么最终派往W星的观察团会有多少种国别的不同组合呢？
//
//下面的程序解决了这个问题。
//数组a[] 中既是每个国家可以派出的最多的名额。
//程序执行结果为：
//DEFFF
//CEFFF
//CDFFF
//CDEFF
//CCFFF
//CCEFF
//CCDFF
//CCDEF
//BEFFF
//BDFFF
//BDEFF
//BCFFF
//BCEFF
//BCDFF
//BCDEF
//....
//(以下省略，总共101行)
//
//
//#include <stdio.h>
//#define N 6
//#define M 5
//#define BUF 1024
//
//void f(int a[], int k, int m, char b[])
//{
//	int i, j;
//
//	if (k == N){
//		b[M] = 0;
//		if (m == 0) printf("%s\n", b);
//		return;
//	}
//
//	for (i = 0; i <= a[k]; i++){
//		for (j = 0; j<i; j++) b[M - m + j] = k + 'A';
//		______________________;  //填空位置
//	}
//}
//int main()
//{
//	int  a[N] = { 4, 2, 2, 1, 1, 3 };
//	char b[BUF];
//	f(a, 0, M, b);
//	return 0;
//}
//
//仔细阅读代码，填写划线部分缺少的内容。
//
//注意：不要填写任何已有内容或说明性文字。

#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024

void f(int a[], int k, int m, char b[])
{
	int i, j;

	if (k == N){
		b[M] = 0;
		if (m == 0) printf("%s\n", b);
		return;
	}

	for (i = 0; i <= a[k]; i++){
		for (j = 0; j<i; j++) b[M - m + j] = k + 'A';
		//______________________;  //填空位置
		f(a, k + 1, m-i, b);
	}
}
int main()
{
	int  a[N] = { 4, 2, 2, 1, 1, 3 };
	char b[BUF];
	f(a, 0, M, b);
	return 0;
}