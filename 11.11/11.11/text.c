#define _CRT_SECURE_NO_WARNINGS 1
//标题：日期问题
//
//小明正在整理一批历史文献。这些历史文献中出现了很多日期。小明知道这些日期都在1960年1月1日至2059年12月31日。
//令小明头疼的是，这些日期采用的格式非常不统一，
//有采用年 / 月 / 日的，
//有采用月 / 日 / 年的，
//还有采用日 / 月 / 年的。
//更加麻烦的是，年份也都省略了前两位，使得文献上的一个日期，存在很多可能的日期与其对应。
//
//比如02 / 03 / 04，可能是2002年03月04日、2004年02月03日或2004年03月02日。
//
//给出一个文献上的日期，你能帮助小明判断有哪些可能的日期对其对应吗？
//
//输入
//----
//一个日期，格式是"AA/BB/CC"。(0 <= A, B, C <= 9)
//
//输入
//----
//输出若干个不相同的日期，每个日期一行，格式是"yyyy-MM-dd"。多个日期按从早到晚排列。
//
//样例输入
//----
//02 / 03 / 04
//
//样例输出
//----
//2002 - 03 - 04
//2004 - 02 - 03
//2004 - 03 - 02
//
//资源约定：
//峰值内存消耗（含虚拟机） < 256M
//CPU消耗  < 1000ms

#include<stdio.h>
#include<string.h>

int arr[13][2] = { {0,0},{ 31, 31 }, { 28, 29 }, { 31, 31 }, { 30, 30 }, \
                       { 31, 31 }, { 30, 30 }, { 31, 31 }, { 31, 31 }, \
                       { 30, 30 }, { 31, 31 }, { 30, 30 }, { 31, 31 } };
int a[3] = { 0 };
char b[3][15] = { '\0' };

int JudgeYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}

int JudgeMonth(int month)
{
	if (month > 12||month==0)
	{
		return 0;
	}
	return 1;
}

void judegYMD(int year, int month, int day,int j)
{
	if (JudgeMonth(month))
	{
		if (year >= 60)
		{
			year += 1900;
		}
		else
		{
			year += 2000;
		}
		int i = JudgeYear(year);
		if (day > arr[i][month])
		{
			return;
		}
		int k = 3;
		while (year)
		{
			b[j][k] = (year % 10) + '0';
			k--;
			year /= 10;
		}
		b[j][4] = '-';
		if (month < 10)
		{
			b[j][5] = '0';
			b[j][6] = month + '0';
		}
		else
		{
			k = 6;
			while (month)
			{
				b[j][k] = (month % 10) + '0';
				k--;
			}
		}
		b[j][7] = '-';
		if (day < 10)
		{
			b[j][8] = '0';
			b[j][9] = day + '0';
		}
		else
		{
			k = 9;
			while (day)
			{
				b[j][k] = (month % 10) + '0';
				k--;
			}
		}
	}
	return;
}

int main()
{
	int i = 0,k=0,j=0;
	scanf("%d/%d/%d", &a[0], &a[1], &a[2]);
	judegYMD(a[0],a[1],a[2],0);
	judegYMD(a[2], a[0], a[1],1);
	judegYMD(a[2], a[1], a[0],2);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3 - i - 1; j++)
		{
			if (strcmp(b[j], b[j+1]) == 1)
			{
				char* src='\0';
				strcpy(src, b[j]);
				strcpy(b[j], b[i]);
				strcpy(b[i], src);
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (b[i][0] != '0')
		{
			puts(b[i]);
		}
	}
	return 0;
}