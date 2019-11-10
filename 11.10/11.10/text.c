#define _CRT_SECURE_NO_WARNINGS 1


//标题：等差素数列
//
//2, 3, 5, 7, 11, 13, ....是素数序列。
//类似：7, 37, 67, 97, 127, 157 这样完全由素数组成的等差数列，叫等差素数数列。
//上边的数列公差为30，长度为6。
//
//2004年，格林与华人陶哲轩合作证明了：存在任意长度的素数等差数列。
//这是数论领域一项惊人的成果！
//
//有这一理论为基础，请你借助手中的计算机，满怀信心地搜索：
//
//长度为10的等差素数列，其公差最小值是多少？

#include<stdio.h>

int judge(int num)
{
	int i = 0;
	if (num == 2 || num == 3)
	{
		return 1;
	}
	else if ((num % 6 != 5) && (num % 6 != 1))
	{
		return 0;
	}
	for (i = 5; i <= num/2; i+=6)
	{
		if ((num % i == 0) || (num % (i + 2) == 0))
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i = 0;
	int a[10000] = { 0 };
	int b[10] = { 0 };
	int j = 0;
	int k = 0;
	for (i = 2; i < 100000; i++)
	{
		if (judge(i))
		{
			a[j] = i;
			j++;
		}
	}
	int n = 0;
	int count = j;
	for (i = 0; i < count; i++)//a[i]表示首项
	{
		for (n = 1; n < 1000; n++)//6*n   表示公差
		{
			k = 1;
			b[0] = a[i];
			//j表示除了首项再找9个数
			for (j = 1; j < 10; j++)
			{
				int num = a[i] + n*6* (j + 1);
				if (judge(num))
				{
					b[k] = num;
					k++;
				}
				else
				{
					break;
				}
			}
			if (k == 10)
			{
				for (i = 0; i <k; i++)
				{
					printf("%d ", b[i]);
				}
				printf("\n%d\n", 6 * n);
				return 0;
			}
		}
		
	}
	return 0;
}