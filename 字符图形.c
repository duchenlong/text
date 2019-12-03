#include<stdio.h>

int main()
{
	int n,m;
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		int num=i;
		for(j=0;num>0&&j<m;j++)
		{
			printf("%c",'A'+num);
			num--;
		}
		if(j<m)
		{
			int k=0;
			for(k=0;k<m-j;k++)
			{
				printf("%c",'A'+k);
			}
		}
		printf("\n");
	}
	return 0;
}
