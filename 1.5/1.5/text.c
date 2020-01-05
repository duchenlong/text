#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

int main()
{
	ListNode* head = ListCreate();
	ListPushBack(head, 6);
	ListPushBack(head, 5);
	ListPushBack(head, 4);
	ListPushBack(head, 3);
	ListPushBack(head, 2);
	ListPushBack(head, 1);
	
	ListPushFront(head, 6);
	ListPushFront(head, 5);
	ListPushFront(head, 4);
	ListPushFront(head, 3);
	ListPushFront(head, 2);
	ListPushFront(head, 1);
	ListPushFront(head, 0);

	ListNode* node = ListFind(head, 6);
	printf("%d\n", node->_data);

	ListInsert(ListFind(head, 3), 2);
	ListErase(ListFind(head, 4));
	ListPopBack(head);

	ListPrintPrev(head);
	printf("\n");
	ListPrintNext(head);

	return 0;
}