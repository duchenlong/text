#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	int i, m, n, b, t, a[5];
	for (i = 0; i < 5; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 4; i++)
	{
		n = a[i];
		for (m = i + 1; m < 5; m++)
		{
			if (a[m] < n)
			{
				n = a[m];
				t = m;
			}
		}
		b = a[i];
		a[i] = n;
		a[t] = b;
	}
	for (i = 0; i < 5; i++)
		printf("%d ", a[i]);
}