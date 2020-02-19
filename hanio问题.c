#include <stdio.h>

int slove(int n)
{
	if(n == 1)
	{
		return 1;
	}
	
	return 1 + 2 * slove(n-1);
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(n % m == 0)
	{
		n /= m;
	}
	else
	{
		n /= m;
		n++;
	}
	
	printf("%d",slove(n));
	
	return 0;
}
