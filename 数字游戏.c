#include <stdio.h>

int arr[20][20] = {0};
int visit[20] = {0};
int ans = 0;

void slove(int n,int sum)
{
	int i = 0;
	int j = 0;
//	for(i = 0;i < n; i++)
//	{
//		printf("%d ",arr[0][i]);
//	}
//	printf("\n");
	for(i = 1; i < n; i++)
	{
		int flag = 0;
		for(j = 0; j < n-i; j++)
		{
			arr[i][j] = arr[i-1][j] + arr[i-1][j+1];
			if(arr[i][j] > sum)
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			break;
		}
	}
	
	if(arr[n-1][0] == sum)
	{
		for(i = 0;i < n; i++)
		{
			printf("%d ",arr[0][i]);
		}
		ans = 1;
	}
}

void dfs(int index,int n,int sum)
{
	if(ans)
	{
		return ;
	}
	
	if(index == n)
	{
		slove(n,sum);
		return ; 
	}
	
	int i = 0;
	for(i = 0; i < n; i++)
	{
		if(!visit[i])
		{
			visit[i] = 1;
			arr[0][index] = i+1;
			dfs(index+1,n,sum);
			visit[i] = 0;
		}
	}
}

int main()
{
	int n,sum;
	scanf("%d%d",&n,&sum);
	
	dfs(0,n,sum);
	
//	int i = 0;
//	for(i = 0;i < n; i++)
//	{
//		printf("%d ",arr[0][i]);
//	}
	return 0;
} 
