#include<stdio.h>
#include<string.h>

#define MAX 10000
#define max1(a, b) a > b ? a : b

struct edge
{
	int _v;
	int _next;
}edge[MAX*2];

int head[MAX]={0};
int dp[MAX][2]={0};
int M=0;

void Creat(int from,int to)
{
	edge[M]._v=to;
	edge[M]._next=head[from];
	head[from]=M++;
	
	edge[M]._v = from;
    edge[M]._next = head[to];   
    head[to] = M++;  
    
    return ;
}

void DFS(int x,int pre)
{
	int i=head[x];
	int v=0;
	for(;i!=-1;i=edge[i]._next)
	{
		v=edge[i]._v;
		if(v==pre)
		{
			continue;
		}
		DFS(v,x);
		dp[x][1] += dp[v][0];               
        dp[x][0] += max1(dp[v][0], dp[v][1]);
	}
	return ;
}

int main()
{
	int n;
	scanf("%d",&n);
	
	int i=0;
	memset(head,-1,sizeof(head));
	for(i=1;i<=n;i++)
	{
		scanf("%d",&dp[i][1]);
	}
	
	for(i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		Creat(a,b);
	}
	DFS(1,-1);
	int tmp = max1(dp[1][0], dp[1][1]);   
    printf("%d\n", tmp);
	return 0;
}
