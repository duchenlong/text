#include <stdio.h>

int arr[1005] = {0};
int brr[1005] = {0};
long long ans[1005] = {0};

int int_cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}

long long Slove(int n)
{
	long long num = 0;
	int lefta = 0,leftb = 0;
	int righta = n-1,rightb = n-1;
	while(n--)
	{
		if(arr[righta] > brr[rightb])
		{
			num += arr[righta--] * brr[leftb++];
		}
		else
		{
			num += arr[lefta++] * brr[rightb--];
		}
	}
	return num;
}

int main()
{
	int T;
	scanf("%d",&T);
	int count = 0;
	while(T--)
	{
		int n;
		scanf("%d",&n);
		
		int i = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%d",&arr[i]);
		}
		qsort(arr,n,sizeof(int),int_cmp);
		for(i = 0; i < n; i++)
		{
			scanf("%d",&brr[i]);
		}
		qsort(brr,n,sizeof(int),int_cmp);
		
		ans[count++] = Slove(n);
	}
	
	int i = 0;
	for(i = 0; i < count; i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
