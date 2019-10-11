#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define MAX 3

typedef struct queue
{
	int data[MAX] ;
	int* front;
	int* rear;
	int size;
}queue;

void QueueInit(queue* pq)
{
	pq->front = pq->rear = pq->data;
	pq->size = 0;
}

void QueuePush(queue* pq,int x)
{
	if (pq->size  +1== MAX)
	{
		return;
	}
	*pq->rear = x;
	pq->rear++;
	pq->size++;
	if (pq->rear-pq->data== MAX)
	{
		pq->rear = pq->data;
	}
}

void QueuePop(queue* pq)
{
	if (pq->size +1== 0)
	{
		return;
	}
	*pq->front++;
	pq->size--;
	if (pq->front - pq->data == MAX)
	{
		pq->front = pq->data;
	}
}
int QueueFront(queue* pq)
{
	if (pq->size == 0)
	{
		return 0;
	}
	return *(pq->front);
}
void QueueShow(queue* pq)
{
	int i = pq->front;
	int j = 0;
	for (i; i < pq->rear; i++)
	{
		printf("%d ", *pq->front + j);
		j++;
	}
}

int QueueBack(queue* pq)
{
	if (pq->rear == pq->data)
	{
		return pq->data[MAX - 1];
	}
	return *(pq->rear - 1);
}
int main()
{
	queue* l;
	l = (queue*)malloc(sizeof(queue));
	QueueInit(l);
	QueuePush(l,2);
	QueuePush(l,5);
	QueuePush(l,8);
	//printf("%d ", QueueFront(l));
	QueuePop(l);
	printf("%d ", QueueFront(l));
	QueuePush(l, 9);
	//QueuePop(l);
	printf("%d ", QueueFront(l));
	//QueuePop(l);
	printf("%d ", QueueBack(l));
	//QueuePop(l);
	printf("\n");
	QueueShow(l);
	return 0;
}