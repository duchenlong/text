#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	scanf("%d",&n);
	int* a=(int*)malloc(sizeof(int));
	int* b=(int*)malloc(sizeof(int));
	int i=0;
	int num=0;
	int j=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=0)
		{
			num++;
			b[j]=a[i];
			j++;
		}
	}
	printf("%d\n",num);
	for(i=0;i<j;i++)
	{
		printf("%d ",b[i]);
	}
	return 0;
}
