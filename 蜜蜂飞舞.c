#include <stdio.h>
#include <math.h>

int bee1[1000][3] = {0};
int bee2[1000][3] = {0};
double ans = {0};

int main()
{
	int exe = 0; //有多少组示例
	int i = 0;
	//while() != EOF)
	int count; //飞行次数
	scanf("%d",&count);
	int j = 0;//printf("%d\n",exe);
	while(count--)
	{
		//a,b,c d,e,f 分别表示飞行时的方向向量
		//t 表示时间 
		int a,b,c,d,e,f,t;
		scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&t);
		bee1[j][0] = a * t;
		bee1[j][1] = b * t;
		bee1[j][2] = c * t;
			
		bee2[j][0] = d * t;
		bee2[j][1] = e * t;
		bee2[j][2] = f * t;
		j++;
	}
		
	int x1,y1,z1,x2,y2,z2;
	scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
	for(i = 0; i < j; i++)
	{
		x1 += bee1[i][0];
		y1 += bee1[i][1];
		z1 += bee1[i][2];
			
		x2 += bee2[i][0];
		y2 += bee2[i][1];
		z2 += bee2[i][2];
	}
	int x = (x2 - x1) * (x2 - x1);
	int y = (y2 - y1) * (y2 - y1);
	int z = (z2 - z1) * (z2 - z1);
	
	ans = sqrt((double)(x+y+z));
	
	printf("%.4lf\n",ans);
	return 0;
}
