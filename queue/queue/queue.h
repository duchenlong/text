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

	free(q);
	q->_front = q->_rear = NULL;
}