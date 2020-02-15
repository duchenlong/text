#include <stdio.h>

#define max(a,b) a>b?a:b

int dp[1005] = {0}; //dp[i] ��ʾ��ʱi ���ɵ�������ҩ��ֵ 

int main()
{
	int t,m;
	scanf("%d%d",&t,&m);
	int arr[1005][2] = {0}; //arr[i][0] ��ʾ�ɼ�ҩ�ݵ�ʱ�� arr[1]��ʾҩ�ݵļ�ֵ 
	int i = 0;
	int value,time;
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d",&time,&value);
		if(time > t)
		{
			i--;
			m--;
			continue;	
		}
		arr[i][0] = time;
		arr[i][1] = value;
	}
	
	int j = 0;
	for(i = 1; i <= m; i++)
	{
		for(j = t; j >= arr[i][0]; j--)
		{
			value = dp[j - arr[i][0]] + arr[i][1];
			dp[j] = max(dp[j],value);
		}
	}
	
	printf("%d ",dp[t]);
	return 0;
}
