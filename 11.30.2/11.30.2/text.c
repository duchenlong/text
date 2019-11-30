#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int Find(int num)
{
	int f1 = 0, f2 = 1, f3;
	int left = 0, right = 0;
	while (1)
	{
		f3 = f1 + f2;
		left = f2;
		right = f3;
		if (f3 >= num)
		{
			break;
		}
		f1 = f2;
		f2 = f3;
	}
	if (f3 == num)
	{
		return 0;
	}
	else if (num - left > right - num)
	{
		return right - num;
	}
	else
	{
		return num - left;
	}
}

int main()
{
	int num;
	scanf("%d", &num);
	printf("%d\n", Find(num));
	return 0;
}