#define _CRT_SECURE_NO_WARNINGS 1

#include "qsort.h"

// 排序实现的接口

// 插入排序
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
			}
			else
			{
				break;
			}
			end--;
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n)
{
	//预排序  间距为gap 的插入排序
	int gap = n;

	//gap != 1 -->预排序阶段
	//gap == 1 --> 排序阶段
	while (gap != 1)
	{
		gap = gap / 3 + 1; //定义每次排序的间距
		int j = 0;
		for (j = 0; j < n - gap; j++)
		{
			int end = j ;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
				}
				else
				{
					break;
				}
				end -= gap;
			}
			a[end + gap] = tmp;
		}
	}
}

void Swap(int* a, int l, int r)
{
	int tmp = a[l];
	a[l] = a[r];
	a[r] = tmp;
}

// 选择排序
void SelectSort(int* a, int n)
{
	
	int i = 0;
	int j = 0;
	for (j = 0; j < n / 2; j++)
	{
		int min = j, max = j;
		for (i = j; i < n - j; i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			else if (a[i] < a[min])
			{
				min = i;
			}
		}
		Swap(a, j, min);
		if (j == max)
		{
			max = min;
		}
		Swap(a, n - j - 1, max);
	}
	
}
// 堆排序
//向下建立大根堆
void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;

	while (child < n)
	{
		if (child < (n - 1) && a[child] < a[child + 1])
		{
			child++;
		}

		if (a[parent] < a[child])
		{
			Swap(a, parent, child);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)
{
	int i = 0;
	for (i = n / 2; i >= 0; i--)
	{
		AdjustDwon(a, n, i);
	}

	for (i = n - 1; i > 0; i--)
	{
		Swap(a, 0, i);
		AdjustDwon(a, i, 0);
	}
}
// 冒泡排序
void BubbleSort(int* a, int n);

// 快速排序递归实现  (三数取中,随机取数)
// 快速排序hoare版本
void PartSort1(int* a, int left, int right)
{
	//递归结束条件
	if (left >= right)
	{
		return;
	}
	//int key = rand()%(right - left +1);
	int key = left;
	int l = left;
	int r = right;

	while (left < right)
	{
		//找到从右向左第一个小于 a[key] 的值
		while (left < right && a[right] >= a[key])
		{
			right--;
		}

		//找到从左往右第一个大于 a[key] 的值
		while (left < right && a[left] <= a[key])
		{
			left++;
		}

		Swap(a, left, right);
	}
	Swap(a, left, key);

	PartSort1(a, l, left - 1);
	PartSort1(a, left + 1, r);
}
// 快速排序挖坑法
void PartSort2(int* a, int left, int right);
// 快速排序前后指针法
void PartSort3(int* a, int left, int right)
{
	//递归结束条件
	if (left >= right)
	{
		return;
	}

	int prev = left - 1;
	int cur = left;

	int key = a[left];
	int i = 0;

	while (cur <= right)
	{
		if (a[cur] < key)
		{
			Swap(a, ++prev, cur);
		}
		cur++;
	}

	PartSort1(a, left, prev - 1);
	PartSort1(a, prev + 1, right);
}
// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right);
// 归并排序递归实现
void MergeSort(int* a, int n);
// 归并排序非递归实现
void MergeSortNonR(int* a, int n);
// 计数排序
void CountSort(int* a, int n);
