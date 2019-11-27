#define _CRT_SECURE_NO_WARNINGS 1

#include"graph.h"


void text1(AdjList* pa)
{
	ScanfAdjList(pa);
	TraverseGraphDFS(pa);
	printf("\n");
	TraverseGraphBFS(pa);
}

int main()
{
	AdjList* ArrList;
	ArrList = (AdjList*)malloc(sizeof(AdjList));
	InitAdjLIst(ArrList);
	text1(ArrList);
	return 0;
}