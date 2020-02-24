#include <stdio.h>

long long arr[6000] = {0};
long long ans = 0;

long long long_cmp(const void* a,const void* b)
{
	return *(long long*)b - *(long long*)a;
}

int main()
{
	int n;
	scanf("%d",&n);
	int i = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%lld",&arr[i]);
	}
	//��ʯ�������Ӵ�С����
	qsort(arr,n,sizeof(long long),long_cmp);
	for(i = 1;i < n; i++)
	{
		ans += (arr[i-1] + 1) * (arr[i] +1);
		
		arr[i] += arr[i-1];
	}
	
	printf("%lld",ans);
	
	return 0;
}
