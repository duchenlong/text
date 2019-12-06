#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

int  str[10][3500] = { '\0' };

int main()
{
	int a[10] = { 0 };
	int n, num = 0;
	char src[100005] = { '\0' };
	int i = 0, len=0, k = 0, j,m=0;
	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		k = 0;
		m = 0;
		memset(src, '\0', sizeof(src));
		gets(src);
		len = strlen(src);
		if (len%3 == 1)
		{
			if (src[0] >= 'A')
			{
				num = src[0] - 'A' + 10;
			}
			else
			{
				num = src[0] - '0';
			}
			str[i][k++] = num;
			len -= 1;
			m = m + 1;
		}
		else if (len%3 == 2)
		{
			if (src[1] >= 'A')
			{
				num = src[1] - 'A' + 10;
			}
			else
			{
				num = src[1] - '0';
			}
			if (src[0] >= 'A')
			{
				num += (src[0] - 'A' + 10) * 16;
			}
			else
			{
				num += (src[0] - '0') * 16;
			}
			str[i][k++] = num;
			len -= 2;
			m = m + 2;
		}
		while (len-3>=0)
		{
			num = 0;
			for (j = 2; j >=0; j--)
			{
				if (src[m] >= 'A')
				{
					num = (num + src[m] - 'A' + 10) * 16;
				}
				else
				{
					num = (num + src[m] - '0') * 16;
				}
				m++;
			}
			len -= 3;
			num =num/16;
			str[i][k++] = num;
		}
		a[i] = k;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <a[i]; j++)
		{
			printf("%o", str[i][j]);
		}
		printf("\n");
	}
	return 0;
}