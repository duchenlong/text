#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

char arr[100] = { 0 };
char copy[100] = { 0 };
char judge[100] = { 0 };
char ans[100] = { 0 };
int len = 0;

int Slove(int j, int n)
{
	int i = j;
	int count = 0;
	for (i = j; i < len - n; i++)
	{
		strncpy(judge, arr + i, n);

		if (strncmp(copy, judge, n) == 0)
		{
			count++;
		}
	}
	return count;
}

int main()
{
	int n;
	scanf("%d", &n);


	scanf("%s", arr);
	len = strlen(arr);

	int num = 0;
	int count = 0;
	int i = 0, j = 0;
	for (i = n; i<len; i++)
	{
		for (j = 0; j <= len - i; j++)
		{
			strncpy(copy, arr + j, i);
			num = Slove(j, i);
			if (num>count)
			{
				strncpy(ans, arr + j, i);
				count = num;
			}
		}
	}

	printf("%s %d\n", ans,count);
	return 0;
}