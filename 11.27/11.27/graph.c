#define _CRT_SECURE_NO_WARNINGS 1
#include "graph.h"

int visit[MAX] = { 0 };

void InitQueue(Queue* pq)
{
	pq->front = pq->rear = 0;
	pq->size = 0;
}

void EnterQueue(Queue* pq, char x)
{
	if (pq->rear > MAX)
	{
		return;
	}
	pq->a[pq->rear++] = x;
	pq->rear = pq->rear%MAX;
	pq->size++;
}

char DeleteQueue(Queue* pq)
{
	char tx = pq->a[pq->front++];
	pq->front = pq->front%MAX;
	pq->size--;
	return tx;
}

void InitAdjLIst(AdjList* pa)
{
	pa->vexnum = pa->arcnum = 0;
}

void ScanfAdjList(AdjList* pa)
{
	int i = 0, j = 0,k=0;
	char v1, v2;
	scanf("%d%d", &pa->arcnum, &pa->vexnum);
	getchar();
	for (i = 0; i < pa->vexnum; i++)
	{
		scanf("%c", &pa->vertex[i].data);
		pa->vertex[i].firstarc = NULL;
	}
	getchar();
	for (k = 0; k < pa->arcnum; k++)
	{
		scanf("%c%c", &v1, &v2);
		getchar();
		i = LocateVex(pa, v1);
		j = LocateVex(pa, v2);
		ArcNode* node;
		node = (ArcNode*)malloc(sizeof(ArcNode));
		node->nextarc = NULL;
		node->adjvex = j;
		if (!pa->vertex[i].firstarc)
		{
			pa->vertex[i].firstarc = node;
		}
		else
		{
			ArcNode* slow;
			ArcNode* fast;
			slow = (ArcNode*)malloc(sizeof(ArcNode));
			fast = (ArcNode*)malloc(sizeof(ArcNode));
			slow = pa->vertex[i].firstarc;
			fast = slow->nextarc;
			while (fast&&fast->adjvex<j)
			{
				slow = fast;
				fast = fast->nextarc;
			}
			node->nextarc = fast;
			slow->nextarc = node;
		}
		
	}
}

int LocateVex(AdjList* pa,char x)
{
	int i = 0;
	for (i = 0; i < pa->vexnum; i++)
	{
		if (pa->vertex[i].data == x)
		{
			break;
		}
	}
	return i;
}

void TraverseGraphDFS(AdjList* pa)
{
	int i = 0;
	for (i = 0; i < pa->vexnum; i++)
	{
		if (!visit[i])
		{
			DFS(pa, i);
		}
	}
}

void DFS(AdjList* pa, int v0)
{
	printf("%c ", pa->vertex[v0].data);
	visit[v0] = 1;
	ArcNode* Farc;
	Farc = (ArcNode*)malloc(sizeof(ArcNode));
	Farc = pa->vertex[v0].firstarc;
	while (Farc)
	{
		if (!visit[Farc->adjvex])
		{
			DFS(pa, Farc->adjvex);
		}
		Farc = Farc->nextarc;
	}
}

void TraverseGraphBFS(AdjList* pa)
{
	memset(visit, 0, sizeof(visit));
	int i = 0;
	for (i = 0; i < pa->vexnum; i++)
	{
		if (!visit[i])
		{
			BFS(pa, i);
		}
	}
}

void BFS(AdjList* pa, int v0)
{
	int v=0;
	printf("%c ", pa->vertex[v0].data);
	visit[v0] = 1;
	Queue* queue;
	queue = (Queue*)malloc(sizeof(queue));
	InitQueue(queue);
	EnterQueue(queue, v0);
	while (queue->size)
	{
		v = DeleteQueue(queue);
		ArcNode* Farc;
		Farc = (ArcNode*)malloc(sizeof(ArcNode));
		Farc = pa->vertex[v].firstarc;
		while (Farc)
		{
			if (!visit[Farc->adjvex])
			{
				printf("%c ", pa->vertex[Farc->adjvex]);
				visit[Farc->adjvex] = 1;
				EnterQueue(queue, Farc->adjvex);
			}
			Farc = Farc->nextarc;
		}
	}
}