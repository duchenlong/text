#include <stdio.h>

#define MAX 100000

int arr[MAX] = {0}; //存放子序列
int dp[MAX] = {0};//表示arr[i]以前的最大值 
int s[MAX] = {0}; //表示arr[i]以前的最大连续子序列的起始位置

int main()
{
	int n = 0;
	scanf("%d",&n);
	
	int i = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	if(n == 1)
	{
		printf("%d 0 0\n",arr[0]);
	}
	else
	{
		dp[0] = arr[0];
		for(i = 1; i < n; i++)
		{
			if(dp[i - 1] + arr[i] > arr[i])
			{
				dp[i] = dp[i - 1] + arr[i];
				s[i] = s[i - 1];
			}
			else
			{
				dp[i] = arr[i];
				s[i] = i;
			}
		}
		int max = 0;
		for(i = 1; i < n; i++)
		{
			if(dp[max] < dp[i])
			{
				max = i;
			}
		}
		
		printf("%d %d %d",dp[max], s[max], max);
	}
	
	return 0;	
} 
