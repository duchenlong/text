#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int arr[10000] = { 1};

int main()
{
	int n;
	int i = 0, j = 0, k = 0;
	int num = 0, ans = 0;
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		for (j = 0; j <= k; j++)
		{
			arr[j] = arr[j] * i + num;
			num = arr[j] / 10;
			arr[j] %= 10;
		}
		while (num)
		{
			arr[j] = num % 10;
			num /= 10;
			k++;
			j++;
		}
	}
	for (i = k; i >= 0; i--)
	{
		printf("%d", arr[i]);
	}
	printf("\n");
	return 0;
}