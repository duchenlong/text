#include <stdio.h>

int dp[200][200] = {0};
int sum = 0;
#define max(a,b) a > b ? a : b
//int max(int a,int b)
//{
//	return a > b ? a : b;
//}

int main()
{
	int n = 0;
	scanf("%d",&n);
	
	int i = 0;
	int j = 0;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			scanf("%d",&dp[i][j]);
		}
	}
	
	for(i = 2; i <= n; i++)
	{
		for(j = 1; j <= i; j++)
		{
			dp[i][j] += max(dp[i - 1][j],dp[i - 1][j - 1]);
		}
	}
	
	for(i = 1; i <= n; i++)
	{
		if(dp[n][i] > sum)
		{
			sum = dp[n][i];
		}
	}
	printf("%d\n",sum);
	return 0;
}
