#define _CRT_SECURE_NO_WARNINGS 1
//设计算法，用户输入合数，程序输出若个素数的乘积。例如，输入6，输出2*3。输入20，输出2*2*5。
//样例

#include<stdio.h>

int panduan(int a)
{
	int i = 0;
	for (i = 2; i < a / 2; i++)
	{
		if (a%i == 0)
		{
			break;
		}
	}
	if (i>(a / 2))
	{
		return 1;
	}
	return 0;
}
int main()
{
	int num=20 ,a= 20;
	int i = 1;
	int j = 0;
	printf("%d=", num);
	while (i != num)
	{
		for (j = 2; j < a ; j++)
		{
			if ((a % j == 0) && (panduan(j)==1))
			{
				printf("%d*", j);
				break;
			}
		}
		a= a / j;
		i = i*j;
	}
	printf("%d", j);
	return 0;
}
#if 0
#include<stdio.h>
int main()
{
	int a[3][2] = { 1, 2, 3, 4, 5, 6 };
	printf("%p \n", a[0]- a[0][1]);
	return 0;
}

#include<stdio.h>

int main()
{
	//int a[] = { 1, 2, 3, 4 };
	char a[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	printf("%d ", sizeof(a ));
	printf("%d ", sizeof(&a+1));
	printf("%d ", sizeof(a[1]));
	printf("%d ", sizeof(*&a));
	printf("%d ", sizeof(&a[0]+1));
	printf("%d ", sizeof(a + 0));
	printf("%d ", sizeof(a + 1));
	return 0;
}


#include<stdio.h>
#include  <string.h>
#include <stdio.h>

int int_cmp(const int* p1, const int* p2)
{
	return (*(int*)p1 > *( int *)p2);   
}
int main()
{
	int a[] = { 4, 5, 2, 8, 7, 1, 9, 3, 6 };
	int i = 0;
	qsort((int *)a, sizeof(a) / sizeof(a[0]), sizeof(int*), int_cmp);
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}

	/*int a[10] = { 0 };
	printf("%p\n", a);
	printf("%p\n", &a+1);
	printf("%d %d", sizeof(a), sizeof(a[0]));*/
	/*char* a = "axcdfvgb";
	char b[] = "axdfvgb";
	char* c = "axcdfvgb";
	printf("%p\n", a);
	printf("%p\n", &a[0]);
	printf("%p\n", &a[1]);
	printf("%p\n", a+1);
	printf("\n");
	printf("%p\n",b);
	printf("%p\n", &b[0]);
	printf("%p\n", &b[1]);
	printf("%p\n", b + 1);
	printf("\n");
	printf("%p\n", c);*/
	return 0;
}
#endif