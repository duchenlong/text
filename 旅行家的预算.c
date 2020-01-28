#include <stdio.h>
#define MAX 0xffffffff
struct node
{
	double path;//加油站距离起点的距离 
	double money;//加油站每升油的价格 
}arr[100000];

double C;//汽车油箱的容量
double d;//每升油可以行使的距离
double N;//沿途加油站数量 
double d1;//d1 两个城市之间的距离
double p;//p 出发点每升汽油的价格
double ans = 0;

void sort()
{
	int i = N + 1;
	int j = 0;
	for(i = 1; i < N; i++)
	{
		for(j = 0; j < N - i; j++)
		{
			if(arr[j].path > arr[j + 1].path)
			{
				struct node tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp; 
			}
		}	
	} 
}

void slove()
{
	double mpath = 0;//表示当前加油站加满油可以到达的距离
	int now = 0;//当前加油站的编号 
	double tank = 0;//当前汽车的油量 
	
	while(now < N)
	{
		mpath = C * d;
		int i = now + 1;
		double minoil = MAX;
		int k = now; 
		
		for(; i <= N && arr[i].path - arr[now].path <= mpath; i++)
		{
			//找到遇到的第一个低油价的下标 
			if(arr[i].money < arr[k].money)
			{
				k = i;
				break;
			}
			
			//如果可以达到范围内油价都比当前大，找到最低油价的下标 
			if(minoil > arr[now].money)
			{
				minoil =  arr[i].money;
				k = i;
			}	
		}
		
		//如果加满油到达不了最近的加油站，退出 
		if(k == now)
		{
			//printf("%d\n",now);
			printf("No Solution\n");
			return; 
		}
		//计算汽车到该加油站所需要的油量
		double need = (arr[k].path - arr[now].path) / d; 
		if(arr[k].money < arr[now].money)//找到有比当前加油站廉价油的加油站 
		{
			//只需要买到该加油站的油
			if(need <= tank)
			{
				tank -= need;	
			} 
			else
			{
				ans += (need - tank) * arr[now].money;
				//printf("%.2lf %d\n",ans,k);
				tank = 0;
			}
		}
		else
		{
			ans += (C - tank) * arr[now].money;
			tank = C - need;
		}
		//printf("%d %.2lf\n",tank,ans);
		now = k; //到达加油站k ,进入下一层循环 
	}
	
	printf("%.2lf\n",ans);	 
} 

int main()
{
	 
	scanf("%lf%lf%lf%lf%lf",&d1,&C,&d,&p,&N);
	int i = 0;
	arr[i].path = 0,arr[i].money=p;
	for(i = 1; i <= N; i++)
	{
		scanf("%lf%lf",&arr[i].path,&arr[i].money);
	}
	arr[i].path = d1,arr[i].money=0;
	N++;
	sort();
	slove();
//	for(i = 0; i <= N; i++)
//	{
//		printf("%.2lf %.2lf %d\n",arr[i].path,arr[i].money,i);
//	}
	
	return 0;
}
