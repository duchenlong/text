#include<stdio.h>
#include<math.h>

#define DIV (1000000007)
int a[100][100]={0};

int main()
{
	int k,l;
	scanf("%d%d",&k,&l);
	
	
	int i=0;
	int j=0;
	int n=0;
	int ans=0;
	
	for(i=0;i<k;i++)
	{
		a[0][i]=1;
	}
	
	for(i=1;i<l;i++)
	{
		for(j=0;j<k;j++)
		{
			for(n=0;n<k;n++)
			{
				if(abs(n-j)!=1)
				{
					a[i][j]+=a[i-1][n];
					a[i][j]=a[i][j]%DIV;
				}
			}
		}
	}
	
	for(i=1;i<k;i++)
	{
		ans+=a[l-1][i];
		ans%=DIV;
	}
	printf("%d\n",ans);
	return 0;
}
