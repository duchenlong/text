#include <stdio.h>

int ans[20] = {0};
int arr[200][2] = {0};
void show(int n);
void swap(int a,int b)
{
	int tmp = ans[a];
	ans[a] = ans[b];
	ans[b] = tmp;
}

int int_cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}

void add(int len)
{
	int i = 0;
	int j = 0;
	int left = 0;
	int right = len-1;
	
	for(i = len - 2; i >= 0; i--)
	{
		left = i;
		int span = 20;
		int flag = 0;
		for(j = i+1; j < len; j++)
		{
			if(span > ans[j] - ans[i] && ans[j] > ans[i])
			{
				span = ans[j] - ans[i];
				right = j;
				flag = 1;
				//printf("\nspan = %d %d %d\n",span,i,j);
			}
		}
		if(flag)
		{
			break;
		}
	}
	//printf("left = %d %d\n",left,right);
	swap(right,left);
	
	if(left+1 < len)
	qsort(ans+left+1,len-left-1,sizeof(int),int_cmp);
}

//打印结果 
void show(int n)
{
	int i = 0;

	for(i = 0; i < n; i++)
	{
		printf("%d ",ans[i]);
	}
	printf("\n");
}

int Judge(int n,int len)
{
	int i = 0;
	int j = 0;
	int m = 0;
	//判断当前结果是否符合限制条件
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < len; j++)
		{
			if(ans[i] == arr[j][0] && arr[j][1] == ans[i-1])
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i = 0;
	int j = 0;
	int num = 0;
	int len = 0;
	
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d",&num);
			
			if(num == 0 && i != j)
			{
				//j-1不能出现在i-1的后面 
				arr[len][0] = j - 1;//后面 
				arr[len][1] = i - 1;//前面 
				len++; 
				//printf("%d %d\n",arr[len-1][0],arr[len-1][1]);
			}
		}
	}
	
	//初始化第一个排列
	for(i = 0; i < n; i++)
	{
		ans[i] = i;
	}
	int m = 0;
	while(k)
	{
		while(Judge(n,len))
		{
			add(n);
			//show(n);
		}
		k--;
		if(k)
		{
			add(n);
		} 
					
	}
	//add(n);
	show(n);
	
	return 0;
}
