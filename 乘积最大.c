#include<stdio.h>
#include<stdlib.h>

long long dp[50][50]={0};
char str[50]={0};
int a[50]={0};

long long Pro(int n,int m)
{
	int i=0;
	long long num=0;
	for(i=n;i<=m;i++)
	{
		num=num*10+a[i];
	}
	
	return num;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	
	int i=0;
	scanf("%s",str);
	
	
	for(i=0;i<n;i++)
	{
		a[i+1]=str[i]-'0';
	}
	
	for(i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0]*10+a[i];
	}
	
	int j=0,m=0;
	for(i=1;i<=k;i++)
	{
		for(j=0;j<=n;j++)
		{
			long long temp=0;
			for(m=i;m<j;m++)
			{
				temp=(temp>dp[m][i-1]*Pro(m+1,j))?temp:(dp[m][i-1]*Pro(m+1,j));
				printf("%d ",temp);
			}
			
			dp[j][i]=temp;
		}
	}
	
	printf("%d\n",dp[n][k]);
	
	
	return 0;
}
 
