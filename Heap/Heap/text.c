#define _CRT_SECURE_NO_WARNINGS 1

#include "heap.h"

void txt(Heap* hp)
{
	int a[6] = { 3, 5, 9, 6, 7, 2 };
	HeapCreate(hp, a, 6);
	HeapPush(hp, 1);

	int i = 0;
	HeapPop(hp);
	printf("%d\n", HeapTop(hp));

	// 堆的数据个数
	printf("%d\n", HeapSize(hp));

	// 堆的判空
	printf("%d\n", HeapEmpty(hp));
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_a[i]);
	}
}

void txt2(Heap* hp)
{
	int i = 0;

	srand(time(0));
	int a[1000] = { 0 };
	for (i = 0; i < 1000; i++)
	{
		a[i] = rand() % 10000;
	}

	a[0] = 2;
	a[3] = -3;
	a[456] = -99;
	a[987] = 5;
	a[657] = 3;
	a[568] = -39;
	a[234] = -33;
	a[123] = 4;

	// 对数组进行堆排序  最小的十个数  大根堆
	BHeapSort(hp,a,1000);

	for (i = 0; i < 10; i++)
	{
		printf("%d ", hp->_a[i]);
	}
}

void txt3(Heap* hp)
{
	int i = 0;

	srand(time(0));
	int a[1000] = { 0 };
	for (i = 0; i < 1000; i++)
	{
		a[i] = rand() % 10000;
	}

	a[0] = 99999;
	a[3] = 88888;
	a[456] = 777777;
	a[987] = 555555;
	a[657] = 22222;
	a[568] = 66666;
	a[234] = 111111;
	a[123] = 4444563;

	// 对数组进行堆排序  最大的十个数  小根堆
	SHeapSort(hp, a, 1000);

	for (i = 0; i < 10; i++)
	{
		printf("%d ", hp->_a[i]);
	}
}

int main()
{
	Heap* hp = (Heap*)malloc(sizeof(Heap));
	HeapInit(hp);
	txt(hp);
	int i = 0;
	//txt2(hp);
	//txt3(hp);
	
	return 0;
}