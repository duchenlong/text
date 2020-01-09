#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000 //最大顶点数
#define INF 0x3fffffff //一个很大的数 

int n = 0, m = 0, s = 0;//n为顶点数 m为边数 s为起点 
int d[MAXN] = {0}; //起点到各点最短路径的长度
int visit[MAXN] = {0};
int arr[MAXN][MAXN] = {0}; 

void Dijkstra()
{
	int i = 0;
	//初始化一步可以到达的路径长度 
	for(i = 0;i < n;i++)
	{
		if(arr[s][i])
		{
			d[i] = 	arr[s][i];
		}
		else
		{
			d[i] = INF;
		}
	}
	visit[s] = 1;
	d[s] = 0; //自己到自己的路径设置为0 
	
	for(i = 0;i < n; i++)
	{
		//找到一条最短的路 
		int j = 0,u = -1,min = INF;
		for(j = 0; j < n; j++)
		{
			if(!visit[j] && d[j] < min)
			{
				u = j;
				min = d[j];
			}
		}
		
		if(u == -1)
		{
			return ;
		}
		
		visit[u] = 1;
		d[u] = min;
		
		//更新路径 
		for(j = 0;j < n;j++)
		{
			if(!visit[j] && arr[u][j] && d[u] + arr[u][j] < d[j])
			{
				d[j] = d[u] + arr[u][j];
			}
		}
	}
}

int main()
{
	int u,v,w;
	scanf("%d%d%d",&n,&m,&s);
	int i=0;
	for(i=0;i<m;i++)
	{
		//输入行号和列号  以及对应的权 
		scanf("%d%d%d",&u,&v,&w);
		arr[u][v] = w;
	}
	
	Dijkstra();
	
	for(i=0;i<n;i++)
	{
		printf("%d ",d[i]);
	}
	
	return 0;
}
