#define _CRT_SECURE_NO_WARNINGS 1

#include "qsort.h"
#include "stack.h"

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

void choose(int* a,int left,int right)
{
	//�������
	//int key = left + rand()%(right - left);
	//����ȡ��
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

// ��������ݹ�ʵ��  (����ȡ��,���ȡ��)
// ��������hoare�汾
void PartSort1(int* a, int left, int right)
{
	//�ݹ��������
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
void PartSort2(int* a, int left, int right)
{
	//�ݹ��������
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
		//�ҵ����������һ��С�� a[key] ��ֵ
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[left] = a[right];
		//�ҵ��������ҵ�һ������ a[key] ��ֵ
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
void QuickSortNonR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);
	//��ջ��ʽ ���뵱ǰ�������ߣ������ұ�
	StackPush(&st, left);
	StackPush(&st, right);

	while (!StackEmpty(&st))
	{
		//��ջʱ���ȵõ�����������ұߣ���õ����
		right = StackTop(&st);
		StackPop(&st);
		left = StackTop(&st);
		StackPop(&st);

		//ȥ��ֻ��һ��������û��������������
		if (left >= right)
		{
			continue;
		}

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

		//�����ұ�������ջ
		StackPush(&st, left+1);
		StackPush(&st, r);
		//���������ջ
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
	�ݹ�[0,3] -> ����[0,1][2,3]

	�ݹ�[0,1] ->����[0,0][1,1] -->�鲢������� [0,1]
	�ݹ�[2,3] ->����[2,2][3,3] -->�鲢������� [2,3]

	[0,1][2,3] --> �鲢�������[0,3]

	�ݹ�[4,7] -> ����[4,5][5,7]
	�ݹ�[4,5] ->����[4,4][5,5] -->�鲢������� [4,5]
	�ݹ�[6,7] ->����[6,6][7,7] -->�鲢������� [6,7]
	[4,5] [6,7] --> �鲢�������[4,7]

	[0,3] [4,7] --> �鲢�������[0,7]
	*/

	if (left >= right)
	{
		return;
	}

	//[left,mid]  [mid+1,right]
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	//������������ĺϲ�
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
	//��tmp����õ����ݿ�����a�����Ӧλ��
	memcpy(a + left, tmp + left, sizeof(int)* (right - left + 1));
}

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);

	_MergeSort(a, tmp, 0, n - 1);

	free(tmp);
}
// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n)//nΪ������Ԫ�ص�����
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

			//�������һ�鲻����size����С�����
			if (mid > n)
			{
				mid = n;
			}
			if (right > n)
			{
				right = n;
			}

			//������������ĺϲ�
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
		// ��tmp����õ����ݿ�����a�����Ӧλ��
		memcpy(a, tmp, sizeof(int)* n);
	}
}
// ��������(�ǱȽ���)
void CountSort(int* a, int n)
{
	int min = a[0];
	int max = a[0];

	//���ҵ����������ֵ����Сֵ
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
	//�������ڵ�һ����Χ
	int range = max - min + 1;
	int* arr = (int*)calloc(range,sizeof(int));

	//ͳ�ƶ�Ӧ�����ݳ��ֵĴ���
	for (i = 0; i < n; i++)
	{
		int tmp = a[i] - min;
		arr[tmp]++;
	}
	int len = 0;
	//���ݴ������򣬷���ԭ����
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
