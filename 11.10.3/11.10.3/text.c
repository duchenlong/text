#define _CRT_SECURE_NO_WARNINGS 1

//���⣺ k������
//
//����һ������ΪN�����У�A1, A2, ... AN��
//�������һ��������������Ai, Ai + 1, ... Aj(i <= j)֮����K�ı�����
//���Ǿͳ��������[i, j]��K�����䡣
//
//��������������ܹ��ж��ٸ�K��������
//
//����
//---- -
//��һ�а�����������N��K��(1 <= N, K <= 100000)
//����N��ÿ�а���һ������Ai��(1 <= Ai <= 100000)
//
//���
//---- -
//���һ������������K���������Ŀ��

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n, k;
	int i = 0, j = 0;
	int ans = 0;
	int* a;
	int sum = 0;
	scanf("%d%d", &n, &k);
	a = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = i; j < n; j++)
		{
			sum += a[j];
			if (sum%k == 0)
			{
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}