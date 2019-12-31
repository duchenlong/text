#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int col[9]={0};
int arr[9][2]={0};
int visit[9][9]={0};
int ans=0;

void slove()
{
	int i=0;
	int j=0;
	for(i=1;i<9;i++)
	{
		for(j=i+1;j<9;j++)
		{
			if(abs(arr[j][0]-arr[i][0])==abs(arr[j][1]-arr[i][1]))
			{
				return ;
			}
		}
	}
	ans++;
	printf("-->%d\n",ans);
	for(i=1;i<9;i++)
	{
		for(j=1;j<9;j++)
		{
			printf("%d ",visit[i][j]);
		}
		printf("\n");
	}
}

void dfs(int index)
{
	if(index==9)
	{
		ans++;
		return ;
	}
	
	int i=0;
	for(i=1;i<9;i++)
	{
		int flag=1;
		if(!col[i])
		{
			
			
			int j=0;
			for(j=1;j<index;j++)
			{
				if(abs(arr[j][0]-index)==abs(arr[j][1]-i))
				{
					flag=0;
					
					break;
				}
			}
			
			if(flag)
			{
				arr[index][0]=index;
				arr[index][1]=i;
				col[i]=1;
				dfs(index+1);
				col[i]=0;
			}
		}
	}
}

//void dfs(int index)
//{
//	if(index==9)
//	{
//		slove();
//		return ;
//	}
//	
//	int i=0;
//	for(i=1;i<9;i++)
//	{
//		if(!col[i])
//		{
//			col[i]=1;
//			
//			arr[index][0]=index;
//			arr[index][1]=i;
//			visit[index][i]=1;
//			dfs(index+1);
//			visit[index][i]=0;
//			col[i]=0;
//		}
//	}
//		
//}

int main()
{
	dfs(1);
	
	printf("%d\n",ans);
	return 0;
}
