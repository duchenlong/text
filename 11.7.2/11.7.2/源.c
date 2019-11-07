#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int cut(int* a, const int len, int c, int k)
{
	int i = 0;
	int count = 0;
	for (i = 0; i<len / 2; i += 2)
	{
		count += (a[i] / c)*(a[i + 1] / c);
	}
	if (count >= k)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int n, k;
	int l = 0;
	int ans = 10000;
	int i = 0;
	int* a;
	scanf("%d%d", &n, &k);
	a = (int*)malloc(n * 2 * sizeof(int));
	for (i = 0; i<2 * n; i++)
	{
		scanf("%d", &a[i]);
	}
	while (ans - l>1)
	{
		int mid = (l + ans) / 2;
		if (cut(a, 2 * n, mid, k) == 0)
		{
			ans = mid;
		}
		else
		{
			l = mid;
		}
	}
	printf("%d", l);
	return 0;
}