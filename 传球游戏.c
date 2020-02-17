#include <stdio.h>

int dp[50][50] = {0};

void show(int n,int m)
{
	int i = 0;
	int j = 0;
	for(i=0;i<=m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int n,m;//学生数量为n 传球次数为m
	scanf("%d%d",&n,&m);
	
	int i = 0;
	int j = 0;
	dp[0][0] = 1;
	for(i = 0; i <= m; i++)
	{
		for(j = 0; j < n; j++)
		{
			if(dp[i][j])
			{
				int left = (j - 1 + n) % n;
				int right = (j + 1) % n;
				//printf("%d %d\n",left,right);
				dp[i+1][left] += dp[i][j];
				dp[i+1][right] += dp[i][j];
			}
		}
//		show(n,m);
//		printf("\n");
	}
	//show();
	printf("%d\n",dp[m][0]);
	return 0;
}
