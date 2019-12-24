#define _CRT_SECURE_NO_WARNINGS 1

#include "queue.h"

int main()
{
	Queue* q =(Queue*)malloc(sizeof(Queue));

	QueueInit(q);
	return 0;
}