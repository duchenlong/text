#define _CRT_SECURE_NO_WARNINGS 1

#include"graph.h"


void text1(grap* pg)
{
	ScanfGrap(pg);
	PrintfGrap(pg);
	FindStartDFS(pg);
	printf("\n");
	FindStartBFS(pg);
}


int main()
{
	grap* grap1;
	Queue* queue;
	queue = (Queue*)malloc(sizeof(Queue));
	grap1 = (grap*)malloc(sizeof(grap));
	InitGrap(grap1);
	
	text1(grap1);
	return 0;
}

