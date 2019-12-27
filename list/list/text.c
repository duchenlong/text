#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

void txt1(SListNode* pplist)
{
	SListInit(&pplist);
	SListPushBack(&pplist, 3);
	SListPushBack(&pplist, 4);
	SListPushBack(&pplist, 5);
	SListPushBack(&pplist, 6);
	SListPushFront(&pplist, 2);
	SListPushFront(&pplist, 1);
	/*SListPopBack(&pplist);
	SListPopFront(&pplist);*/
	SListNode* node = SListFind(pplist, 8);
	if (node)
	{
		printf("%d\n",node->data);
	}
	//SListEraseAfter(SListFind(pplist, 3));
	SListInsertAfter(SListFind(pplist, 3), 9);
	SListDestory(&pplist);
	SListPrint(pplist);
}

int main()
{
	SListNode list;
	txt1(&list);
	return 0;
}