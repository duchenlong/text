#include <stdio.h>

int Fun(int k,int n)
{
	if(k == 0 || k == n)
	{
		return 1;
	}
	return Fun(k,n - 1) + Fun(k - 1, n - 1);
}

int main()
{
	int k,n;
	scanf("%d%d",&k,&n);
	
	printf("%d\n",Fun(k,n));
	
	return 0;
}
