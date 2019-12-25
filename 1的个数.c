#include<stdio.h>

int main()
{
	int num=0;
	int i=0;
	int ans=0;
	scanf("%d",&num);
	
	for(i=1;i<=num;i++)
	{
		int n=i;
		int count=0;
		while(n)
		{
			count=n%10;
			n=n/10;
			if(count==1)
			{
				ans++;
			}
		}
	}
	
	printf("%d\n",ans);
	return 0;
}
