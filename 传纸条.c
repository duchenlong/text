#include <stdio.h>

#define max(a,b) (a>b?a:b) 

int dp[55][55][55][55] = {0};
int arr[55][55] = {0};

int main()
{
	int m,n;//学生座位有m行n列 
	scanf("%d%d",&m,&n);
	int i = 0;
	int j = 0;
	//输入同学对（1,1）（m,n)两位学生的好感度
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d",&arr[i][j]);	
		}	
	} 
	
	int i1,j1,i2,j2;
	for(i1 = 1; i1 <= m; i1++)
	{
		for(j1 = 1; j1 <= n; j1++)
		{
			for(i2 = 1; i2 <= m; i2++)
			{
				for(j2 = 1; j2 <= n; j2++)
				{
					//同方向传纸条的好感度
					int same = max(dp[i1-1][j1][i2-1][j2],dp[i1][j1-1][i2][j2-1]);
					//异方向传纸条的好感度 
					int diff = max(dp[i1][j1-1][i2-1][j2],dp[i1-1][j1][i2][j2-1]);
					
					dp[i1][j1][i2][j2] = max(same,diff) + arr[i1][j1];
					
					//判断是否两次走在了同一位置
					if(i1!=i2 && j1!=j2)
					{
						dp[i1][j1][i2][j2] += arr[i2][j2];
					} 
					//printf("%d\n",dp[i1][j1][i2][j2]);
				}
			}
		}
	}
	
	printf("%d\n",dp[m][n][m][n]);
	return 0;
}
