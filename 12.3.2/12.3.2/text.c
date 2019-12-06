#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void my_sqort(int* arr, const int len)
{
	int i = 0, j = 0;
	int flag = 0;
	for (i = 0; i < len; i++)
	{
		flag = 0;
		for (j = 0; j<len - i - 1; j++)
		{
			if (arr[j]>arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
		}
	}
}

int main()
{
	int n, i;
	int* huffman;
	int num = 0;
	int len = 3;
	scanf("%d", &n);
	huffman = (int*)malloc(sizeof(int));
	for (i = 0; i < n; i++)
	{
		scanf("%d", &huffman[i]);
	}
	my_sqort(huffman, n);
	while (n != 1)
	{
		if (n == 2)
		{
			len = 2;
		}
		my_sqort(huffman, len);

		num += huffman[0] + huffman[1];
		huffman[1] = num;
		for (i = 0; i < n - 1; i++)
		{
			huffman[i] = huffman[i + 1];
		}
		n--;
	}
	printf("%d\n", num + huffman[0]);
	return 0;
}