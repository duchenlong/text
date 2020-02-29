#include <stdio.h>
#include <math.h>

struct node
{
	int x;
	int y;
	int z;
	int r;
}ball[120],biol[120];

int ans[120] = {0};

int slove(int ser,int n)
{
	int num = 0;
	int i = 0;
	for(i = 0; i < n; i++)
	{
		int x = abs(ball[i].x - biol[ser].x);
		int y = abs(ball[i].y - biol[ser].y);
		int z = abs(ball[i].z - biol[ser].z);
		
		int dis2 = x*x + y*y + z*z;
		int r2 = ball[i].r * ball[i].r;
		if(dis2 < r2)
		{
			num++;
		}
	}
	return num;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	int i = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&ball[i].x,&ball[i].y,&ball[i].z,&ball[i].r);
	}
	
	for(i = 0; i < m; i++)
	{
		scanf("%d%d%d",&biol[i].x,&biol[i].y,&biol[i].z);
	}
	
	for(i = 0; i < m; i++)
	{
		ans[i] = slove(i,n);
	}
	
	for(i = 0; i < m; i++)
	{
		printf("%d ",ans[i]);
	}
	return 0;
}
