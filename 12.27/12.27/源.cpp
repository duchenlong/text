#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
#include <assert.h>

typedef int QDataType;

// ��ʽ�ṹ����ʾ����
typedef struct QListNode
{
	struct QListNode* _pNext;
	QDataType _data;
}QNode;

// ���еĽṹ
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������
void QueueInit(Queue* q);
// ��β�����
void QueuePush(Queue* q, QDataType data);
// ��ͷ������
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q);
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q);
// ��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* q);
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
// ���ٶ���
void QueueDestroy(Queue* q);


// ��ʼ������
void QueueInit(Queue* q)
{
	assert(q);

	q->_rear = q->_front = NULL;
}
// ��β�����
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
// ��ͷ������
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
// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(Queue* q)
{
	assert(q->_front);

	return q->_front->_data;
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q->_rear);

	return q->_rear->_data;
}
// ��ȡ��������ЧԪ�ظ���
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);

	return q->_front ? 0 : 1;
}
// ���ٶ���
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