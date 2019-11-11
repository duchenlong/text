#define _CRT_SECURE_NO_WARNINGS 1

//
//标题：兴趣小组
//
//为丰富同学们的业余文化生活，某高校学生会创办了3个兴趣小组
//（以下称A组，B组，C组）。
//每个小组的学生名单分别在【A.txt】, 【B.txt】和【C.txt】中。
//每个文件中存储的是学生的学号。
//
//由于工作需要，我们现在想知道：
//既参加了A组，又参加了B组，但是没有参加C组的同学一共有多少人？
//
//请你统计该数字并通过浏览器提交答案。
//--->20
//注意：答案是一个整数，不要提交任何多余的内容。
#include<stdio.h>
#include<string.h>

int main()
{
	char A[1000][20];
	char B[1000][20];
	char C[1000][20];
	int lenA, lenB, lenC;
	int len = 0;
	int i = 0,j=0,k=0;
	printf("A\n");
	while (1)
	{
		scanf("%s,", A[i]);
		i++;
		if (A[i-1][0] == '-')
		{
			break;
		}
	}
	lenA = i - 1;
	printf("B\n");
	while (1)
	{
		scanf("%s,", B[i]);
		i++;
		if (B[i - 1][0] == '-')
		{
			break;
		}
	}
	lenB = i - 1;
	printf("C\n");
	while (1)
	{
		scanf("%s,", C[i]);
		i++;
		if (C[i - 1][0] == '-')
		{
			break;
		}
	}
	lenC = i - 1;
	for (i = 0; i<lenA; i++)
	{
		for (j = 0; j < lenB; j++)
		{
			if (strcmp(B[j], A[i]) == 0)
			{
				int flag = 0;
				for (k = 0; k < lenC; k++)
				{
					if (strcmp(C[k], A[i]) ==0)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					len++;
				}
				break;
			}
		}
	}
	printf("%d\n", len);
	return 0;
}