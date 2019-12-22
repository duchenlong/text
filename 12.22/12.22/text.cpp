#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct {
	int _size;
	int* _arr;
	int _front;
	int _rear;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */
bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

MyCircularQueue* myCircularQueueCreate(int k) {
	MyCircularQueue* mq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));

	mq->_arr = (int*)malloc(sizeof(int)*(k + 1));
	mq->_front = mq->_rear = 0;
	mq->_size = k + 1;
	return mq;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
	if (myCircularQueueIsFull(obj))
	{
		return false;
	}

	obj->_arr[obj->_rear++] = value;
	obj->_rear %= obj->_size;
	return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return false;
	}

	obj->_front = (obj->_front + 1) % obj->_size;
	return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}

	return obj->_arr[obj->_front];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
	if (myCircularQueueIsEmpty(obj))
	{
		return -1;
	}

	int newn = obj->_rear - 1;
	if (obj->_rear == 0)
	{
		newn = obj->_size - 1;
	}
	return obj->_arr[newn];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
	if (obj->_front == obj->_rear)
	{
		return true;
	}
	return false;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
	if ((obj->_rear + 1) % obj->_size == obj->_front)
	{
		return true;
	}
	return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->_arr);
	free(obj);
}


int main()
{
	MyCircularQueue* obj=myCircularQueueCreate(5);

	return 0;
}