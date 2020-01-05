#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));

	head->_next = head;
	head->_prev = head;
	return head;
}
// 双向链表销毁
void ListDestory(ListNode* plist)
{
	ListNode* node = plist->_next;

	while (plist != node)
	{
		ListNode* nodenext = node->_next;

		free(node);
		node = nodenext;
	}

	free(plist);
}

// 双向链表next打印
void ListPrintNext(ListNode* plist)
{
	ListNode* node = plist->_next;

	while (node != plist)
	{
		printf("%d ", node->_data);
		node = node->_next;
	}

}

// 双向链表prev打印
void ListPrintPrev(ListNode* plist)
{
	ListNode* node = plist->_prev;

	while (node != plist)
	{
		printf("%d ", node->_data);
		node = node->_prev;
	}

}
// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;

	ListNode* tail = plist->_prev;

	tail->_next = node;
	node->_prev = tail;

	plist->_prev = node;
	node->_next = plist;
}
// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	if (plist == plist->_prev)
	{
		return;
	}

	ListNode* tail = plist->_prev;
	ListNode* tailprev = tail->_prev;

	plist->_prev = tailprev;
	tailprev->_next = plist;
	free(tail);
}
// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;
	ListNode* next = plist->_next;

	node->_next = next;
	next->_prev = node;

	plist->_next = node;
	node->_prev = plist;
}
// 双向链表头删
void ListPopFront(ListNode* plist)
{
	if (plist->_next == plist)
	{
		return;
	}

	ListNode* next = plist->_next;
	ListNode* cur = next->_next;

	plist->_next = cur;
	cur->_prev = plist;
	free(next);
}
// 双向链表查找
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	ListNode* node = plist->_next;

	while (node != plist)
	{
		if (node->_data == x)
		{
			return node;
		}
		node = node->_next;
	}

	return NULL;
}
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_data = x;

	ListNode* prev = pos->_prev;

	prev->_next = node;
	node->_prev = prev;

	pos->_prev = node;
	node->_next = pos;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* next = pos->_next;
	ListNode* prev = pos->_prev;

	prev->_next = next;
	next->_prev = prev;

	free(pos);
}