#define _CRT_SECURE_NO_WARNINGS 1
//��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
#include<stdio.h>
#if 0
void Paixu(int* a,int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			int t = 0;
			t = a[i];
			a[i] = a[j];
			a[j] = t;
			j++;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(a) / sizeof(a[0]);
	Paixu(a,n);
	return 0;
}
#endif
////���Ͼ���
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//
//���飺
//1 2 3
//2 3 4
//3 4 5
//
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
/// ��py ��������������
void find(int arr[3][3], int *px, int * py, int key)
{
	if (key > arr[*px-1][*py-1])
	{
		printf("�����ֲ�����\n");
	}
	else
	{
		int i = 0,j=(*py);
		while (i<(*px)*(*py))
		{
			if (key == arr[*px - 1][*py - 1])
			{
				printf("�����ֵ�λ����%d,%d\n", *px, *py);
				(*px)--;
				*py = j;
			}
			/*else if (key > arr[*px - 1][*py - 1])
			{
				(*px)--;
			}*/
			else if (key <arr[*px - 1][*py - 1])
			{
				(*py)--;
			}
			if (*py < 0)
			{
				(*py) = j;
				(*px)--;
			}
			i++;
		}
	}
}
int main()
{
	//int arr[3][3] = { 1,3,4,2,4,5,4,5,6 };
	//int arr[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int arr[3][3] = { 1, 2, 3,2,3,4,3,4,5};
	int x = 3;
	int y = 3;
	find(arr, &x, &y, 4);
	return 0;
}