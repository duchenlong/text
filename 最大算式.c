#include <stdio.h>

long long max(long long a,long long b)
{
	return a > b? a : b;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	long long sum[20] = {0};
	int i = 0;
	long long dp[20][20] = {0};
	
	for(i = 1; i <= n; i++)
	{
		int num;
		scanf("%d",&num);
		sum[i] += sum[i-1] + num; 
		dp[i][0] = sum[i];
	}
	
	for(i = 2; i <= n; i++)
	{
		int j = 1;
		for(j = 1; j <= i-1 && j <= k; j++)
		{
			int l = 2;
			for(l = 2; l <= n; l++)
			{
				dp[i][j] = max(dp[i][j] , dp[l-1][j-1] * (sum[i] - sum[l-1]));
			}
		}
	}
	
	printf("%lld\n",dp[n][k]);
	return 0;
}
