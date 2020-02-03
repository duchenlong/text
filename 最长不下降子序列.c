#include <stdio.h>
#include <string.h>

#define MAX 100000

int arr[MAX] = {0};
int hash[MAX] = {0};
int dp[MAX] = {0}; //��ʾ��λ��ǰ�治������������Ԫ����Ŀ 

int slove(num)
{
	int i = 0;
	int max = -1;
	int j = 0;
	
	for(i = 0; i < num; i++)
	{
		dp[i] = 1;//����������Ԫ�ذ��������� 
		for(j = 0; j < i; j++)
		{
			if(hash[arr[j]] <= hash[arr[i]] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1; 
			}
		}
		
		max = max > dp[i] ? max : dp[i];
	}
	
	return max;
}

int main()
{
	int n; //������
	int m; //������������
	
	scanf("%d%d",&n,&m);
	memset(hash,-1,sizeof(hash));
	
	int i = 0;
	int num = 0;
	for(i = 0; i < m; i++)
	{
		scanf("%d",&num);
		hash[num] = i;
	}
	
	int L;
	scanf("%d",&L); //�������еĴ�С
	int j = 0;
	for(i = 0; i < L; i++)
	{
		scanf("%d",&num);
		if(hash[num] != -1)
		{
			arr[j++] = num;
		}
	}
	
	printf("%d\n",slove(j));
	return 0;	
} 
