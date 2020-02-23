#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num;//木棍数量
int arr[100] = {0};//每一根木棍的长度
int visit[100] = {0};//判断木棍有没有被访问
int ans[10000] = {0}; //每一组木棍的最小组合长度
int len = 0; // ans数组的长度 
int max = 0; // 可能最多组成该长度的木棍数 

int int_cmp(const void* a,const void* b)
{
	return *(int*)b - *(int*)a;
}

//now 现在组合的木棍长度，size 需要拼成木块的长度
//res 已经拼成size 的木块数量 
int dfs(int now,int res,int cur,int size)
{
	if(res == max)
	{
		return 1;
	}
	//printf("%d\n",now);
	int i = 0;
	for(i = cur; i < num; i++)
	{
		if(visit[i] || (i && arr[i] == arr[i-1]  && !visit[i-1]))
		{
			continue;
		}
		
		if(now + arr[i] == size)
		{
			visit[i] = 1;
			if(dfs(0,res+1,0,size))
			{
				return 1;
			}
			visit[i] = 0;
			return 0;
		}
		else if(now + arr[i] < size)
		{
			visit[i] = 1;
			if(dfs(now+arr[i],res,i+1,size))
			{
				return 1;
			}
			visit[i] = 0;
			
			if(!now)
			{
				return 0;
			}
		}
	}
	return 0;
}

int main()
{
	
	scanf("%d",&num);
	int i = 0;
	while(num)
	{
		int sum = 0;
		for(i = 0; i < num; i++)
		{
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		
		//输入木棍从大到小排列 
		qsort(arr,num,sizeof(int),int_cmp);
		
//		for(i = 0; i< num; i++)
//		{
//			printf("%d ",arr[i]);
//		}
		
		int flag = 0;
		
		for(i = arr[0]; i <= sum/2; i++)
		{
			if(sum % i == 0)
			{
				memset(visit,0,sizeof(visit));
				max = sum / i; // 可能最多组成该长度的木棍数 
				//深搜
				if(dfs(0,0,0,i))
				{
					ans[len++] = i;
					flag = 1;
					break;
				}
			}
		}
		
		if(!flag)
		{
			ans[len++] = sum;
		}
		
		scanf("%d",&num); 
	} 
	
	for(i = 0; i < len; i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
