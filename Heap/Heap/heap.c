#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"


//��������ڵ�
void SwapHeap(HPDataType* a, int child,int parent)
{
	HPDataType tmp = a[child];
	a[child] = a[parent];
	a[parent] = tmp;
}

//��ʼ����
void HeapInit(Heap* hp)
{
	hp->_capacity = hp->_size = 0;
}

//���µ���(С����)
void AddjustDown(HPDataType* a,int n, int root)
{
	int child = root * 2+1;
	int parent = root;

	while (child<n)
	{
		//�����Һ����бȽ�С��
		if (a[child + 1] < a[child] && child + 1<=n-1)
		{
			child++;
		}

		if (a[child] < a[parent])
		{
			SwapHeap(a, child, parent);
			parent = child;
			child = parent*2+1;
		}
		else
		{
			break;
		}
	}
}

//�ѱٿռ�,����
void AddCapacity(Heap* hp, int n)
{
	hp->_capacity = n;
	
	hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType)* hp->_capacity);
}

// �ѵĹ��� (С����)
void HeapCreate(Heap* hp, HPDataType* a, int n)
{
	int i = 0;
	hp->_capacity = n;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)* hp->_capacity);
	
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
		hp->_size++;
	}

	for (i = hp->_size-1; i >=0; i--)
	{
		AddjustDown(hp->_a, n, i);
	}
	
}

// �ѵ�����
void HeapDestory(Heap* hp)
{
	free(hp->_a);
	hp->_capacity = hp->_size = 0;
	free(hp);
}

//���ϵ���(С����)
void AddjustUp(HPDataType* a, int n, int child)
{
	while (child>0)
	{
		HPDataType parent = (child - 1) / 2;
		if (a[child] < a[parent])
		{
			SwapHeap(a, child, parent);
		}
		else
		{
			break;
		}

		child = parent;
	}
}

// �ѵĹ���  (�����)
void BigHeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_capacity = n;
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)* hp->_capacity);

	int i = 0;
	for (i = 0; i < n; i++)
	{
		hp->_a[i] = a[i];
		hp->_size++;
	}

	for (i = n - 1; i >= 0; i--)
	{
		SubjustDown(hp->_a, n, i);
	}
}

//���ϵ���(�����)
void SubjustUp(HPDataType* a, int n, int child)
{
	while (child > 0)
	{
		HPDataType parent = (child - 1) / 2;
		if (a[child] > a[parent])
		{
			SwapHeap(a, child, parent);
		}
		else
		{
			break;
		}

		child = parent;
	}
}

//���µ���(�����)
void SubjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = root * 2 + 1;

	while (child < n)
	{

		if (a[child] < a[child + 1] && child + 1 <= n - 1)
		{
			child++;
		}

		if (a[child]>a[parent])
		{
			SwapHeap(a, child, parent);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_capacity == hp->_size)
	{
		AddCapacity(hp, hp->_capacity * 2);
	}

	hp->_a[hp->_size++] = x;
	AddjustUp(hp->_a, hp->_size-1, hp->_size-1);
}

// �ѵ�ɾ��(head Pop)
void HeapPop(Heap* hp)
{
	SwapHeap(hp->_a, 0, hp->_size-1);

	hp->_size--;

	AddjustUp(hp->_a, hp->_size, 0);
}

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	return hp->_size;
}

// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}

// ��������ж�����  (�����ݵ�ǰʮ�������)
void SHeapSort(Heap* hp,int* a, int n)
{
	HeapCreate(hp, a, 10);

	int i = 10;
	for (i = 10; i < n; i++)
	{
		if (a[i]>HeapTop(hp))
		{
			hp->_a[0] = a[i];
			AddjustDown(hp->_a, 10, 0);
		}
	}
}

// ��������ж����� (��С��)
void BHeapSort(Heap* hp, int* a, int n)
{
	BigHeapCreate(hp, a, 10);

	int i = 10;
	for (i = 10; i < n; i++)
	{
		if (a[i]<HeapTop(hp))
		{
			hp->_a[0] = a[i];
			SubjustDown(hp->_a, 10, 0);
		}
	}
}