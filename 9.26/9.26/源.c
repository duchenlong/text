#define _CRT_SECURE_NO_WARNINGS 1
//调整数组使奇数全部都位于偶数前面。
//
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
#include<stdio.h>
#if 0
void Paixu(int* a,int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			int t = 0;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			j++;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(a) / sizeof(a[0]);
	Paixu(a,n);
	return 0;
}
#endif
////杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
/// ，py 代表行数和列数
void find(int arr[3][3], int *px, int * py, int key)
{
	if (key > arr[*px-1][*py-1])
	{
		printf("该数字不存在\n");
	}
	else
	{
		int i = 0,j=(*py);
		while (i<(*px)*(*py))
		{
			if (key == arr[*px - 1][*py - 1])
			{
				printf("该数字的位置是%d,%d\n", *px, *py);
				(*px)--;
				*py = j;
			}
			/*else if (key > arr[*px - 1][*py - 1])
			{
				(*px)--;
			}*/
			else if (key <arr[*px - 1][*py - 1])
			{
				(*py)--;
			}
			if (*py < 0)
			{
				(*py) = j;
				(*px)--;
			}
			i++;
		}
	}
}
int main()
{
	//int arr[3][3] = { 1,3,4,2,4,5,4,5,6 };
	//int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr[3][3] = { 1, 2, 3,2,3,4,3,4,5};
	int x = 3;
	int y = 3;
	find(arr, &x, &y, 4);
	return 0;
}