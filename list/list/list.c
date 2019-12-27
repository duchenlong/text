#define _CRT_SECURE_NO_WARNINGS 1

#include "list.h"

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//�������ʼ��
void SListInit(SListNode** plist)
{
	*plist = NULL;
}

// �������ӡ
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

// ������β��
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

// �������ͷ��
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

// �������βɾ
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

// ������ͷɾ
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

// ���������
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

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
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

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
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

// �����������
void SListDestory(SListNode** plist)
{
	free(*plist);

	*plist = NULL;
}