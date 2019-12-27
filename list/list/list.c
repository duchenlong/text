#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//单链表初始化
void SListInit(SListNode** plist)
{
	*plist = NULL;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
	if (plist == NULL)
	{
		return;
	}
	SListNode* node = plist;
	while (node)
	{
		printf("%d->", node->data);
		node = node->next;
	}
	printf("\b\b  ");
	printf("\n");
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* node=BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = node;
	}
	else
	{
		SListNode* cur = *pplist;
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* node = BuySListNode(x);

	if (*pplist == NULL)
	{
		*pplist = node;
	}
	else
	{
		node->next = *pplist;
		(*pplist) = node;
	}
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}

	SListNode* cur = *pplist;
	SListNode* pre = *pplist;

	while (cur->next)
	{
		pre = cur;
		cur = cur->next;
	}
	if (pre == *pplist)
	{
		*pplist = NULL;
		free(*pplist);
	}
	else
	{
		pre->next = NULL;
		free(cur);
	}
	
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	if (*pplist == NULL)
	{
		return;
	}

	SListNode* node = *pplist;
	*pplist = (*pplist)->next;
	free(node);
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	if (pos == NULL)
	{
		return;
	}
	SListNode* node = BuySListNode(x);

	node->next = pos->next;
	pos->next = node;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	SListNode* nodelist = pos->next;

	free(nodelist);
	pos->next = NULL;
}

// 单链表的销毁
void SListDestory(SListNode** plist)
{
	free(*plist);

	*plist = NULL;
}