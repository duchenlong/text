#include <stdio.h>


int arr[1600][1600] = {0};//压缩矩阵 
int a[1600][1600] = {0};//辅助压缩矩阵 
int dp[1600][1600] = {0};//存储矩阵 
int ans = 0;
//计算四个方向的max
int leftup[1600][1600] = {0};
int rightup[1600][1600] = {0};
int leftdown[1600][1600] = {0};
int rightdown[1600][1600] = {0};

int max(int a,int b)
{
	return a>b?a:b;
}

void show(int row,int col)
{
	int i = 0;
	int j = 0;
	for(i = 1; i <= row; i++)
	{
		for(j = 1; j <= col; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void slove(int m,int n,int k)
{
	int i = 0;
	int j = 0;
	
	for(i=k;i<=m;i++) {
		for(j=k;j<=n;j++) {
			//左边，上边 最大 
			leftup[i][j]=max(arr[i][j], max(leftup[i-1][j], leftup[i][j-1]));
		}
	}
	
	for(i=k;i<=m;i++) {
		for(j=n-k+1;j>=1;j--) {
			//上边，右边  最大 
			rightup[i][j]=max(arr[i][j+k-1], max(rightup[i-1][j], rightup[i][j+1]));
		}
	}
		
	for(i=m-k+1;i>=1;i--)  {
		for(j=k;j<=n;j++) {
			leftdown[i][j]=max(arr[i+k-1][j], max(leftdown[i][j-1], leftdown[i+1][j]));
		}
	}
		
	for(i=m-k+1;i>=1;i--)  {
		for(j=n-k+1;j>=1;j--) {
			rightdown[i][j]=max(arr[i+k-1][j+k-1], max(rightdown[i+1][j], rightdown[i][j+1]));
		}
	}
	//上下左右四个方向的最大值 
	for(i=k;i+k<=m;++i)
		for(j=k;j+k<=n;++j)
		{
			//左  和  左上，右上，左下 
			int aa=max(leftup[m][j]+rightup[i][j+1]+rightdown[i+1][j+1],leftup[i][j]+rightup[m][j+1]+leftdown[i+1][j]);
			//左上 
			int bb=max(leftup[i][j]+rightup[i][j+1]+leftdown[i+1][n],leftup[i][n]+leftdown[i+1][j]+rightdown[i+1][j+1]);
			ans=max(ans,max(aa,bb));
		}
		
	// | 
	for(i=2*k;i+k<=m;++i)
		for(j=k;j<=n;++j)
			ans=max(ans,leftup[i-k][n]+leftdown[i+1][n]+arr[i][j]);
	// 一 
	for(j=2*k;j+k<=m;++j)
		for(i=k;i<=n;++i)
			ans=max(ans,leftup[m][j-k]+rightup[m][j+1]+arr[i][j]);
}

int main()
{
	int m,n,k;
	scanf("%d%d%d",&m,&n,&k);
	
	int i = 0;
	int j = 0;
	//k*k压缩在左下角
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			scanf("%d",&dp[i][j]);
			a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + dp[i][j];
			arr[i][j] = a[i][j] - a[i][j-k] - a[i-k][j] + a[i-k][j-k];
		}
	} 
	//show(m,n);
	slove(m,n,k);
//	int num = 0;
//	int col[1600] = {0};
//	//k*k 压缩在右上角 
//	for(i = 1; i <= m; i++)
//	{
//		int count = 0;
//		for(j = 1; j <= n; j++)
//		{
//			scanf("%d",&dp[i][j]);
//			count += dp[i][j];
//			//行压缩 
//			if(j >= k)
//			{
//				//printf(" |%d - %d| ",k,count);
//				arr[i][j - k+1] = count;
//				count -= dp[i][j-k+1];
//				dp[i][j-k+1] = arr[i][j-k+1];
//			}
//		}
//	}
//	show(m,n-k+1);
//	//列压缩 
//	for(i = 1; i <= m; i++)
//	{
//		//printf(" |%d - %d| ",k,col[i]);
//		for(j = 1; j <= n-k+1; j++)
//		{
//			col[j] += arr[i][j];
//			//printf(" |%d| ",col[j]);
//			if(i >= k)
//			{
//				arr[i-k+1][j] = col[j];
//				col[j] -= dp[i-k+1][j];
//			}
//			
//		}
//	}
	
	printf("%d",ans);
	return 0;
}
