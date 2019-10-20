#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//快速排序
//
//排序在各种场合经常被用到。
//快速排序是十分常用的高效率的算法。
//
//其思想是：先选一个“标尺”，
//用它把整个队列过一遍筛子，
//以保证：其左边的元素都不大于它，其右边的元素都不小于它。
//
//这样，排序问题就被分割为两个子区间。
//再分别对子区间排序就可以了。
//
//下面的代码是一种实现，请分析并填写划线部分缺少的代码。


#include <stdio.h>

void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[], int p, int r)
{
	int i = p;
	int j = r + 1;
	int x = a[p];
	while (1){
		while (i<r && a[++i]<x);
		while (a[--j]>x);
		if (i >= j) break;
		swap(a, i, j);
	}
	//______________________;
	swap(a, p, j);
	return j;
}

void quicksort(int a[], int p, int r)
{
	if (p<r){
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int main()
{
	int i;
	int a[] = { 5, 13, 6, 24, 2, 8, 19, 27, 6, 12, 1, 17 };
	int N = 12;

	quicksort(a, 0, N - 1);

	for (i = 0; i<N; i++) printf("%d ", a[i]);
	printf("\n");

	return 0;
}


//注意：只填写缺少的内容，不要书写任何题面已有代码或说明性文字。

#endif

//消除尾一
//
//下面的代码把一个整数的二进制表示的最右边的连续的1全部变成0
//如果最后一位是0，则原数字保持不变。
//
//如果采用代码中的测试数据，应该输出：
//00000000000000000000000001100111   00000000000000000000000001100000
//00000000000000000000000000001100   00000000000000000000000000001100
//
//请仔细阅读程序，填写划线部分缺少的代码。

#if 0
#include <stdio.h>

void f(int x)
{
	int i;
	for (i = 0; i<32; i++) printf("%d", (x >> (31 - i)) & 1);
	printf("   ");

	//x = _______________________;
	x = x&(x+1);
	for (i = 0; i<32; i++) printf("%d", (x >> (31 - i)) & 1);
	printf("\n");
}

int main()
{
	f(103);
	f(12);
	return 0;
}

//注意：只填写缺少的内容，不要书写任何题面已有代码或说明性文字。
#endif

//寒假作业
//
//现在小学的数学题目也不是那么好玩的。
//看看这个寒假作业：
//
//□ + □ = □
//□ - □ = □
//□ × □ = □
//□ ÷ □ = □
//
//(如果显示不出来，可以参见【图1.jpg】)
//
//每个方块代表1~13中的某一个数字，但不能重复。
//比如：
//6 + 7 = 13
//9 - 8 = 1
//3 * 4 = 12
//10 / 2 = 5
//
//以及：
//7 + 6 = 13
//9 - 8 = 1
//3 * 4 = 12
//10 / 2 = 5
//
//就算两种解法。（加法，乘法交换律后算不同的方案）
//
//你一共找到了多少种方案？
//
//
//请填写表示方案数目的整数。
//注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

#include<stdio.h>

void bianli(int* a)
{
	int i = 0;
	for (i = 0; i <= 13; i++)
	{
		a[i] = 1;
	}
}
int main()
{
	int add = 0;
	int sub = 0;
	int mul= 0;
	int div = 0;
	int count = 0;
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	for (add =1; add <= 13; add++)
	{
		int a[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		for (i = 1; i <= 13-add; i++)
		{
			bianli(a);
			a[add] = 0;
			if ((a[i] != 1) || (a[add+i]!=1))
			{
				continue;
			}
			for (sub = 13; sub >0; sub--)
			{
				bianli(a);
				a[add] = 0;
				a[i] = 0;
				a[add + i] = 0;
				if (a[sub]!= 1)
				{
					continue;
				}
				for (j = 1; j <sub; j++)
				{
					bianli(a);
					a[add] = 0;
					a[i] = 0;
					a[add + i] = 0;
					a[sub] = 0;
					if (a[j] != 1)
					{
						continue;
					}
					a[j] = 0;
					if (a[sub - j] != 1)
					{
						continue;
					}
					for (mul = 1; mul <= 13; mul++)
					{
						bianli(a);
						a[add] = 0;
						a[i] = 0;
						a[add + i] = 0;
						a[sub] = 0;
						a[j] = 0;
						a[sub - j] = 0;
						if (a[mul] != 1)
						{
							continue;
						}
						for (m = 1; m <= (13/mul); m++)
						{
							bianli(a);
							a[add] = 0;
							a[i] = 0;
							a[add + i] = 0;
							a[sub] = 0;
							a[j] = 0;
							a[sub - j] = 0;
							a[mul] = 0;
							if (a[m] != 1) 
							{
								continue;
							}
							a[m] = 0;
							if  (a[m*mul] != 1)
							{
								continue;
							}
							for (div = 13; div > 0; div--)
							{
								bianli(a);
								a[add] = 0;
								a[i] = 0;
								a[add + i] = 0;
								a[sub] = 0;
								a[j] = 0;
								a[sub - j] = 0;
								a[m] = 0;
								a[mul] = 0;
								a[m*mul] = 0;
								if (a[div] != 1)
								{
									continue;
								}
								a[div] = 0;
								for (n = 1; n < div; n++)
								{
									bianli(a);
									a[add] = 0;
									a[i] = 0;
									a[add + i] = 0;
									a[sub] = 0;
									a[j] = 0;
									a[sub - j] = 0;
									a[m] = 0;
									a[mul] = 0;
									a[m*mul] = 0;
									a[div] = 0;
									if ((div%n )!= 0)
									{
										continue;
									}
									if (a[n] != 1)
									{
										continue;
									}
									a[n] = 0;
									if (a[div/n] != 1)
									{
										continue;
									}
									count++;
									printf("%d+%d=%d\n", add, i, add + i);
									printf("%d-%d=%d\n", sub, j, sub-j);
									printf("%d*%d=%d\n", mul, m, mul*m);
									printf("%d/%d=%d\n", div, n, div/n);
									printf("\n");
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}