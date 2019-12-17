#include<stdio.h>

void An(int i,int n)
{
	if(i==n)
	{
		printf("sin(%d)",i);
		return ;
	}
	
	printf("sin(%d",i);
	if(i%2!=0)
	{
		printf("-");
	}
	else
	{
		printf("+");
	}
	An(i+1,n);
	printf(")");
}

void Sn(int i,int n,int j)
{
	
	if(j==n)
	{
		An(1,i);
		printf("+%d",j);
		return ;
	}
	
	printf("(");
	
	Sn(i-1,n,j+1);
	printf(")");
	An(1,i);
	printf("+%d",j);
}

int main()
{
	int n=0;
	scanf("%d",&n);
	Sn(n,n,1);
	return 0;
}
