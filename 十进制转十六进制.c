#include<stdio.h>

int main()
{
	int num,i=0;
	scanf("%d",&num);
	char arr[10000]={'\0'};
	if(!num)
	{
		printf("0\n");
		return 0;
	}
	while(num)
	{
		if(num%16<10)
		{
			arr[i]=num%16+'0';
		}
		else
		{
			arr[i]=num%16+'A'-10;
		}
		i++;
		num/=16;
	}
	int j=0;
	for(j=i-1;j>=0;j--)
	{
		printf("%c",arr[j]);
	}
	printf("\n");
	return 0;
}
