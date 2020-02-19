#include <stdio.h>

int int_cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}

int main()
{
	int n,b;
	scanf("%d%d",&n,&b);//n 数组元素个数 b 被整除的数
	int num = 0;
	int i = 0;
	int len = 0;
	int arr[500] = {0};
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&num);
		
		if(num % b == 0)
		{
			continue;
		}
		
		arr[len++] = num;
	}  
	
	qsort(arr,len,sizeof(int),int_cmp);
	
	for(i = 0; i < len; i++)
	{
		if(arr[i] >= 'A' && arr[i] <= 'Z')
		{
			printf("%c ",arr[i]);
			continue;
		}
		
		printf("%d ",arr[i]);
	}
	return 0;
}
