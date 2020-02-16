#include <stdio.h>
#include <math.h>

unsigned int arr[1005] = {0};

unsigned int my_pow(unsigned int k,int i)
{
	int j = 0;
	unsigned int num = 1;
	for(j = 1; j <= i; j++)
	{
		num *= k;
	}
	return num;
}

int main()
{
	int k;
	int n;
	scanf("%d%d",&k,&n);
	
	int i = 0;//幂
	int j = 0;//数组下标 
	while(1)
	{
		int count = j; // 记录当前下标
		unsigned int num = my_pow(k,i); 
		//printf("%d\n",num);
		arr[j++] = num;
		int m = 0;
		for(m = 0; m < count; m++)
		{
			arr[j++] = num + arr[m];
			if(j == n)
			{
				printf("%d\n",arr[j-1]);
				return 0;
			}
		}
		i++;
	}
	return 0;
}
