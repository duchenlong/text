#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
//��ð������ģ��ʵ��qsort
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
	//len-->���鳤��  size-->�����һ��������ռ���ֽ���
	//(*int_cmp)(void*,void*)-->�ص�����int_cmp����������Ϊvoid*
	int i = 0;
	int j = 0;
	for (i = 1; i < len; i++)
	{
		for (j = 0; j < len - 1-i; j++)
		{
			//�ж��������������Ĵ�С
			//��Ϊ��������������Ϊvoid��������Ҫ����ǿת
			//char�������ڴ���ռһ���ֽڣ����������ݵĵ�һ���ֽ�+һ�����ݵ��ֽ�������ʾ���void������
			if (int_cmp((char*)a + j*size, (char*)a + (j + 1)*size)>0)
			{
				swap((char*)a + j*size, (char*)a + (j + 1)*size,size);//���ý�������
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
	//void ���ܽ��н����ã�ʹ������ʱ��Ҫ����ǿתΪint �� char����
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