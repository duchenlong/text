#include <stdio.h>

#define max(a,b) a>b?a:b

int dp[20005] = {0};
int arr[50] = {0};

int main()
{
	int V;//�������� 
	scanf("%d",&V);
	int n;//n����Ʒ
	scanf("%d",&n);
	
	int i = 0;
	int j = 0;
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);	
	} 
	
	for(i = 0; i < n; i++)//���η���n������ 
	{
		for(j = V; j >= arr[i]; j--)//�жϸ����������� ���Ƿ���Է������� 
		{
			//��������������
			//dp[j - arr[i]] j�����³��˸����壬�����Է����������� 
			dp[j] = max(dp[j],dp[j - arr[i]] + arr[i]);
		}
	}
//	for(i = 0; i <= V; i++)
//	{
//		printf("%d ",dp[i]);
//	}
	printf("%d\n",V - dp[V]);
	return 0;
}
