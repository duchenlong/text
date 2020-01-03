#include<stdio.h>

int main()
{
	long long num;
	scanf("%lld",&num);
	long long ans=1;
	long long i=0;
	for(i=1;i<=num;i++)
	{
		ans*=i;
		long long count=ans;
		while(count)
		{
			if(count % 10 !=0)
			{
				ans=count%10000000;
				break;
			}
			
			count /= 10;
		}
	}
	
	printf("%lld\n",ans%10);
	return 0;
}
