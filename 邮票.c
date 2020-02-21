#include <stdio.h>
#include <math.h>

int sum[100000] = {0};
int visit[10000] = {0};

int int_cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b; 
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i = 0;
	for(i = 0; i < m; i++)
	{
		scanf("%d",&sum[i]);
		visit[sum[i]] = 1;
	}
	
	//邮票面值从小到大排列 
	qsort(sum,m,sizeof(int),int_cmp);
	
	if(sum[0] != 1)
	{
		printf("0\n");
		return 0;
	}
	
	int j = 0;
	int k = 0;
	int len = m;
	for(i = 1; i < n; i++)
	{
		int span = pow(n,i);
		int count = len;
		for(j = 0; j < m; j++)
		{
			for(k = 0; k < count; k++)
			{
				int num = sum[j] + sum[k];
				if(!visit[num])
				{
					visit[num] = 1;
					sum[len++] = num;
				}
			}
		}
	}
	i = 0;
	while(visit[i+1] == 1)
	{
		i++;
	}
	
	printf("%d\n",i);
	return 0;
} 
