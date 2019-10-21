#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
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

//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC

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
	printf("左旋为正，右旋为负\n");
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