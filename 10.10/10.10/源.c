#define _CRT_SECURE_NO_WARNINGS 1
//�����������Ĵ��������������ַ����е��ַ���*���Ƶ��ַ�����ǰ���֣�
//ǰ��ķǡ�*���ַ����ƣ����ǲ��ܸı�ǡ�*���ַ����Ⱥ�˳��, ���������ַ����зǡ�*���ַ���������
//���磺ԭʼ��ΪHel**l**o**bi*ter, �����Ϊ*******Hellobiter��������10.
//����ԭ�ͣ�void MoveStr(char *str)��

#include<stdio.h>
#include<stdlib.h>
int MoveStr(char* str)
{
	int len = strlen(str);
	int i = 0, j = len-1;
	for (i = len-1; i >= 0; i--)
	{
		if (*(str + j) != '*')
		{
			j--;
		}
		else if (*(str+i)!='*')
		{
			*(str + j) = *(str + i);
			*(str + i) = '*';
			j--;
		}
	}
	return len-j-1;
}
int main()
{
	char arr[] = "hel**l**o**bi*ter";
	int num = MoveStr(arr);
	printf("%d\n", num);
	puts(arr);
	return 0;
}
#if 0
#include<stdio.h>
#include<stdlib.h>

int MoveStr(char* str)
{
	int  num = 0;
	int count = 0;
	int len = strlen(str);
	int i = 0;
	int j = 0;
	char* p = str;
	for (i = 0; i<len; i++)
	{
		if ((*(str + i) == '*') && (count == 0))
		{
			j = i;
			count = 1;
		}
		if ((*(str + i) != '*') && (count == 1))
		{
			int n = i;
			count = 0;
			for (int k = j - 1; k >= num; k--)
			{
				char t = *(str + k);
				*(str + k) = *(str + n - 1);
				*(str + n - 1) = t;
				n--;
			}
			num += i - j;
		}
	}
	if (*(str + j) == '*')
	{
		int m = len;
		int n = j;
		for (j; j >= num; j--)
		{
			char t = *(str + j - 1);
			*(str + j - 1) = *(str + m - 1);
			*(str + m - 1) = t;
			m--;
		}
		num += len - n;
	}
	return len - num;
}

int main()
{
	char arr[] = "hel**l**o**bi*ter*";
	int num = MoveStr(arr);
	printf("%d\n", num);
	puts(arr);
	return 0;
}
#endif