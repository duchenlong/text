#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

char a[25][100000] = { '\0' };
int ans = 0;
int b[25] = { 0 };
char arr[100] = { '\0' };

void DFS(int len, int n)
{
	ans = ans < len ? len : ans;

	int i = 0;
	for (i = 0; i < n; i++)
	{
		int leni = len;
		int flag = 0;
		if (b[i] < 2)
		{
			int lenc = strlen(arr);
			int j = 0;
			for (j = 0; j < lenc; j++)
			{
				if (a[i][j] != arr[j])
				{
					flag = 1;
					break;
				}
			}

			if (flag)
			{
				continue;
			}
			int lenb = strlen(a[i]);
			int lena = len;

			int k = lenb - 1;
			char brr[100] = { 0 };
			strcpy(brr, arr);
			for (; k > 0; k--)
			{
				len = lena + lenb - lenc;
				memset(arr, 0, sizeof(arr));
				int m = 0;
				int m1 = k;
				for (m = 0; m < lenb - k; m++)
				{
					arr[m] = a[i][m1++];
				}
				b[i]++;
				DFS(len, n);
				b[i]--;
			}
			memset(arr, 0, sizeof(arr));
			strcpy(arr, brr);
		}
		len = leni;
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%s", a[i]);
	}
	scanf("%s", arr);
	DFS(1, n);
	printf("%d\n", ans);
	return 0;
}