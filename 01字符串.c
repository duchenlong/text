#include<stdio.h>

int arr[5]={0};

void dfs(int index)
{
	if(index==5)
	{
		int j=0;
		for(j=0;j<5;j++)
		{
			printf("%d",arr[j]);
		}
		printf("\n");
		return ;
	}
	int i=0;
	for(i=0;i<2;i++)
	{
		arr[index]=i;
		dfs(index+1);
	}
}

int main()
{
	dfs(0);
	return 0;
}
