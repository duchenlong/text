#include <stdio.h>

long long max(long long a,long long b) 
{
	return a > b ? a : b;
}

long long dp[15][15][15][15]= {0};
int arr[15][15] = {0};
int n;

int main()
{
	scanf("%d",&n);
	
	int row,col,weight;
	scanf("%d%d%d",&row,&col,&weight);
	while(row && col && weight)
	{
		arr[row][col] = weight;
		scanf("%d%d%d",&row,&col,&weight);
	}
	int i1,j1,i2,j2;
	
	for(i1 = 1; i1 <= n; i1++)
	{
		for(j1 = 1; j1 <= n; j1++)
		{
			for(i2 = 1; i2 <= n; i2++)
			{
				for(j2 = 1; j2 <= n; j2++)
				{
					dp[i1][j1][i2][j2] = max(\
							max(dp[i1-1][j1][i2-1][j2],dp[i1-1][j1][i2][j2-1]),\
							max(dp[i1][j1-1][i2-1][j2],dp[i1][j1-1][i2][j2-1]));
					dp[i1][j1][i2][j2] += arr[i1][j1];
					if(i1!=i2 || j1!=j2)
					{
						dp[i1][j1][i2][j2] += arr[i2][j2];
					}
				}
			}
		}
	}
	
	printf("%lld\n",dp[n][n][n][n]);
	return 0;
}
