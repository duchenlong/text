#include<stdio.h>

#define MAX 10005

int arc[1000][1000]={0};

void Floyd(int n)
{
	int i=0;	
	int j=0;
	int k=0;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(arc[i][k]!=MAX&&arc[k][j]!=MAX)
				{
					if(arc[i][j]>arc[i][k]+arc[k][j])
					{
						arc[i][j]=arc[i][k]+arc[k][j];
					}
				}
				
			}
		}
	}
	
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int a,b,adj,i=0;
	int j=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
			{
				arc[i][i]=0;
			}
			else
			{
				arc[i][j]=MAX;
			}
		}
	}
	
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&adj);
		arc[a-1][b-1]=adj;
	}
	
	Floyd(n);
	
	for(i=1;i<n;i++)
	{
		printf("%d\n",arc[0][i]);
	}
	return 0;
}
