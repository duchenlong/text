#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000 //��󶥵���
#define INF 0x3fffffff //һ���ܴ���� 

int n = 0, m = 0, s = 0;//nΪ������ mΪ���� sΪ��� 
int d[MAXN] = {0}; //��㵽�������·���ĳ���
int visit[MAXN] = {0};
int arr[MAXN][MAXN] = {0}; 

void Dijkstra()
{
	int i = 0;
	//��ʼ��һ�����Ե����·������ 
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
	d[s] = 0; //�Լ����Լ���·������Ϊ0 
	
	for(i = 0;i < n; i++)
	{
		//�ҵ�һ����̵�· 
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
		
		//����·�� 
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
		//�����кź��к�  �Լ���Ӧ��Ȩ 
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
