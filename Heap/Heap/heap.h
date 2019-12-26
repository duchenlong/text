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

//初始化堆
void HeapInit(Heap* hp);

// 堆的构建  (小根堆)
void HeapCreate(Heap* hp, HPDataType* a, int n);

// 堆的构建  (大根堆)
void BigHeapCreate(Heap* hp, HPDataType* a, int n);

//向下调整(大根堆)
void SubjustDown(HPDataType* a, int n, int root);

//向上调整(大根堆)
void SubjustUp(HPDataType* a, int n, int child);

// 堆的销毁
void HeapDestory(Heap* hp);

// 堆的插入
void HeapPush(Heap* hp, HPDataType x);

// 堆的删除
void HeapPop(Heap* hp);

// 取堆顶的数据
HPDataType HeapTop(Heap* hp);

// 堆的数据个数
int HeapSize(Heap* hp);

// 堆的判空
int HeapEmpty(Heap* hp);

// 对数组进行堆排序  (最大的)
void SHeapSort(Heap* hp,int* a, int n);

// 对数组进行堆排序 (最小的)
void BHeapSort(Heap* hp, int* a, int n);