#include <stdio.h>
#include <string.h>

#define MAX 100000

int arr[MAX] = {0};
int hash[MAX] = {0};
int dp[MAX] = {0}; //表示该位置前面不大于他的所有元素数目 

int slove(num)
{
	int i = 0;
	int max = -1;
	int j = 0;
	
	for(i = 0; i < num; i++)
	{
		dp[i] = 1;//不大于他的元素包括他自身 
		for(j = 0; j < i; j++)
		{
			if(hash[arr[j]] <= hash[arr[i]] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1; 
			}
		}
		
		max = max > dp[i] ? max : dp[i];
	}
	
	return max;
}

int main()
{
	int n; //最大序号
	int m; //合理的序号数量
	
	scanf("%d%d",&n,&m);
	memset(hash,-1,sizeof(hash));
	
	int i = 0;
	int num = 0;
	for(i = 0; i < m; i++)
	{
		scanf("%d",&num);
		hash[num] = i;
	}
	
	int L;
	scanf("%d",&L); //所求序列的大小
	int j = 0;
	for(i = 0; i < L; i++)
	{
		scanf("%d",&num);
		if(hash[num] != -1)
		{
			arr[j++] = num;
		}
	}
	
	printf("%d\n",slove(j));
	return 0;	
} 
