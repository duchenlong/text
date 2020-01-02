#include<stdio.h>
#include<math.h>
#include<string.h>

int arr[9][2]={0};
int myarr[9][2]={0};
int col[9]={0};
int ans=0;
int n=0;
int visit[9][9]={0};

//void Printf()
//{
//		int i=0,j=0;
//		printf("-->%d\n",ans);
//		for(i=1;i<=n;i++)
//		{
//			for(j=1;j<=n;j++)
//			{
//				printf("%d ",visit[i][j]);
//			}
//			printf("\n");
//		}
//		return ;
//}

void dfs(int index,int num)
{
	if(num==2 && index==n+1)
	{
		ans++;
		return ;
	}
	
	if(num==1 && index==n+1)
	{
		int i=0,j=0;
		for(i=1;i<=n;i++)
		{
			myarr[i][0]=arr[i][0];
			myarr[i][1]=arr[i][1];
		}
		memset(col,0,(n+1)*sizeof(int));
		dfs(1,2);
		memset(col,1,(n+1)*sizeof(int));
		for(i=1;i<=n;i++)
		{
			arr[i][0]=myarr[i][0];
			arr[i][1]=myarr[i][1];
		}
		//Printf();
		return ;
	}
	
	int i=0;
	for(i=1;i<=n;i++)
	{
		if(visit[index][i])
		{
			if(!col[i])
			{
				int flag=1;
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
					visit[index][i]=0;
					col[i]=1;
					arr[index][0]=index;
					arr[index][1]=i;
					dfs(index+1,num);
					col[i]=0;
					visit[index][i]=1;
				}
			}
			
		}
	}
}

int main()
{
	scanf("%d",&n);
	int i=0;
	int j=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&visit[i][j]);
		}
	}
	
	dfs(1,1);
	
	printf("%d\n",ans);
	return 0;
}
