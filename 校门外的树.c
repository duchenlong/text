#include <stdio.h>

int arr[10005] = {0};

int main()
{
	int l,m;
	scanf("%d%d",&l,&m);
	int i = 0;
	int left,right;
	for(i = 0; i < m; i++)
	{
		scanf("%d%d",&left,&right);
		int j = 0;
		for(j = left; j <= right; j++)
		{
			if(!arr[j])
			{
				arr[j] = 1;
				l--;
			}
		}
	}
	printf("%d\n",l+1);
	return 0;
}
