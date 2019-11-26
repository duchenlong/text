#define _CRT_SECURE_NO_WARNINGS 1

#include"graph.h"

int visit[MAX] = { 0 };

void InitGrap(grap* pg)
{
	assert(pg);

	pg->vexnum = pg->arcnum = 0;
}

//找顶点在数组的位置
int LocateVertex(grap* pg, char x)
{
	assert(pg);

	int i = 0;
	for (i = 0; i < pg->vexnum; i++)
	{
		if (pg->vertex[i] == x)
		{
			return i;
		}
	}
	return -1;
}

void ScanfGrap(grap* pg)
{
	assert(pg);

	int i = 0, j = 0, k = 0;
	char v1 = 0, v2 = 0;
	int weight = 0;

	scanf("%d%d", &pg->arcnum, &pg->vexnum);
	getchar();
	for (i = 0; i < pg->vexnum; i++)
	{
		for (j = 0; j < pg->vexnum; j++)
		{
			pg->arr[i][j].adj = 0;
		}
	}
	for (i = 0; i < pg->vexnum; i++)
	{
		scanf("%c", &pg->vertex[i]);
	}
	getchar();
	for (k = 0; k < pg->arcnum; k++)
	{
		scanf("%c%c%d", &v1, &v2, &weight);
		getchar();
		i = LocateVertex(pg, v1);
		j = LocateVertex(pg, v2);
		pg->arr[i][j].adj = weight;
	}
}

void PrintfGrap(grap* pg)
{
	assert(pg);
	int i = 0, j = 0;

	printf("%d %d\n", pg->vexnum, pg->arcnum);

	for (i = 0; i < pg->vexnum; i++)
	{
		for (j = 0; j < pg->vexnum; j++)
		{
			printf("%d ", pg->arr[i][j].adj);
		}
		printf("\n");
	}

	printf("\n");
}
//队列
void InitQueue(Queue* pq)
{
	pq->front = pq->rear = 0;
	pq->size = 0;
}

void EnterQueue(Queue* pq,char x)
{
	if (pq->rear > MAX)
	{
		return;
	}
	pq->a[pq->rear++] = x;
	pq->rear=pq->rear%MAX;
	pq->size++;
}

char DeleteQueue(Queue* pq)
{
	char tx = pq->a[pq->front++];
	pq->front = pq->front%MAX;
	pq->size--;
	return tx;
}


void Visit(grap* pg, int v0)
{
	printf("%c ", pg->vertex[v0]);
}

int Findvertex(grap* pg, int v0)
{
	int j = 0;
	for (j = 0; j < pg->vexnum; j++)
	{
		if (pg->arr[j][v0].adj>0 && !visit[j])
		{
			return j;
		}
	}
	return v0;
}

void _DFS(grap* pg, int v0)
{
	assert(pg);
	int i = 0;

	Visit(pg, v0);
	visit[v0] = 1;
	v0 = Findvertex(pg, v0);
	for (i = 0; i < pg->vexnum; i++)
	{
		if (!visit[i] && pg->arr[v0][i].adj>0)
		{
			_DFS(pg, i);
		}
	}
}


void FindStartDFS(grap* pg)
{
	assert(pg);
	int i = 0;
	for (i = 0; i < pg->vexnum; i++)
	{
		if (!visit[i])
		{
			_DFS(pg, i);
		}
	}
}

int Firstvertex(grap* pg, int v)
{
	int i = 0;
	for (i = 0; i < pg->vexnum; i++)
	{
		if (pg->arr[v][i].adj>0)
		{
			return i;
		}
	}
	return -1;
}

int Nextvertex(grap* pg, int v, int w)
{
	int i = 0;
	for (i = w+1; i < pg->vexnum; i++)
	{
		if (pg->arr[v][i].adj>0)
		{
			return i;
		}
	}
	return -1;
}

void _BFS(grap* pg, int v0)
{
	Queue* queue;
	queue = (Queue*)malloc(sizeof(Queue));
	Visit(pg, v0);
	visit[v0] = 1;
	InitQueue(queue);
	EnterQueue(queue, v0);

	while (queue->size)
	{
		int v=DeleteQueue(queue);
		int w = Firstvertex(pg, v);
		while (w != -1)
		{
			if (!visit[w])
			{
				Visit(pg,w);
				visit[w] = 1;
				EnterQueue(queue, w);
			}
			w = Nextvertex(pg, v, w);
		}
	}
}

void FindStartBFS(grap* pg)
{
	assert(pg);
	memset(visit, 0, sizeof(visit));
	int i = 0;
	for (i = 0; i < pg->vexnum; i++)
	{
		if (!visit[i])
		{
			_BFS(pg, i);
		}
	}
}


