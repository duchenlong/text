#include<stdio.h>

int a[105][1005]={0};

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int i=0,row=0,col=0;
	int j=0;
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&row,&col);
		
		a[row-1][i]=1;
		a[col-1][i]=-1;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
} 
