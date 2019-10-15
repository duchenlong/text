#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void quick_sort(int* a, int left, int right)
{
	if (left < right)
	{
		int count = sort(a, left, right);
		quick_sort(a, left, count - 1);
		quick_sort(a, count + 1, right);
	}
}
int sort(int* a, int left, int right)
{
	int t = a[left];
	while (left < right)
	{
		while ((left<right) && (a[right]>t))
		{
			right--;
		}
		a[left] = a[right];
		while ((left < right) && (a[left] < t))
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = t;
	return left;
}

int main()
{
	int a[10] = { 2, 5, 8, 7, 4, 1, 3, 6, 9, 10 };
	int i = 0;
	quick_sort(a, 0, 9);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
#if 0
void quit_sort(int* a, int left, int right)
{
	int t = a[left];
	int i = left;
	int j = right;
	int count = 0;
	while (left < right)
	{
		while ((left<right) && (a[right]>t))
		{
			right--;
		}
		a[left] = a[right];
		while ((left < right) && (a[left] < t))
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = t;
	if (i<left - 1)
	{
		quit_sort(a, i, left - 1);
	}
	if (j>right + 1)
	{
		quit_sort(a, right + 1, j);
	}
}
int main()
{
	int a[10] = { 2, 5, 8, 7, 4, 1, 3, 6, 9, 10 };
	int i = 0;
	quit_sort(a,0,9);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
#endif