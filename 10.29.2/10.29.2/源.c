#define _CRT_SECURE_NO_WARNINGS 1

//ú����Ŀ
//
//��һ��ú�򣬶ѳ�������׶�Ρ����壺
//��һ���1����
//�ڶ���3�������г������Σ���
//������6�������г������Σ���
//���Ĳ�10�������г������Σ���
//....
//���һ����100�㣬���ж��ٸ�ú��
//
//�����ʾú������Ŀ�����֡�
//ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�
//
#if 0
#include<stdio.h>

int main()
{
	int i = 0;
	int num = 0;
	int a[101] = { 0 };
	for (i = 1; i < 101; i++)
	{
		a[i] = a[i - 1] + i;
		num += a[i];
	}
	printf("%d", num);

	return 0;
}
#endif

//����ʽ
//
//     B      DEF
//A + -- - +------ - = 10
//     C      GHI
//
//�������ʾ�����⣬���Բμ���ͼ1.jpg����
//
//
//�����ʽ��A~I����1~9�����֣���ͬ����ĸ����ͬ�����֡�
//
//���磺
//6 + 8 / 3 + 952 / 714 ����һ�ֽⷨ��
//5 + 3 / 1 + 972 / 486 ����һ�ֽⷨ��
//
//�����ʽһ���ж����ֽⷨ��
//
//ע�⣺���ύӦ���Ǹ���������Ҫ��д�κζ�������ݻ�˵�������֡�

#if 0
#include<stdio.h>
#include<string.h>

int  arr[10] = { 0 };
int ans = 0;
int visit[10] = { 0 };


int judge(int* arr)
{
	double x = arr[1] + (double)arr[2] / arr[3] + (double)(arr[4] * 100 + arr[5] * 10 + arr[6]) / (arr[7] * 100 + arr[8] * 10 + arr[9]);
	if (x == 10)
	{
		return 1;
	}
	return 0;
}

int main()
{
	int a, b, c, d, e, f, g, h, i;
	for (a = 1; a <= 9; a++)
	{
		memset(arr, 0, sizeof(arr));
		arr[a] = 1;
		for (b = 1; b <= 9; b++)
		{
			memset(arr, 0, sizeof(arr));
			arr[a] = 1;
			if (arr[b] == 1)
			{
				continue;
			}
			arr[b] = 1;
			for (c = 1; c <= 9; c++)
			{
				memset(arr, 0, sizeof(arr));
				arr[a] = 1;
				arr[b] = 1;
				if (arr[c] == 1)
				{
					continue;
				}
				arr[c] = 1;
				for (d = 1; d <= 9; d++)
				{
					memset(arr, 0, sizeof(arr));
					arr[a] = 1;
					arr[b] = 1;
					arr[c] = 1;
					if (arr[d] == 1)
					{
						continue;
					}
					arr[d] = 1;
					for (e = 1; e <= 9; e++)
					{
						memset(arr, 0, sizeof(arr));
						arr[a] = 1;
						arr[b] = 1;
						arr[c] = 1;
						arr[d] = 1;
						if (arr[e] == 1)
						{
							continue;
						}
						arr[e] = 1;
						for (f = 1; f <= 9; f++)
						{
							memset(arr, 0, sizeof(arr));
							arr[a] = 1;
							arr[b] = 1;
							arr[c] = 1;
							arr[d] = 1;
							arr[e] = 1;
							if (arr[f] == 1)
							{
								continue;
							}
							arr[f] = 1;
							for (g = 1; g <= 9; g++)
							{
								memset(arr, 0, sizeof(arr));
								arr[a] = 1;
								arr[b] = 1;
								arr[c] = 1;
								arr[d] = 1;
								arr[e] = 1;
								arr[f] = 1;
								if (arr[g] == 1)
								{
									continue;
								}
								arr[g] = 1;
								for (h = 1; h <= 9; h++)
								{
									memset(arr, 0, sizeof(arr));
									arr[a] = 1;
									arr[b] = 1;
									arr[c] = 1;
									arr[d] = 1;
									arr[e] = 1;
									arr[f] = 1;
									arr[g] = 1;
									if (arr[h] == 1)
									{
										continue;
									}
									arr[h] = 1;
									for (i = 1; i <= 9; i++)
									{
										memset(arr, 0, sizeof(arr));
										arr[a] = 1;
										arr[b] = 1;
										arr[c] = 1;
										arr[d] = 1;
										arr[e] = 1;
										arr[f] = 1;
										arr[g] = 1;
										arr[h] = 1;
										if (arr[i] == 1)
										{
											continue;
										}
										arr[i] = 1;
										visit[1] = a;
										visit[2] = b;
										visit[3] = c;
										visit[4] = d;
										visit[5] = e;
										visit[6] = f;
										visit[7] = g;
										visit[8] = h;
										visit[9] = i;
										if (judge(visit))
										{
											ans++;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d", ans);
	return 0;
}
#endif
//��ǩ
//
//X����Ҫ�ɳ�һ��5����ɵĹ۲���ǰ��W�ǡ�
//���У�
//A���������ɳ�4�ˡ�
//B���������ɳ�2�ˡ�
//C���������ɳ�2�ˡ�
//....
//
//��ô��������W�ǵĹ۲��Ż��ж����ֹ���Ĳ�ͬ����أ�
//
//����ĳ�������������⡣
//����a[] �м���ÿ�����ҿ����ɳ����������
//����ִ�н��Ϊ��
//DEFFF
//CEFFF
//CDFFF
//CDEFF
//CCFFF
//CCEFF
//CCDFF
//CCDEF
//BEFFF
//BDFFF
//BDEFF
//BCFFF
//BCEFF
//BCDFF
//BCDEF
//....
//(����ʡ�ԣ��ܹ�101��)
//
//
//#include <stdio.h>
//#define N 6
//#define M 5
//#define BUF 1024
//
//void f(int a[], int k, int m, char b[])
//{
//	int i, j;
//
//	if (k == N){
//		b[M] = 0;
//		if (m == 0) printf("%s\n", b);
//		return;
//	}
//
//	for (i = 0; i <= a[k]; i++){
//		for (j = 0; j<i; j++) b[M - m + j] = k + 'A';
//		______________________;  //���λ��
//	}
//}
//int main()
//{
//	int  a[N] = { 4, 2, 2, 1, 1, 3 };
//	char b[BUF];
//	f(a, 0, M, b);
//	return 0;
//}
//
//��ϸ�Ķ����룬��д���߲���ȱ�ٵ����ݡ�
//
//ע�⣺��Ҫ��д�κ��������ݻ�˵�������֡�

#include <stdio.h>
#define N 6
#define M 5
#define BUF 1024

void f(int a[], int k, int m, char b[])
{
	int i, j;

	if (k == N){
		b[M] = 0;
		if (m == 0) printf("%s\n", b);
		return;
	}

	for (i = 0; i <= a[k]; i++){
		for (j = 0; j<i; j++) b[M - m + j] = k + 'A';
		//______________________;  //���λ��
		f(a, k + 1, m-i, b);
	}
}
int main()
{
	int  a[N] = { 4, 2, 2, 1, 1, 3 };
	char b[BUF];
	f(a, 0, M, b);
	return 0;
}