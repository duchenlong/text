#define _CRT_SECURE_NO_WARNINGS 1
//描述：正则问题
//
//考虑一种简单的正则表达式：
//只由 x() | 组成的正则表达式。
//小明想求出这个正则表达式能接受的最长字符串的长度。
//
//例如((xx | xxx)x | (x | xx))xx 能接受的最长字符串是： xxxxxx，长度是6。
//
//输入
//----
//一个由x() | 组成的正则表达式。输入长度不超过100，保证合法。
//
//输出
//----
//这个正则表达式能接受的最长字符串的长度。
//
//例如，
//输入：
//((xx | xxx)x | (x | xx))xx
//
//程序应该输出：
//6
//
//资源约定：
//峰值内存消耗（含虚拟机） < 256M
//CPU消耗  < 1000ms

#include<stdio.h>
#include<string.h>

int len = 0;
char* str;
int visit = 0;
int num = 0;
int flag = 0;

int Fun()
{
	int i = 0;
	int ans = 0;
	while (visit<len - 1)
	{
		if (str[visit] == 'x')
		{
			++visit;
			ans++;
		}
		else if (str[visit] == '(')
		{
			flag = 1;
			++visit;
			ans += Fun();
			flag = 0;
		}
		else if (str[visit] == '|')
		{
			++visit;
			if (num<ans)
			{
				num = ans;
			}
		}
		if ((str[visit]) == ')')
		{
			++visit;
			break;
		}
	}
	if ((visit<len-1) && (flag == 0))
	{
		Fun();
	}
	return ans;
}

int main()
{
	str= "((xx|xxxx|x)|(xx))xx";
	len = strlen(str);
	Fun();
	printf("%d",num);
	return 0;
}