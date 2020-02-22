#include <stdio.h>
#include <math.h>

int arr[100][100] = {0};

int main()
{
	int n;
	scanf("%d",&n); 
	n = pow(2,n);
	
	int i = 0;
	int j = 0;
	int k = 0;
	for(i = 1; i < n; i++)
	{
		printf("<%d>",i);
		int visit[100] = {0};
		
		for(j = 1; j < n; j++)
		{
			if(visit[j])
			{
				continue;
			}
			visit[j] = 1;
			
			k = j + 1;
			while(k <= n)
			{
				//如果之前j 和 k以及比赛过，则跳过k 
				if(arr[j][k] || visit[k])
				{
					k++;
					continue;
				}
				
				break;
			}
			
			visit[k] = 1;
			arr[j][k] = 1;
			printf("%d-%d ",j,k);
		}
		
		printf("\n");
	}
	
	return 0;
}
