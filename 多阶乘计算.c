#include <stdio.h>

long long slove(n,k)
{
	int mul = n;
	long long num = 1;
	int i = 1;
	while(mul > 0)
	{
		num *= mul;
		mul = n - i * k;
		i++;
	}
	return num;
}

int add(long long num)
{
	int ans = 0;
	while(num)
	{
		ans += num % 10;
		num /= 10;
	}
	
	return ans;
}

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int m;
	scanf("%d",&m);
	
	int i = 0;
	long long ans = 0;
	for(i = 1; i <= k; i++)
	{
		long long num = slove(n,i);
		ans += num;
	}
	
	if(m == 1)
		printf("%lld\n",ans);
	else
		printf("%d\n",add(ans));
	return 0;
} 
