#define _CRT_SECURE_NO_WARNINGS 1

//
//���⣺��ȤС��
//
//Ϊ�ḻͬѧ�ǵ�ҵ���Ļ����ĳ��Уѧ���ᴴ����3����ȤС��
//�����³�A�飬B�飬C�飩��
//ÿ��С���ѧ�������ֱ��ڡ�A.txt��, ��B.txt���͡�C.txt���С�
//ÿ���ļ��д洢����ѧ����ѧ�š�
//
//���ڹ�����Ҫ������������֪����
//�Ȳμ���A�飬�ֲμ���B�飬����û�вμ�C���ͬѧһ���ж����ˣ�
//
//����ͳ�Ƹ����ֲ�ͨ��������ύ�𰸡�
//--->20
//ע�⣺����һ����������Ҫ�ύ�κζ�������ݡ�
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