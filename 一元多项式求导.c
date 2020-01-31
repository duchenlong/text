#include <stdio.h>

int arr[1000] = {0};

int main()
{
	int n;
	scanf("%d",&n);
	
	int i = 0;
	int k,e; //k为系数 e为指数 
	int max = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d %d",&k,&e);
		arr[e] = k;
		if(e > max)
		{
			max = e;
		}
	} 
	if(max == 0)
	{
		printf("0 0\n");
		return 0;
	}
	
	arr[0] = 0;
	int count = 0;//记录求导后非零项的数量 
	for(i = 1; i <= max; i++)
	{
		
		arr[i - 1] = arr[i] * i;
		arr[i] = 0;
		if(arr[i - 1] != 0)
		{
			count++;
		}
	}
	printf("%d ",count); 
	for(i = max - 1; i >= 0; i--)
	{
		if(arr[i] != 0)
		{
			printf("%d %d",arr[i],i);
		}
		count--;
		if(count >= 0)
		{
			printf(" "); 
		}
		else
		{
			break;
		}
	}
	
	
	return 0;
} 
