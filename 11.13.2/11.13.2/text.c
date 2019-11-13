#define _CRT_SECURE_NO_WARNINGS 1
//标题： Excel地址
//
//Excel单元格的地址表示很有趣，它使用字母来表示列号。
//比如，
//A表示第1列，
//B表示第2列，
//Z表示第26列，
//AA表示第27列，
//AB表示第28列，
//BA表示第53列，
//....
//
//当然Excel的最大列号是有限度的，所以转换起来不难。
//如果我们想把这种表示法一般化，可以把很大的数字转换为很长的字母序列呢？
//
//本题目既是要求对输入的数字, 输出其对应的Excel地址表示方式。
//
//例如，
//输入：
//26
//则程序应该输出：
//Z
//
//再例如，
//输入：
//2054
//则程序应该输出：
//BZZ
//
//我们约定，输入的整数范围[1, 2147483647]

#include<stdio.h>

int main()
{
	int num;
	int i = 0;
	int j = 0;
	scanf("%d", &num);
	char a[10] = { '\0' };
	while (num!=0)
	{
		int tmp = num % 26;
		if (tmp == 0)
		{
			tmp = 26;
		}
		a[i]= 'A' + tmp - 1;
		i++;
		num = (num - tmp) / 26;
	}
	for (j = i-1; j >=0; j--)
	{

		printf("%c", a[j]);
	}
	return 0;
}