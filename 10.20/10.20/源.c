#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//��������
//
//�����ڸ��ֳ��Ͼ������õ���
//����������ʮ�ֳ��õĸ�Ч�ʵ��㷨��
//
//��˼���ǣ���ѡһ������ߡ���
//�������������й�һ��ɸ�ӣ�
//�Ա�֤������ߵ�Ԫ�ض��������������ұߵ�Ԫ�ض���С������
//
//��������������ͱ��ָ�Ϊ���������䡣
//�ٷֱ������������Ϳ����ˡ�
//
//����Ĵ�����һ��ʵ�֣����������д���߲���ȱ�ٵĴ��롣


#include <stdio.h>

void swap(int a[], int i, int j)
{
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

int partition(int a[], int p, int r)
{
	int i = p;
	int j = r + 1;
	int x = a[p];
	while (1){
		while (i<r && a[++i]<x);
		while (a[--j]>x);
		if (i >= j) break;
		swap(a, i, j);
	}
	//______________________;
	swap(a, p, j);
	return j;
}

void quicksort(int a[], int p, int r)
{
	if (p<r){
		int q = partition(a, p, r);
		quicksort(a, p, q - 1);
		quicksort(a, q + 1, r);
	}
}

int main()
{
	int i;
	int a[] = { 5, 13, 6, 24, 2, 8, 19, 27, 6, 12, 1, 17 };
	int N = 12;

	quicksort(a, 0, N - 1);

	for (i = 0; i<N; i++) printf("%d ", a[i]);
	printf("\n");

	return 0;
}


//ע�⣺ֻ��дȱ�ٵ����ݣ���Ҫ��д�κ��������д����˵�������֡�

#endif

//����βһ
//
//����Ĵ����һ�������Ķ����Ʊ�ʾ�����ұߵ�������1ȫ�����0
//������һλ��0����ԭ���ֱ��ֲ��䡣
//
//������ô����еĲ������ݣ�Ӧ�������
//00000000000000000000000001100111   00000000000000000000000001100000
//00000000000000000000000000001100   00000000000000000000000000001100
//
//����ϸ�Ķ�������д���߲���ȱ�ٵĴ��롣

#if 0
#include <stdio.h>

void f(int x)
{
	int i;
	for (i = 0; i<32; i++) printf("%d", (x >> (31 - i)) & 1);
	printf("   ");

	//x = _______________________;
	x = x&(x+1);
	for (i = 0; i<32; i++) printf("%d", (x >> (31 - i)) & 1);
	printf("\n");
}

int main()
{
	f(103);
	f(12);
	return 0;
}

//ע�⣺ֻ��дȱ�ٵ����ݣ���Ҫ��д�κ��������д����˵�������֡�
#endif

//������ҵ
//
//����Сѧ����ѧ��ĿҲ������ô����ġ�
//�������������ҵ��
//
//�� + �� = ��
//�� - �� = ��
//�� �� �� = ��
//�� �� �� = ��
//
//(�����ʾ�����������Բμ���ͼ1.jpg��)
//
//ÿ���������1~13�е�ĳһ�����֣��������ظ���
//���磺
//6 + 7 = 13
//9 - 8 = 1
//3 * 4 = 12
//10 / 2 = 5
//
//�Լ���
//7 + 6 = 13
//9 - 8 = 1
//3 * 4 = 12
//10 / 2 = 5
//
//�������ֽⷨ�����ӷ����˷������ɺ��㲻ͬ�ķ�����
//
//��һ���ҵ��˶����ַ�����
//
//
//����д��ʾ������Ŀ��������
//ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�

#include<stdio.h>

void bianli(int* a)
{
	int i = 0;
	for (i = 0; i <= 13; i++)
	{
		a[i] = 1;
	}
}
int main()
{
	int add = 0;
	int sub = 0;
	int mul= 0;
	int div = 0;
	int count = 0;
	int i = 0;
	int j = 0;
	int m = 0;
	int n = 0;
	for (add =1; add <= 13; add++)
	{
		int a[14] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
		for (i = 1; i <= 13-add; i++)
		{
			bianli(a);
			a[add] = 0;
			if ((a[i] != 1) || (a[add+i]!=1))
			{
				continue;
			}
			for (sub = 13; sub >0; sub--)
			{
				bianli(a);
				a[add] = 0;
				a[i] = 0;
				a[add + i] = 0;
				if (a[sub]!= 1)
				{
					continue;
				}
				for (j = 1; j <sub; j++)
				{
					bianli(a);
					a[add] = 0;
					a[i] = 0;
					a[add + i] = 0;
					a[sub] = 0;
					if (a[j] != 1)
					{
						continue;
					}
					a[j] = 0;
					if (a[sub - j] != 1)
					{
						continue;
					}
					for (mul = 1; mul <= 13; mul++)
					{
						bianli(a);
						a[add] = 0;
						a[i] = 0;
						a[add + i] = 0;
						a[sub] = 0;
						a[j] = 0;
						a[sub - j] = 0;
						if (a[mul] != 1)
						{
							continue;
						}
						for (m = 1; m <= (13/mul); m++)
						{
							bianli(a);
							a[add] = 0;
							a[i] = 0;
							a[add + i] = 0;
							a[sub] = 0;
							a[j] = 0;
							a[sub - j] = 0;
							a[mul] = 0;
							if (a[m] != 1) 
							{
								continue;
							}
							a[m] = 0;
							if  (a[m*mul] != 1)
							{
								continue;
							}
							for (div = 13; div > 0; div--)
							{
								bianli(a);
								a[add] = 0;
								a[i] = 0;
								a[add + i] = 0;
								a[sub] = 0;
								a[j] = 0;
								a[sub - j] = 0;
								a[m] = 0;
								a[mul] = 0;
								a[m*mul] = 0;
								if (a[div] != 1)
								{
									continue;
								}
								a[div] = 0;
								for (n = 1; n < div; n++)
								{
									bianli(a);
									a[add] = 0;
									a[i] = 0;
									a[add + i] = 0;
									a[sub] = 0;
									a[j] = 0;
									a[sub - j] = 0;
									a[m] = 0;
									a[mul] = 0;
									a[m*mul] = 0;
									a[div] = 0;
									if ((div%n )!= 0)
									{
										continue;
									}
									if (a[n] != 1)
									{
										continue;
									}
									a[n] = 0;
									if (a[div/n] != 1)
									{
										continue;
									}
									count++;
									printf("%d+%d=%d\n", add, i, add + i);
									printf("%d-%d=%d\n", sub, j, sub-j);
									printf("%d*%d=%d\n", mul, m, mul*m);
									printf("%d/%d=%d\n", div, n, div/n);
									printf("\n");
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", count);
	return 0;
}