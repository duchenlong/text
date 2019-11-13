#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

// 基本增删查改接口
//初始化顺序表
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->array = (SLDataType*)malloc(sizeof(SLDataType)* capacity);
	psl->size = 0;
	psl->capicity = capacity;
}
//删除顺序表
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	psl->size = 0;
}
//扩容
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		psl->array = realloc(psl->array, sizeof(SLDataType)* (psl->capicity)*2);
		psl->capicity *= 2;
	}
}
//头插
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	
	CheckCapacity(psl);
	memmove(psl->array+1, psl->array, sizeof(SLDataType)*psl->size);
	psl->array[0] = x;
	psl->size++;
}
//头删
void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	memmove(psl->array, psl->array + 1, sizeof(SLDataType)*(psl->size-1));
	psl->size--;
}
//尾插
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);
	psl->array[psl->size++] = x;
}
//尾删
void SeqListPopFront(SeqList* psl)
{
	assert(psl);

	psl->size--;
}
//查找
int SeqListFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	size_t i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i+1;
		}
	}
	return -1;
}
//指定位置插入
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl && pos<psl->size);

	CheckCapacity(psl);
	memmove(psl->array+pos, psl->array+pos-1, sizeof(SLDataType)*(psl->size - pos + 1));
	psl->array[pos - 1] = x;
	psl->size++;
}
//指定位置删除
void SeqListErase(SeqList* psl, size_t pos)
{
	assert(psl && (pos>0 && pos < psl->size));

	size_t i = pos-1;
	for (; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
//指定元素删除
void SeqListRemove(SeqList* psl, SLDataType x)
{
	assert(psl);

	size_t i = 0;
	for (i = 0; i<psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			memmove(psl->array + i, psl->array + i + 1, sizeof(SLDataType)*(psl->size - i - 1));
			psl->size--;
			return;
		}
	}
}
//指定位置修改
void SeqListModify(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl && (pos>0 && pos < psl->size));

	psl->array[pos - 1] = x;
}

void SeqListPrint(SeqList* psl)
{
	size_t i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
}

// 扩展面试题实现

//冒泡排序
void SeqListBubbleSort(SeqList* psl)
{
	assert(psl);

	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < psl->size - 1; i++)
	{
		for (j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->array[j]>psl->array[j + 1])
			{
				SLDataType tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
			}
		}
	}
}
//二分查找
int SeqListBinaryFind(SeqList* psl, SLDataType x)
{
	assert(psl);

	int left = 0;
	int right = (int)psl->size;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (psl->array[mid] == x)
		{
			return mid+1;
		}
		else if (psl->array[mid] < x)
		{
			left = mid+1;
		}
		else
		{
			right = mid;
		}
	}
	return -1;
}
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1)
void SeqListRemoveAll(SeqList* psl, SLDataType x)
{
	assert(psl);
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->array[i] != x)
		{
			psl->array[j] = psl->array[i];
			j++;
		}
	}
	psl->size = j;
}
