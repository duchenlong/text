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

	QNode* node = q->_front;

	while (node != q->_rear)
	{
		QNode* cur = node->_pNext;
		free(node);
		node = cur;
	}
	free(node);
	free(q);
	//q->_front = q->_rear = NULL;
}

typedef struct {
	Queue Q1;
	Queue Q2;
} MyStack;

/** Initialize your data structure here. */

MyStack* myStackCreate() {
	MyStack* my = (MyStack*)malloc(sizeof(MyStack));
	/*my->Q1 = (Queue*)malloc(sizeof(Queue));
	my->Q2 = (Queue*)malloc(sizeof(Queue));*/
	QueueInit(&(my->Q1));
	QueueInit(&(my->Q2));
	return my;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	Queue* a ;
	Queue* b ;

	if (QueueEmpty(&(obj->Q1)))
	{
		a = &(obj->Q1);
		b = &(obj->Q2);
	}
	else
	{
		a = &(obj->Q2);
		b = &(obj->Q1);
	}

	QueuePush(b, x);
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	Queue* a;
	Queue* b;

	if (QueueEmpty(&(obj->Q1)))
	{
		a = &(obj->Q1);
		b = &(obj->Q2);
	}
	else
	{
		a = &(obj->Q2);
		b = &(obj->Q1);
	}
	if (QueueSize(b) == 0)
	{
		return 0;
	}
	while (QueueSize(b) > 1)
	{
		QueuePush(a, QueueFront(b));
		QueuePop(b);
	}

	QDataType ans = QueueFront(b);
	QueuePop(b);
	return ans;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
	Queue* a;
	Queue* b;

	if (QueueEmpty(&(obj->Q1)))
	{
		a = &(obj->Q1);
		b = &(obj->Q2);
	}
	else
	{
		a = &(obj->Q2);
		b = &(obj->Q1);
	}

	return QueueBack(b);
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	Queue* a;
	Queue* b;

	if (QueueEmpty(&(obj->Q1)))
	{
		a = &(obj->Q1);
		b = &(obj->Q2);
	}
	else
	{
		a = &(obj->Q2);
		b = &(obj->Q1);
	}
	if (QueueEmpty(b))
	{
		return true;
	}
	return false;
}

void myStackFree(MyStack* obj) {
	Queue* a;
	Queue* b;

	if (QueueEmpty(&(obj->Q1)))
	{
		a = &(obj->Q1);
		b = &(obj->Q2);
	}
	else
	{
		a = &(obj->Q2);
		b = &(obj->Q1);
	}

	QueueDestroy(b);
	free(obj);
}

int main()
{

	MyStack* obj = myStackCreate();
	myStackPush(obj, 2);
	myStackPush(obj, 3);
	return 0;
}