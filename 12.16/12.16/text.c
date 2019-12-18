#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//
//int a[25] = { 0 };
//int b[25] = { 0 };
//int ans = 0;
//int k = 0;
//int m = 0;
//
//void slove(int index)
//{
//	int i = 0;
//	for (i = 0; i<index - 2; i++)
//	{
//		if ((a[i + 1]>a[i] && a[i + 1] > a[i + 2]) || (a[i + 1] < a[i] && a[i + 1] < a[i + 2]))
//		{
//			if ((a[i + 2]>a[i] && a[i + 2]>a[i + 1]) || (a[i + 2] < a[i] && a[i + 2] < a[i + 1]))
//			{
//				continue;
//			}
//			else
//			{
//				return;
//			}
//		}
//		else
//		{
//			return;
//		}
//	}
//	ans++;
//}
//
//void DFS(int index)
//{
//	if (index  == m)
//	{
//		slove(index);
//		return;
//	}
//
//	int j = 0;
//
//	for (j = 1; j <= k; j++)
//	{
//		if (!b[j])
//		{
//			b[j] = 1;
//			a[index] = j;
//			DFS(index+1);
//			b[j] = 0;
//		}
//	}
//}
//
//int main()
//{
//	scanf("%d", &k);
//
//	ans = k*(k - 1);
//	int i = 0;
//	for (i = 3; i <= k; i++)
//	{
//	m = i;
//	DFS(0);
//	}
//
//	printf("%d\n", ans);
//	return 0;
//}

#include<stdio.h>

int a[25][25] = { 0 };
int ans = 0;

int main()
{
	int k = 0;
	scanf("%d", &k);

	int i = 0;
	int j = 0;
	for (i = 2; i <= k; i++)
	{
		a[i][2] = i*(i - 1);
		a[i][i] = 2;
		for (j = 3; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}

	for (i = 2; i <= k; i++)
	{
		ans += a[k][i];
	}
	printf("%d\n", ans);
	return 0;
}