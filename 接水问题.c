#include <stdio.h>

int arr[10005] = {0};
int water[105] = {0};
int ans = 0;

int find_max(int count)
{
	int i = 0;
	int max = 0;
	for(i = 0; i < count; i++)
	{
		if(water[i] > max)
		{
			max = water[i];
		}
	}
	//printf("\n %d - %d \n",count,max);
	return max;
}

int find_min(int m)
{
	int i = 0;
	int min = 0;
	for(i = 1; i < m; i++)
	{
		if(water[i] < water[min])
		{
			min = i;
		}
	}
	return min;
}

void slove(int n,int m)
{
	int i = 0;
	int next = 0;//下一个学生编号
	 
	while(1)
	{   		
		//安排学生去水龙头前 
		for(i = 0; i < m; i++)
		{
			if(next == n)
			{
				break;
			}
			
			if(!water[i])
			{
				//printf(" %d ",next);
				water[i] = arr[next++];
			}
		}
//		for(i = 0; i < m; i++)
//		{
//			printf("%d ",water[i]);
//		}
		if(next == n)
		{
			ans += find_max(m);
			return ;
		}
		
		
		int min = find_min(m); // 找到当前接水最少的学生水龙头编号
		for(i = 0; i < m; i++)
		{
			if(i != min)
			water[i] -= water[min];	
		}
		ans += water[min];
		water[min] = 0;
//		printf("\n%d %d %d -- %d\n",min,water[min],next,ans);
//		for(i = 0; i < m; i++)
//		{
//			printf("%d ",water[i]);
//		}
//		printf("\n");
	}
}

int main()
{
	int n,m;//有n个学生 m个水龙头
	scanf("%d%d",&n,&m);
	
	 int i = 0;
	 for(i = 0; i < n; i++)
	 {
	 	scanf("%d",&arr[i]);
	 }
	 
	 
	 slove(n,m);
	printf("%d\n",ans);
	return 0;
} 
