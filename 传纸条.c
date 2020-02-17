#include <stdio.h>

#define max(a,b) (a>b?a:b) 

int dp[55][55][55][55] = {0};
int arr[55][55] = {0};

int main()
{
	int m,n;//ѧ����λ��m��n�� 
	scanf("%d%d",&m,&n);
	int i = 0;
	int j = 0;
	//����ͬѧ�ԣ�1,1����m,n)��λѧ���ĺøж�
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d",&arr[i][j]);	
		}	
	} 
	
	int i1,j1,i2,j2;
	for(i1 = 1; i1 <= m; i1++)
	{
		for(j1 = 1; j1 <= n; j1++)
		{
			for(i2 = 1; i2 <= m; i2++)
			{
				for(j2 = 1; j2 <= n; j2++)
				{
					//ͬ����ֽ���ĺøж�
					int same = max(dp[i1-1][j1][i2-1][j2],dp[i1][j1-1][i2][j2-1]);
					//�췽��ֽ���ĺøж� 
					int diff = max(dp[i1][j1-1][i2-1][j2],dp[i1-1][j1][i2][j2-1]);
					
					dp[i1][j1][i2][j2] = max(same,diff) + arr[i1][j1];
					
					//�ж��Ƿ�����������ͬһλ��
					if(i1!=i2 && j1!=j2)
					{
						dp[i1][j1][i2][j2] += arr[i2][j2];
					} 
					//printf("%d\n",dp[i1][j1][i2][j2]);
				}
			}
		}
	}
	
	printf("%d\n",dp[m][n][m][n]);
	return 0;
}
