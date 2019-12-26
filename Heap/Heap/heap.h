#pragma once

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>

typedef int HPDataType;
#define MAX 10

typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

//��ʼ����
void HeapInit(Heap* hp);

// �ѵĹ���  (С����)
void HeapCreate(Heap* hp, HPDataType* a, int n);

// �ѵĹ���  (�����)
void BigHeapCreate(Heap* hp, HPDataType* a, int n);

//���µ���(�����)
void SubjustDown(HPDataType* a, int n, int root);

//���ϵ���(�����)
void SubjustUp(HPDataType* a, int n, int child);

// �ѵ�����
void HeapDestory(Heap* hp);

// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x);

// �ѵ�ɾ��
void HeapPop(Heap* hp);

// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp);

// �ѵ����ݸ���
int HeapSize(Heap* hp);

// �ѵ��п�
int HeapEmpty(Heap* hp);

// ��������ж�����  (����)
void SHeapSort(Heap* hp,int* a, int n);

// ��������ж����� (��С��)
void BHeapSort(Heap* hp, int* a, int n);