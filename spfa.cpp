#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define MAX 200100
#define MAX_VAL 99999999

struct edge
{
	int to; //�ߵ��յ� 
	int val;//�ߵ�Ȩֵ 
	int next;//��һ����ͬ���ıߵı�� 
}e[MAX];//e[i] �ߵ���� i

int m;//�ߵ���Ŀ 
int n;//������Ŀ 
int head[MAX]; //��ʾ��iΪ���ıߵı�� 
int dis[MAX]; //��ʾ1�ŵ㵽i�ŵ�ľ���

//�ߵ���� 
void add(int from,int to,int val,int len)
{
	e[len].to = to;
	e[len].val = val;
	e[len].next = head[from];//head[from] ��ʾ��һ�����Ϊfrom �ı� �ı�� 
	head[from] = len;//��������ߺ����µ���fromΪ���ıߵı����len 
}

//��ʼ��·�������ֵ������ʹ��memset 
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
	int visit[MAX];//�鿴�ñ��Ƿ��ڶ����� 0-->����  1-->�� 
	int judge[MAX];//�ж����޸��� 
	memset(judge,0,sizeof(judge));
	memset(visit,0,sizeof(visit));
	dis[1] = 0;//��ʼ����㵽����·��Ϊ0 
	q.push(1);
	visit[1] = 1;
	while(!q.empty())
	{
		int from = q.front();//�õ���ͷ����Ҫ�жϵıߵ���� 
		q.pop();
		visit[from] = 0;
		int i = 0;
		//�����������Ե�������б� 
		for(i = head[from];i != -1; i = e[i].next)
		{
			int to = e[i].to;
			//������fromΪ��������·�����ɳ� 
			if(dis[to] > dis[from] + e[i].val)
			{
				dis[to] = dis[from] + e[i].val;
				//����ɹ��ɳ�֮�󣬰Ѳ��ڶ����еı߼�������� 
				if(visit[to] == 0)
				{
					q.push(to);
					visit[to] = 1;
					judge[to]++;
					if(judge[to] > n)
					{
						printf("���ڸ���\n");
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
		add(from,to,val,i+1);//��������ʽ���洢ͼ�ĸ����� 
	}
	spfa();
	for(i = 2; i <= n; i++)
	{
		cout<<dis[i]<<endl;
	}
}
