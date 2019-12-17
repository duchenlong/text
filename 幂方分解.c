#include<stdio.h>

void f(int num)
{
	if(num==0)
	{
		printf("2(0)");
		return ;
	}
	if(num==1)
	{
		printf("2");
		return ;
	}
	printf("2(");
	
	int i=0;
	int a[32]={0};
	while(num)
	{
		a[i++]=num&1;
		num=num>>1;
	}
	int k=0;
	int j=0;
	for(j=0;j<i;j++)
	{
		if(a[j])
		{
			k=j;
			break;
		}
	}
	for(j=i-1;j>=k;j--)
	{
		if(a[j])
		{
			f(j);
			if(j!=k)
			{
				printf("+");
			}
		}
	}
	
	printf(")");
}

int main()
{
	int num;
	scanf("%d",&num);
	
	
	int i=0;
	int a[32]={0};
	while(num)
	{
		a[i++]=num&1;
		num=num>>1;
	}
	int k=0;
	int j=0;
	for(j=0;j<i;j++)
	{
		if(a[j])
		{
			k=j;
			break;
		}
	}
	for(j=i-1;j>=k;j--)
	{
		if(a[j])
		{
			f(j);
			if(j!=k)
			{
				printf("+");
			}
		}
	}
	
	return 0;
}
