#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
#include<stdio.h>
#include<string.h>

void rotate(char* arr,const int k,const int len)
{
	int i = 0;
	int n = k;
	for (i = 0; i <len-k; i++)
	{
		int tmp = arr[i];
		arr[i] = arr[n];
		arr[n] = tmp;
		n++;
	}
	for (i = 0; i <k-1; i++)
	{
		int tmp = arr[i+len-k];
		arr[i + len - k] = arr[len - 1];
		arr[len - 1] = tmp;
	}
}

int main()
{
	char arr[] = "ABCDE";
	int len = strlen(arr);
	int k =2;
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
#include<string.h>

void rotate(char* arr, const int k, const int len)
{
	int i = 0;
	int n = k;
	for (i = 0; i <len - k; i++)
	{
		int tmp = arr[i];
		arr[i] = arr[n];
		arr[n] = tmp;
		n++;
	}
	for (i = 0; i <k - 1; i++)
	{
		int tmp = arr[i + len - k];
		arr[i + len - k] = arr[len - 1];
		arr[len - 1] = tmp;
	}
}

int main()
{
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	/*char s1[] = "abcd";
	char s2[] = "ACBD";*/
	int k = 0;
	int len = strlen(s1);
	printf("����Ϊ��������Ϊ��\n");
	scanf("%d", &k);
	if (k > 0)
	{
		rotate(s1, k%len, len);
	}
	else
	{
		rotate(s1, (-len)%k+len, len);
	}
	printf("%d\n", strcmp(s1, s2)==0?1:0);
	return 0;
}