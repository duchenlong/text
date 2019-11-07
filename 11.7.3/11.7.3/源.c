#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int a[10000][10000] = { 0 };

int main()
{
	int n, count = 0;
	int i = 0, j = 0, k = 0;
	int add = 0;
	scanf("%d", &n);
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<4; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 0; i<n; i++)
	{
		for (j = a[i][0]; j<a[i][2]; j++)
		{
			for (k = a[i][1]; k<a[i][3]; k++)
			{
				if (a[j][k] == 0)
				{
					count++;
					a[j][k] = 1;
				}
			}
		}
	}
	printf("%d", count);
	return 0;
}