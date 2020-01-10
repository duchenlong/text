#define _CRT_SECURE_NO_WARNINGS 1

#include "qsort.h"

// ����ʵ�ֵĽӿ�

// ��������
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

// ϣ������
void ShellSort(int* a, int n)
{
	//Ԥ����  ���Ϊgap �Ĳ�������
	int gap = n;

	//gap != 1 -->Ԥ����׶�
	//gap == 1 --> ����׶�
	while (gap != 1)
	{
		gap = gap / 3 + 1; //����ÿ������ļ��
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

// ѡ������
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
// ������
//���½��������
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
// ð������
void BubbleSort(int* a, int n);

// ��������ݹ�ʵ��  (����ȡ��,���ȡ��)
// ��������hoare�汾
void PartSort1(int* a, int left, int right)
{
	//�ݹ��������
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
		//�ҵ����������һ��С�� a[key] ��ֵ
		while (left < right && a[right] >= a[key])
		{
			right--;
		}

		//�ҵ��������ҵ�һ������ a[key] ��ֵ
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
// ���������ڿӷ�
void PartSort2(int* a, int left, int right);
// ��������ǰ��ָ�뷨
void PartSort3(int* a, int left, int right)
{
	//�ݹ��������
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
// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right);
// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n);
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n);
// ��������
void CountSort(int* a, int n);
