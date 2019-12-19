#include<stdio.h>

int ans=0;

int f(int N)
{
	if(N==1)
	{
		return 1;
	}
	else if(N==2) 
	{
		return 2;
	}
	
	return f(N-1)+f(N-2);
 } 

int main()
{
	int N;
	scanf("%d",&N);
	
	ans=f(N);
	
	printf("%d\n",ans);
	return 0;
}
