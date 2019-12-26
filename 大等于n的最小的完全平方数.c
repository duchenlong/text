#include<stdio.h>
#include<math.h>

int main()
{
	long long i=0;
	long long num=0;
	scanf("%lld",&num);
	if(num<0)
	{
		num=0;
	}
	
	for(i=num;i>=0;i++)
	{
		long long  count=sqrt(i);
		if(count*count==i)
		{
			printf("%lld\n",i);
			return 0;
		}
	}
	return 0;
}
