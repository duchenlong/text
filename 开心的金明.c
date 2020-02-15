#include <stdio.h>

#define max(a,b) a>b?a:b

int dp[30005] = {0};

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int arr[100][2] = {0}; //arr[i][0] 表示物品价格 arr[1]表示物品优先级 
	int i = 0;
	int value,weight;
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d",&value,&weight);
		if(value > n)
		{
			i--;
			m--;
			continue;	
		}
		arr[i][0] = value;
		arr[i][1] = weight;
	}
	
	int j = 0;
	for(i = 1; i <= m; i++)
	{
		for(j = n; j >= 1; j--)
		{
			if(j < arr[i][0])
			{
				break;
			}
			value = dp[j - arr[i][0]] + arr[i][0] * arr[i][1];
			dp[j] = max(dp[j],value);
		}
	}
	
	printf("%d ",dp[n]);
	return 0;
}
