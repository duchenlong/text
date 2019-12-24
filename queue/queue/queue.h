#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
#include <assert.h>

typedef int QDataType;

// 链式结构：表示队列
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// 队列的结构
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType data);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列队尾元素
QDataType QueueBack(Queue* q);
// 获取队列中有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);


// 初始化队列
void QueueInit(Queue* q)
{
	assert(q);

	q->_rear = q->_front = NULL;
}
// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
	assert(q);

	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->_data = data;
	node->_pNext = NULL;

	if (!q->_rear)
	{
		q->_front = q->_rear = node;
	}
	else
	{
		q->_rear->_pNext = node;
		q->_rear = node;
	}
}
// 队头出队列
void QueuePop(Queue* q)
{
	assert(q);

	if (!q->_front)
	{
		return;
	}
	
	if (q->_front == q->_rear)
	{
		q->_front = q->_rear = NULL;
	}
	else
	{
		q->_front = q->_front->_pNext;
	}
}
// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
	assert(q->_front);

	return q->_front->_data;
}
// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q->_rear);

	return q->_rear->_data;
}
// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
	assert(q);

	int num = 0;
	QNode* node = q->_front;
	while (node)
	{
		num++;
		node = node->_pNext;
	}

	return num;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_front ? 0 : 1;
}
// 销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);

	free(q);
	q->_front = q->_rear = NULL;
}