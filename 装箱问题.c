#include <stdio.h>

#define max(a,b) a>b?a:b

int dp[20005] = {0};
int arr[50] = {0};

int main()
{
	int V;//箱子容量 
	scanf("%d",&V);
	int n;//n个物品
	scanf("%d",&n);
	
	int i = 0;
	int j = 0;
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);	
	} 
	
	for(i = 0; i < n; i++)//依次放入n个物体 
	{
		for(j = V; j >= arr[i]; j--)//判断该质量的物体 ，是否可以放入箱子 
		{
			//如果放入这个物体
			//dp[j - arr[i]] j质量下除了该物体，还可以放入的最大质量 
			dp[j] = max(dp[j],dp[j - arr[i]] + arr[i]);
		}
	}
//	for(i = 0; i <= V; i++)
//	{
//		printf("%d ",dp[i]);
//	}
	printf("%d\n",V - dp[V]);
	return 0;
}
