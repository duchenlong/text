#include<stdio.h>

int judge(int num)
{
	if(num==1)
	{
		return 0;
	}
	if(num==2||num==3)
	{
		return 1;
	}
	if(num%6!=5&&num%6!=1)
	{
		return 0;
	}
	int i=0;
	for(i=5;i<num/2;i+=6)
	{
		if((num%i==0)||(num%(i+2)==0))
		{
			return 0;
		}
	}
	return 1;
}

void fenjie(int num)
{
	int i=0;
	while(num!=1)
	{
		for(i=2;i<=num;i++)
		{
			if(num%i==0)
			{
				if(judge(i))
				{
					printf("%d",i);
					num/=i;
					if(num!=1)
					{
						printf("*");
					}
					break;
				}
			}
			
		}
	}
	printf("\n");
}

int main()
{
	int a,b;
	int i;
	scanf("%d %d",&a,&b);
	for(i=a;i<=b;i++)
	{
		printf("%d=",i);
		fenjie(i);
	}
	return 0;
}
