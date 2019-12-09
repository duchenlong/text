#include<stdio.h>

int a[200][200] = { 0 };
int b[200][200] = { 0 };

void Printf(int m, int n)
{
	int i = 0;
	int j = 0;
	int s = 0;
	int num = 0;
	int flag = 0;
	for (num = 0; num < n*m; num++)
	{
		printf("%d ", a[i][j]);
		b[i][j] = 1;
		if (s % 4 == 0)
		{
			i++;
		}
		else if (s % 4 == 1)
		{
			j++;
		}
		else if (s % 4 == 2)
		{
			i--;
		}
		else if (s % 4 == 3)
		{
			j--;
		}


		if (b[i][j] == 1)
		{
			if (b[i + 1][j + 1] == 0&&s%4==3)
			{
				s++;
				i++;
				j++;
			}
			else if (b[i-1][j+1] == 0&&s%4==0)
			{
				s++;
				i--;
				j++;
			}
			else if (b[i - 1][j - 1] == 0&&s%4==1)
			{
				s++;
				i--;
				j--;
			}
			else if (b[i+1][j-1]==0&&s%4==2)
			{
				s++;
				j--;
				i++;
			}
		}
		if (i == m )
		{
			s++;
			i--;
			j++;
		}
		else if (j == n )
		{
			s++;
			j--;
			i--;
		}
		else if (i < 0 )
		{
			s++;
			i++;
			j--;
		}
		else if (j < 0 )
		{
			s++;
			j++;
			i--;
		}
	}
}

int main()
{
	int m, n;
	int i = 0, j = 0;
	scanf("%d%d", &m, &n);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}

	Printf(m, n);
	return 0;
}
