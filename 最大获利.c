#include<stdio.h>
#include<string.h>

int a[200][200],b[200][200],c[200][200];

void add(char* arr,long long num)
{
	char src[50] = {'\0'};
	int len = 0;
	while(num)
	{
		src[len++] = num % 10 + '0';
		num /= 10;
	}
	int count = 0;
	int i = 0;
	for(i = 0; i < len; i++)
	{
		if(arr[i] == '\0')
		{
			count += src[i] - '0';
		}
		else
		{
			count += src[i] - '0' + arr[i] - '0';
		}
		arr[i] = count % 10 + '0';
		count = count / 10;
	}
	
	while(count)
	{
		if(arr[i] == '\0')
		{
			count += arr[i];
		}
		else
		{
			count += arr[i] - '0';
		}
		arr[i] = count % 10 + '0';
		count = count / 10;
		i++;
	}
}

int main()
{
	int n,m;
	scanf("%d%d\n",&n,&m);
	
	int i = 0;
	
	int j = 0;
	
	for(i = 0; i< n;i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i = 0; i< n;i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	for(i = 0; i< n;i++)
	{
		for(j = 0; j < m; j++)
		{
			scanf("%d",&c[i][j]);
		}
	}
	
	long long num = 0;
	long long count = 0;
	char ans[50] = {'\0'};
	for(i = 0; i < n;i++)
	{
		num = 0;
		for(j = 0; j < m; j++)
		{
			if(a[i][j] < b[i][j])
			{
				count = a[i][j] * c[i][j];
			}
			else
			{
				count = b[i][j] * c[i][j];
			}
			
			if(count > num)
			{
				num = count;
			}
		}
		add(ans,num);
	}
	
	int len = strlen(ans);
	for(i = len-1;i>=0;i--)
	{
		printf("%c",ans[i]);
	}
	return 0;
}
