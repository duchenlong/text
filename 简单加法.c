#include <stdio.h>

int len(int num)
{
	if(num < 10)
	{
		return 1;
	}
	return 1 + num / 10;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int i = 0;
	int ans = 0;
	for(i = 0; i <= n; i++)
	{
		int num = len(i);
		
		int count = 3 * i + 2;
		if(num == len(count))
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
