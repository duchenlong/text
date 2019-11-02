#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>


void swap(char* left,char* right)
{
	char c;
	int i = 0;
	while ((left + i)<=(right - i))
	{
		c = *(right-i);
		*(right - i) = *(left+i);
		*(left +i) = c;
		i++;
	}
}

void slove(char* a, const int len)
{
	swap(a, a + len - 1);
	char* left = a;
	char* right = a+1 ;
	int flag = 0;
	for (int i = 0; i < len-1; i++)
	{
		if (*right == ' '&&flag == 0)
		{
			flag = 1;
		}
		else if ((*right != ' ' || *right != '\0')&&flag == 1)
		{
			flag = 0;
		}
		if (flag == 1)
		{
			swap(left, right-1);
			left = right+1;
		}
		right++;
	}
}

int main()
{
	char a[100];
	gets(a);
	int len = strlen(a);
	slove(a, len);
	puts(a);
	return 0;
}