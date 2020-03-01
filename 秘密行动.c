#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b) ((a)<(b)?(a):(b))

int dp[10005][2] = {0};

int main()
{
	int  n;//楼层高度
	scanf("%d",&n);
	
	int* arr = (int*)malloc(sizeof(int) * (n+1)); 
	int i = 0;
	for(i = 1; i <= n; i++)
	{
		scanf("%d",&arr[i]);
	}
	dp[1][0] = arr[0];
	dp[1][1] = dp[2][0] = dp[2][1] = 0;
	
	for(i = 2; i <= n; i++)
	{
		//走上这一层台阶 
		dp[i][0] = MIN(dp[i-1][0]+arr[i],dp[i-1][1]+arr[i]);
	
		//跳上这一层台阶 
		dp[i][1] = MIN(dp[i-1][0],dp[i-2][0]); 
	}
	
	int min = MIN(dp[n][0],dp[n][1]);
	printf("%d\n",min);
	return 0;
}
