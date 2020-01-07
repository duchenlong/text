#include<stdio.h>

char arr[100][100]={'\0'};

int main()
{
	int n=0;
	scanf("%d",&n);
	
	int i=0;
	int j=0;
	for(i=0;i<n-1;i++)
	{
		int k=i;
		for(j=0;j<k;j++)
		{
			arr[i][j]='.';
		}
		arr[i][k++]='A'+i;
		for(j=k;j<n;j++)
		{
			arr[i][j]='.';
		}
		arr[i][n-1]='A'+i;
		int m=2;
		for(j=n;j<2*n;j++)
		{
			arr[i][j]=arr[i][j-m];
			m+=2;
		}
	}
	for(i=0;i<n;i++)
	{
		arr[n-1][i]='A'+i;
	}
	int m=n;
	for(i=i-2;i>=0;i--)
	{
		arr[n-1][m++]='A'+i;
	}
	
	m=n-2;
	for(i=n;i<2*n-1;i++)
	{
		for(j=0;j<2*n-1;j++)
		{
			arr[i][j]=arr[m][j];
		}
		m--;
	}
	for(i=0;i<2*n-1;i++)
	{
		for(j=0;j<2*n-1;j++)
		{
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
