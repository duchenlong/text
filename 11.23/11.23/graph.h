#pragma once

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<assert.h>

#define MAX 50

typedef struct node
{
	int adj;
}node;

typedef struct grap
{
	char vertex[MAX];
	node arr[MAX][MAX];
	int vexnum;
	int arcnum;
}grap;

typedef struct Queue
{
	char a[MAX];
	int front;
	int rear;
	int size;
}Queue;

//��ʼ��
void InitGrap(grap* pg);


//����
void ScanfGrap(grap* pg);
//���
void PrintfGrap(grap* pg);
//DFS
void FindStartDFS(grap* pg);
//BFS
void FindStartBFS(grap* pg);

void InitQueue(Queue* pq);
void EnterQueue(Queue* pq,char x);
char DeleteQueue(Queue* pq);
