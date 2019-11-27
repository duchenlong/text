#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 50

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode* nextarc;
}ArcNode;

typedef struct VertexNode
{
	char data;
	ArcNode* firstarc;
}VertexNode;

typedef struct AdjList
{
	VertexNode vertex[MAX];
	int vexnum;
	int arcnum;
}AdjList;

typedef struct Queue
{
	char a[MAX];
	int front;
	int rear;
	int size;
}Queue;

void InitAdjLIst(AdjList* pa);
void ScanfAdjList(AdjList* pa);
int LocateVex(AdjList* pa, char x);

void DFS(AdjList* pa, int v0);
void TraverseGraphDFS(AdjList* pa);
void TraverseGraphBFS(AdjList* pa);
void BFS(AdjList* pa, int v0);

void InitQueue(Queue* pq);
void EnterQueue(Queue* pq, char x);
char DeleteQueue(Queue* pq);