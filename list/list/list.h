#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

//�������ʼ��
void SListInit(SListNode** plist);

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);

// �������ӡ
void SListPrint(SListNode* plist);

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);

// �������βɾ
void SListPopBack(SListNode** pplist);

// ������ͷɾ
void SListPopFront(SListNode** pplist);

// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);

// �����������
void SListDestory(SListNode** plist);