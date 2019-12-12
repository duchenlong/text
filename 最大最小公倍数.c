#include<stdio.h>
#include<string.h>
#include <stdlib.h>

char arr[100] = { '\0' };
char mul[100] = { '\0' };
char add[100] = { '\0' };
char ans[100] = { '\0' };
int b[3] = { 0 };

void  my_mul(int i)
{
	int num = 0;
	int k = 0;

	for (k = 0; k < i; k++)
	{
		add[k] = '0';
	}
	int len = strlen(arr);
	for (k = 0; k < len; k++)
	{
		num += (arr[k] - '0')*(mul[i]-'0');
		add[k+i] = num % 10+'0';
		num /= 10;
	}

	while (num)
	{
		add[k+i] = num % 10+'0';
		num /= 10;
		k++;
	}
}

void my_add()
{
	int i = 0;
	int num = 0;
	int count = 0;
	int len = strlen(add);
	for (i = 0; i < len; i++)
	{
		if (ans[i] != '\0')
		{
			num += (add[i] - '0') + (ans[i] - '0');
		}
		else
		{
			num += add[i] - '0';
		}
		ans[i] = num % 10+'0';
		num /= 10;
	}

	while (num)
	{
		ans[i++] = num % 10+'0';
		num /= 10;
	}
}

void slove(int j)
{
	int i = 0;
	for (i = 0; i < j; i++)
	{
		my_mul(i);
		if (i != 0)
		{
			my_add();
		}
		else
		{
			strcpy(ans, add);
		}
	}
	strcpy(arr, ans);
}

int main()
{
	int n;
	int i = 0;
	int len = 0;
	scanf("%d", &n);

	if (n < 3)
	{
		printf("%d\n", n);
		return 0;
	}

	if (n % 2 == 0)
	{
		if (n % 3 == 0)
		{
			b[0] = n - 1;
			b[1] = n - 2;
			b[2] = n - 3;
		}
		else
		{
			b[0] = n;
			b[1] = n - 1;
			b[2] = n - 3;
		}
	}
	else
	{
		b[0] = n;
		b[1] = n - 1;
		b[2] = n - 2;
	}

	int num = 0;
	num = b[0];
	while (num)
	{
		arr[i++] = num % 10 + '0';
		num /= 10;
	}

	for (i = 1; i < 3; i++)
	{
		(char*)memset(ans, 0, sizeof(ans));
		num = b[i];
		int j = 0;
		while (num)
		{
			mul[j++] = num % 10+'0';
			num /= 10;
		}
		slove(j);
	}

	len = strlen(arr);
	for (i = len - 1; i >= 0; i--)
	{
		printf("%c", arr[i]);
	}
}

