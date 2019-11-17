#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//一个数被称为质数（或素数）是指除开1和它本身两个约数外，没有其他的约数。
//不超过10000的数中，最大的质数是多少 ?
#include<stdio.h>

int judege(int num)
{
	int i = 2;
	for (i = 2; i < num / 2; i++)
	{
		if (num%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int num = 10000;
	for (num = 10000; num > 0; num--)
	{
		if (judege(num))
		{
			printf("%d", num);
			break;
		}
	}
	return 0;
}
#endif

#if 0
//输入一个单词，请输出这个单词中第一个出现的元音字母。
//元音字母包括 a, e, i, o, u，共五个。
#include<stdio.h>

int main()
{
	char str = '\0';
	char ch='\0';
	int flag = 0;
	scanf("%c", &ch);
	while (ch>='a'&&ch<='z')
	{
		if (((ch == 'a') || (ch == 'o') || (ch == 'e') || (ch == 'i') || (ch == 'u'))&&(flag==0))
		{
			flag = 1;
			str = ch;
		}
		scanf("%c", &ch);
	}
	if (flag == 1)
	{
		printf("%c\n", str);
	}
	else
	{
		printf("n\n");
	}
	return 0;
}
#endif

//
//小明非常不喜欢数字 2，包括那些数位上包含数字 2 的数。如果一个数的数位不包含数字 2，小明将它称为洁净数。
//请问在整数 1 至 n 中，洁净数有多少个？
#include<stdio.h>

int main()
{
	int i = 0;
	int ans = 0;
	int n = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		int num = i;
		while (num)
		{
			if (num % 10 == 2)
			{
				break;
			}
			num /= 10;
		}
		if (!num)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return  0;
}