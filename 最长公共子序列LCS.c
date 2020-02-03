#include <stdio.h>
#include <string.h>

#define MAX_1 210
#define MAX_2 100000
#define max(a,b) a>b?a:b

int a[MAX_1] = {0};
int b[MAX_2] = {0};
int dp[MAX_1][MAX_2] = {0};

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int i = 0;
	for(i = 1; i <= m; i++)
	{
		scanf("%d",&a[i]);
	}
	
	int L;
	scanf("%d",&L);
	for(i = 1; i <= L; i++)
	{
		scanf("%d",&b[i]);
	}
	
	int j = 0;
	for(i = 0; i <= m; i++)
	{
		dp[i][0] = 0;
	}
	
	for(i = 0; i <= L; i++)
	{
		dp[0][i] = 0;
	} 
	
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= L; j++)
		{
			int max = max(dp[i - 1][j],dp[i][j - 1]);
			dp[i][j] = max;
			if(a[i] == b[j])
			{
				dp[i][j]++;
			}
		}
	}
	
	printf("%d\n",dp[m][L]);
	return 0;
}
