#define _CRT_SECURE_NO_WARNINGS 1

#include "qsort.h"
#include "stack.h"

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

void choose(int* a,int left,int right)
{
	//随机数法
	//int key = left + rand()%(right - left);
	//三数取中
	int key = (left + right) / 2;
	
	if (a[left] < a[key])
	{
		if (a[key] < a[right])
		{
			Swap(a, left, key);
		}
		else
		{
			if (a[left] < a[right])
			{
				Swap(a, left, right);
			}
		}
	}
	else
	{
		if (a[key] > a[right])
		{
			Swap(a, left, key);
		}
		else
		{
			if (a[left] > a[right])
			{
				Swap(a, left, right);
			}
		}
	}
}

// 快速排序递归实现  (三数取中,随机取数)
// 快速排序hoare版本
void PartSort1(int* a, int left, int right)
{
	//递归结束条件
	if (left >= right)
	{
		return;
	}

	choose(a,left,right);
	
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
void PartSort2(int* a, int left, int right)
{
	//递归结束条件
	if (left >= right)
	{
		return;
	}

	choose(a, left, right);

	int key = a[left];
	int l = left;
	int r = right;

	while (left < right)
	{
		//找到从右向左第一个小于 a[key] 的值
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
		//找到从左往右第一个大于 a[key] 的值
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[right] = a[left];
	}
	a[left] = key;
	PartSort1(a, l, left - 1);
	PartSort1(a, left + 1, r);
}
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
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	//入栈方式 先入当前区间的左边，再入右边
	StackPush(&st, left);
	StackPush(&st, right);

	while (!StackEmpty(&st))
	{
		//弹栈时，先得到的是区间的右边，后得到左边
		right = StackTop(&st);
		StackPop(&st);
		left = StackTop(&st);
		StackPop(&st);

		//去除只有一个数或者没有数的情况的情况
		if (left >= right)
		{
			continue;
		}

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

		//先让右边区间入栈
		StackPush(&st, left+1);
		StackPush(&st, r);
		//左边区间入栈
		StackPush(&st, l);
		StackPush(&st, left - 1);
	}

	StackDestroy(&st);
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	int mid = (left + right) / 2;
	/*
	[0,7] -> [0,3] [4,7]
	递归[0,3] -> 划分[0,1][2,3]

	递归[0,1] ->划分[0,0][1,1] -->归并出有序的 [0,1]
	递归[2,3] ->划分[2,2][3,3] -->归并出有序的 [2,3]

	[0,1][2,3] --> 归并出有序的[0,3]

	递归[4,7] -> 划分[4,5][5,7]
	递归[4,5] ->划分[4,4][5,5] -->归并出有序的 [4,5]
	递归[6,7] ->划分[6,6][7,7] -->归并出有序的 [6,7]
	[4,5] [6,7] --> 归并出有序的[4,7]

	[0,3] [4,7] --> 归并出有序的[0,7]
	*/

	if (left >= right)
	{
		return;
	}

	//[left,mid]  [mid+1,right]
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	//两个有序数组的合并
	int begin1 = left, begin2 = mid + 1;
	int end1 = mid, end2 = right;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//将tmp排序好的数据拷贝到a数组对应位置
	memcpy(a + left, tmp + left, sizeof(int)* (right - left + 1));
}

// 归并排序递归实现
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);

	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
}
// 归并排序非递归实现
void MergeSortNonR(int* a, int n)//n为数组里元素的数量
{
	int* tmp = (int*)malloc(sizeof(int)* n);

	int size = 1;
	int count = (int)(log(n) / log(2)) + 1;;
	for (; size < n;size *= 2)
	{
		int i = 0;
		for (i = 0; i < n; i += size*2)
		{
			int left = i, mid = i + size,right = mid + size;

			//处理最后一组不满足size个大小的情况
			if (mid > n)
			{
				mid = n;
			}
			if (right > n)
			{
				right = n;
			}

			//两个有序数组的合并
			//[begin1,end1) [begin2,end2)
			int begin1 = left, begin2 = mid;
			int end1 = mid, end2 = right;
			int index = begin1;
			while (begin1 < end1 && begin2 < end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[index++] = a[begin1++];
				}
				else
				{
					tmp[index++] = a[begin2++];
				}
			}

			while (begin1 < end1)
			{
				tmp[index++] = a[begin1++];
			}

			while (begin2 < end2)
			{
				tmp[index++] = a[begin2++];
			}
		}
		// 将tmp排序好的数据拷贝到a数组对应位置
		memcpy(a, tmp, sizeof(int)* n);
	}
}
// 计数排序(非比较类)
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];

	//先找到数组中最大值和最小值
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}

		if (min > a[i])
		{
			min = a[i];
		}
	}
	//数据所在的一个范围
	int range = max - min + 1;
	int* arr = (int*)calloc(range,sizeof(int));

	//统计对应的数据出现的次数
	for (i = 0; i < n; i++)
	{
		int tmp = a[i] - min;
		arr[tmp]++;
	}
	int len = 0;
	//根据次数排序，返回原数组
	for (i = 0; i < range; i++)
	{
		while (arr[i])
		{
			a[len++] = i + min;
			arr[i]--;
		}
	}

	free(arr);
}
