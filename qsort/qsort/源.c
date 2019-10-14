#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
//用冒泡排序法模拟实现qsort
int int_cmp(const void* p1, const void* p2)
{
	return *(int *)p1 - *(int *)p2;
}

void swap(void* p1,void* p2,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		char tmp=*((char*)p1 + i);
		*((char*)p1 + i) = *((char*)p2 + i);
		*((char*)p2+ i) = tmp;
	}
}
void qsort_pop(void* a,int len, int size, int (*int_cmp)(void*,void*))
{
	//len-->数组长度  size-->数组的一个数据所占的字节数
	//(*int_cmp)(void*,void*)-->回调函数int_cmp，参数类型为void*
	int i = 0;
	int j = 0;
	for (i = 1; i < len; i++)
	{
		for (j = 0; j < len - 1-i; j++)
		{
			//判断数组中两个数的大小
			//因为所传的数据类型为void，所以需要进行强转
			//char类型在内存中占一个字节，可以用数据的第一个字节+一个数据的字节数来表示这个void型数据
			if (int_cmp((char*)a + j*size, (char*)a + (j + 1)*size)>0)
			{
				swap((char*)a + j*size, (char*)a + (j + 1)*size,size);//调用交换函数
			}
		}
	}
}

int main()
{
	int a[10] = { 2, 4, 9, 8, 7, 5, 6, 3, 1, 10 };
	int i = 0;
	qsort_pop(a, sizeof(a) / sizeof(a[0]), sizeof(int), int_cmp);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
#if 0
//qsort
int int_cmp(const void* p1,const void* p2)
{
	return *(int *)p1-*(int *)p2;
	//void 不能进行解引用，使用数据时需要进行强转为int 或 char类型
}

int main()
{
	int a[10] = { 2, 4, 9, 8, 7, 5, 6, 3, 1, 10 };
	int i = 0;
	qsort(a,sizeof(a)/sizeof(a[0]),sizeof(int),int_cmp);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
#endif