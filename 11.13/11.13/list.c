#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

// ������ɾ��Ľӿ�
//��ʼ��˳���
void SeqListInit(SeqList* psl, size_t capacity)
{
	assert(psl);
	psl->array = (SLDataType*)malloc(sizeof(SLDataType)* capacity);
	psl->size = 0;
	psl->capicity = capacity;
}
//ɾ��˳���
void SeqListDestory(SeqList* psl)
{
	assert(psl);
	psl->size = 0;
}
//����
void CheckCapacity(SeqList* psl)
{
	assert(psl);
	if (psl->size == psl->capicity)
	{
		psl->array = realloc(psl->array, sizeof(SLDataType)* (psl->capicity)*2);
		psl->capicity *= 2;
	}
}
//ͷ��
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	assert(psl);
	
	CheckCapacity(psl);
	memmove(psl->array+1, psl->array, sizeof(SLDataType)*psl->size);
	psl->array[0] = x;
	psl->size++;
}
//ͷɾ
void SeqListPopBack(SeqList* psl)
{
	assert(psl);

	memmove(psl->array, psl->array + 1, sizeof(SLDataType)*(psl->size-1));
	psl->size--;
}
//β��
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	assert(psl);

	CheckCapacity(psl);
	psl->array[psl->size++] = x;
}
//βɾ
void SeqListPopFront(SeqList* psl)
{
	assert(psl);

	psl->size--;
}
//����
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
//ָ��λ�ò���
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	assert(psl && pos<psl->size);

	CheckCapacity(psl);
	memmove(psl->array+pos, psl->array+pos-1, sizeof(SLDataType)*(psl->size - pos + 1));
	psl->array[pos - 1] = x;
	psl->size++;
}
//ָ��λ��ɾ��
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
//ָ��Ԫ��ɾ��
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
//ָ��λ���޸�
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

// ��չ������ʵ��

//ð������
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
//���ֲ���
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
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1)
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
