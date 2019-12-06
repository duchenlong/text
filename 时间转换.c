#include<stdio.h>

int main()
{
	int time;
	scanf("%d",&time);
	int a=time/3600;
	int c=time%60;
	int b=(time-a*3600-c)/60;
	printf("%d:%d:%d\n",a,b,c);
	return 0;
}
