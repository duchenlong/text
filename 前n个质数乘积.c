#include <stdio.h>

int Judge(int num)
{
	if(num == 2 || num == 3)
	{
		return 1;
	}
	
	if(num % 6 != 5 && num % 6 != 1)
	{
		return 0;
	}
	
	int i = 0;
	for(i = 5; i < num / 2; i += 6)
	{
		if(num % i == 0 || num % (i + 1) == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i = 2;
	int count = 0;
	int ans = 1;
	int n;
	scanf("%d",&n);
	while(i)
	{
		if(count == n)
		{
			break;
		}
		if(Judge(i))
		{
			ans = (ans * i) % 50000;
			count++;
		}
		i++;
	}
		
	printf("%d\n",ans);
	return 0;
}
