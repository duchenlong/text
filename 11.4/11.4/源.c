#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Swap(int* arr1, int* arr2)
{
	int tmp = *arr1;
	*arr1 = *arr2;
	*arr2 = tmp;
}

void InterpolationSort(int* a, int len)
{
	int i = 0;
	int j = 0;
	int num;
	for (i = 1; i < len; i++)
	{
		num = i;
		while (a[num] < a[num-1]&&num>0)
		{
			Swap(&a[num], &a[num-1]);
			num--;
		}
	}
}

void HillSort(int* a, int len)
{
	size_t i = 0;
	size_t  size = len / 2;
	while (size != 1)
	{
		for (i = 0;i<(len - size); i++)
		{
			if (a[i]>a[i + size])
			{
				Swap(&a[i], &a[i + size]);
			}
		}
		size /= 2;
	}
	InterpolationSort(a, len);
}


int main()
{
	int a[10] = { 9, 8, 7, 4, 5, 6, 3, 2, 1, 10 };
	HillSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}