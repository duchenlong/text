#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#include<stdio.h>
#include<string.h>

void Inverse(char* left,char* right)
{
	char tmp;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void rotate(char* arr,const int k,const int len)
{
	Inverse(arr, arr + k - 1);
	Inverse(arr + k, arr + len - 1);
	Inverse(arr, arr + len - 1);
}

int main()
{
	char arr[] = "ABCDEF";
	int len = strlen(arr);
	int k =3;
	rotate(arr,k%len, len);
	puts(arr);
	return 0;
}
#endif

//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int lor_rotate(char* str, char* src)
{
	int len = strlen(str);
	int ret = 0;
	char* double_str = (char*)malloc(sizeof(char)* (2 * len + 1));
	strcpy(double_str, str);
	strcat(double_str, str);
	if (strstr(double_str, src) == NULL)
	{
		ret = 0;
	}
	else
	{
		ret = 1;
	}
	free(double_str);
	return ret;
}

int main()
{
	char s1[] = "abcd";
	char s2[] = "ACBD";
	printf("%d",lor_rotate(s1,s2));
	return 0;
}