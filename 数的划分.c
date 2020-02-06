#include <stdio.h>

int num = 0;
int arr[10] = {1,0};

//int dfs(int deq,int n,int k)
//{
//	if(k == 0)
//	{
//		if(n == 0)
//		{
//			int i;
////			for(i=0;i<3;i++)
////			{
////				printf("%d ",arr[i]);
////			}
////			printf("\n");
//			return 1;
//		}
//		return 0;
//	}
//	int i = 0;
//	int ans = 0;
//	
//	for(i = arr[deq - 1]; i <= n; i++)
//	{
//		//num -= i;
//		arr[deq] = i;
//		ans += slove(deq+1,n - i, k - 1);
//		//num += i;
//	}
//	return ans;
//}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int dp[300][10] = {1,0};
	//µİ¹é 
	//printf("%d",dfs(1,n,k));
	//¶¯Ì¬¹æ»®
	int i = 0;
	int j = 0;
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= k && j <= i; j++)	
		{
			dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
		}
	}
	printf("%d",dp[n][k]);
	return 0;
}
