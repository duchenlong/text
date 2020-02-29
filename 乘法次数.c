#include <stdio.h>

int fun(int n)
{
	if(n == 1)
		return 0;
		
	if(n % 2 == 0)
		return 1 + fun(n/2);
	
	return 1 + fun(n-1);
}

int main()
{
	int m;
	scanf("%d",&m);
	int arr[200] = {0};
	int len = 0;
	int n;
	while(m--)
	{
		scanf("%d",&n);
		
		arr[len++] = fun(n); 
	} 
	
	int i = 0;
	for(i = 0; i < len; i++)
	{
		printf("%d\n",arr[i]);
	}
	return 0;
} 
