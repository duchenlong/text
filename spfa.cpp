#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define MAX 200100
#define MAX_VAL 99999999

struct edge
{
	int to; //边的终点 
	int val;//边的权值 
	int next;//上一条相同起点的边的编号 
}e[MAX];//e[i] 边的起点 i

int m;//边的数目 
int n;//顶点数目 
int head[MAX]; //表示以i为起点的边的编号 
int dis[MAX]; //表示1号点到i号点的距离

//边的添加 
void add(int from,int to,int val,int len)
{
	e[len].to = to;
	e[len].val = val;
	e[len].next = head[from];//head[from] 表示上一条起点为from 的边 的编号 
	head[from] = len;//添加这条边后，最新的以from为起点的边的编号是len 
}

//初始化路径数组的值，不能使用memset 
void Init(int* a,int len,int val)
{
	int i = 0;
	for(i = 0; i <= len; i++)
	{
		a[i] = val;
	}
}

void spfa()
{
	int s;
	queue<int>q;
	Init(dis,n,MAX_VAL);
	int visit[MAX];//查看该边是否在队列中 0-->不在  1-->在 
	int judge[MAX];//判断有无负环 
	memset(judge,0,sizeof(judge));
	memset(visit,0,sizeof(visit));
	dis[1] = 0;//初始化起点到起点的路径为0 
	q.push(1);
	visit[1] = 1;
	while(!q.empty())
	{
		int from = q.front();//得到队头的需要判断的边的起点 
		q.pop();
		visit[from] = 0;
		int i = 0;
		//遍历该起点可以到达的所有边 
		for(i = head[from];i != -1; i = e[i].next)
		{
			int to = e[i].to;
			//进行以from为起点的所有路径的松弛 
			if(dis[to] > dis[from] + e[i].val)
			{
				dis[to] = dis[from] + e[i].val;
				//如果成功松弛之后，把不在队列中的边加入队列中 
				if(visit[to] == 0)
				{
					q.push(to);
					visit[to] = 1;
					judge[to]++;
					if(judge[to] > n)
					{
						printf("存在负环\n");
						return ;
					}
				}
			}
		}
	}
}

int main()
{
	cin>>n>>m;
	int from,to,val;
	memset(head,-1,sizeof(head));
	int i = 0;
	for(i = 0; i < m; i++)
	{
		cin>>from>>to>>val;
		add(from,to,val,i+1);//用数组形式来存储图的各个边 
	}
	spfa();
	for(i = 2; i <= n; i++)
	{
		cout<<dis[i]<<endl;
	}
}
