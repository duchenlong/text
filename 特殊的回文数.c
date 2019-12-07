#include<stdio.h>

int main()
{
	int i;
	int n,num,sum=0;
	int a[10]={0};
	scanf("%d",&n);
	for(i=10000;i<1000000;i++)
	{
		num=i;
		sum=0;
		if(i<100000)
		{
			int j=4;
			while(num)
			{
				a[j]=num%10;
				sum+=a[j];
				j--;
				num/=10;
			}
			if(a[0]==a[4]&&a[1]==a[3])
			{
				if(sum==n)
				{
					printf("%d\n",i);
				}
			}
		}
		else
		{
			int j=5;
			while(num)
			{
				a[j]=num%10;
				sum+=a[j];
				j--;
				num/=10;
			}
			if(a[0]==a[5]&&a[1]==a[4]&&a[2]==a[3])
			{
				if(sum==n)
				{
					printf("%d\n",i);
				}
			}
		}
	}
	return 0;
}
