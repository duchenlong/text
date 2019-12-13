#include<stdio.h>

int a[1005]={0};
int b[1005]={0};
int c[1005]={0};

void swap(int* arr,int i,int j)
{
	int tmp=arr[i];
	arr[i]=arr[j];
	arr[j]=tmp;
}

void my_sort(int* a,int len)
{
	int i=0,j=0;
	for(i=0;i<len;i++)
	{
		for(j=0;j<len-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a,j,j+1);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int m=0,num=0;
	scanf("%d",&m);
	
	while(m)
	{
		int l,r,k;
		int j=0;
		scanf("%d%d%d",&l,&r,&k);
		for(i=l-1;i<r;i++)
		{
			b[j]=a[i];
			j++;
		}
		
		my_sort(b,j);
		
		c[num]=b[k-1];
		num++;
		m--;
	}
	
	for(i=0;i<num;i++)
	{
		printf("%d\n",c[i]);
	}
	
	return 0;
}
