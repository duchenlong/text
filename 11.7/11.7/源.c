#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
	int n, m;
	int ans = 0;
	int  i = 0, j = 0;
	int q = 0, w = 0, e = 0, r = 0;
	int* a, *b;
	scanf("%d%d", &n, &m);
	int k = (int)pow(2, m);
	a = (int*)calloc(n*m, sizeof(int));
	b = (int*)calloc(k, sizeof(int));
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<m; j++)
		{
			scanf("%d", a + i*m + j);
		}
	}
	for (i = 0; i<n; i++)
	{
		int num = 0;
		for (j = 0; j <m; j++)
		{
			num = (num << 1) + *(a + i*m + j);
		}
		b[num]++;
	}
	for (i = 0; i<k/2; i++)
	{
		ans += b[i] * b[k - 1 - i];
	}
	printf("%d", ans);
}