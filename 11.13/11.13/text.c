#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"

void text1()
{
	SeqList* p;
	p = (SeqList*)malloc(sizeof(SeqList));
	SeqListInit(p, 2);
	SeqListPushBack(p, 1);
	SeqListPushBack(p, 2);
	SeqListPushBack(p, 3);
	SeqListPushBack(p, 4);
	SeqListPushBack(p, 5);
	SeqListPushBack(p, 6);
	SeqListPushBack(p, 7);
	SeqListPushBack(p, 8);
	SeqListPopBack(p);
	SeqListPushFront(p, 0);
	SeqListPushFront(p, 8);
	SeqListPopFront(p);
	SeqListPopFront(p);
	SeqListPrint(p);
}

void text2()
{
	SeqList* p;
	p = (SeqList*)malloc(sizeof(SeqList));
	SeqListInit(p, 2);
	SeqListPushBack(p, 1);
	SeqListPushBack(p, 2);
	SeqListPushBack(p, 3);
	SeqListPushBack(p, 4);
	SeqListPushBack(p, 5);
	SeqListPushBack(p, 3);
	SeqListPushBack(p, 6);
	SeqListPushBack(p, 3);
	SeqListPushBack(p, 7);
	SeqListPushBack(p, 8);
	//printf("\n%d\n", SeqListFind(p, 0));

	/*SeqListInsert(p, 2, 10);
	SeqListInsert(p, 4, 19);
	SeqListInsert(p, 2, 17);
	SeqListInsert(p, 5, 15);
	SeqListInsert(p, 3, 10);*/
	/*SeqListErase(p, 5);
	SeqListModify(p, 1, 0);*/
	/*SeqListRemove(p, 7);
	SeqListBubbleSort(p);
	printf("%d\n", SeqListBinaryFind(p, 9));*/
	//SeqListBubbleSort(p);
	SeqListRemoveAll(p, 10);
	SeqListPrint(p);
}
int main()
{
	//text1();
	text2();
	return 0;
}