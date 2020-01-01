#include<stdio.h>

int a,b;

int f(int m,int n)
{
	if(n > m)
	{
		return 0;
	}
	
	if(m==a || n==b)
	{
		return 1;
	}
	return f(m+1,n)+f(m,n+1);
}

int main()
{
	int m,n;
	scanf("%d%d",&a,&b);
	
	if(b > a)
	{
		printf("0\n");
		return 0;
	}
	
	printf("%d\n",f(0,0));
	
	return 0;
}
