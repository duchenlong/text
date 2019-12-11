#include<stdio.h>
#include<string.h>

void swap(char* arr, int i, int j)
{
	char tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

int main()
{
	char arr[10000] = { '\0' };
	int a[30] = { 0 };
	char b = '\0';
	int n, i, j, k, len;
	int ou = 0, ji = 0, h = 0, adj = 0;
	scanf("%d", &n);
	len = n;
	scanf("%s", arr);
	for (i = 0; i < n; i++)
	{
		a[arr[i] - 'a']++;
	}
	for (i = 0; i<26; i++)
	{
		if (a[i] % 2 != 0)
		{
			b = i + 'a';
			ji++;
		}
	}
	if (ji>1)
	{
		printf("Impossible\n");
		return 0;
	}

	for (i = 0; i<n/2; i++)
	{
		if (arr[i] != arr[len - 1])
		{
			for (j = len - 1; j>i; j--)
			{
				if (arr[j] == arr[i])
				{
					break;
				}
			}
			if (j == i)
			{
				adj = n / 2 - i;
			}
			else
			{
				for (k = j; k < len - 1; k++)
				{
					swap(arr, k, k + 1);
					h++;
				}
			}
		}
		if (arr[i]==arr[len-1])
		{
			len--;
		}
	}
	printf("%d\n", h + adj);
	return 0;
}
