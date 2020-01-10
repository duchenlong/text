#define _CRT_SECURE_NO_WARNINGS 1

#include "qsort.h"

void Show(int* a, int N)
{
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

//²âÊÔÅÅÐòµÄÐÔÄÜ¶Ô±È
void TestOP()
{
	srand((unsigned)time(NULL));

	const int N =10000000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);
	int* a7 = (int*)malloc(sizeof(int)*N);
	int* a8 = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	
	//int begin1 = clock();
	//InsertSort(a1, N);	// ²åÈëÅÅÐò
	//int end1 = clock();
	//printf("InsertSort: %d \n", end1 - begin1);

	int begin2 = clock();
	ShellSort(a2, N);	// Ï£¶ûÅÅÐò
	int end2 = clock();
	printf("ShellSort: %d\n", end2 - begin2);

	//int begin3 = clock();
	//SelectSort(a3, N);	// Ñ¡ÔñÅÅÐò
	//int end3 = clock();
	//printf("SelectSort: %d\n", end3 - begin3);

	int begin4 = clock();
	HeapSort(a4, N);	// ¶ÑÅÅÐò
	int end4 = clock();
	printf("HeapSort: %d\n", end4 - begin4);
	//Show(a4, N);

	int begin5 = clock();
	PartSort3(a5, 0, N-1);	// ¿ìËÙÅÅÐò
	int end5 = clock();
	//Show(a5, N);
	printf("QuickSort1: %d\n", end5 - begin5);

	//int begin7 = clock();
	//PartSort2(a7, 0, N - 1);	// ¿ìËÙÅÅÐò
	//int end5 = clock();
	////Show(a5, N);
	//printf("QuickSort2: %d\n", end5 - begin5);

	//int begin8 = clock();
	//PartSort3(a8, 0, N - 1);	// ¿ìËÙÅÅÐò
	//int end5 = clock();
	////Show(a5, N);
	//printf("QuickSort3: %d\n", end5 - begin5);

	//int begin6 = clock();
	//MergeSort(a6, N);	// ¹é²¢ÅÅÐò
	//int end6 = clock();
	//printf("MergeSort: %d\n", end6 - begin6);

	
	

	/*free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);*/
}

int main()
{
	TestOP();
	return 0;
}