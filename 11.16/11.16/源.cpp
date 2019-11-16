#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		struct ListNode* LessHead = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* LessNode = LessHead;
		struct ListNode* GreatHead = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* GreatNode = GreatHead;

		while (pHead)
		{
			int num = pHead->val;
			if (num < x)
			{
				LessNode->next = pHead;
				LessNode = LessNode->next;
			}
			else
			{
				GreatNode->next = pHead;
				GreatNode = GreatNode->next;
			}
			pHead = pHead->next;
		}

		LessNode->next = GreatHead->next;
		GreatNode->next = NULL;
		struct ListNode* list = LessHead->next;
		free(LessHead);
		free(GreatHead);
		return list;
	}
};

int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 5;
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 7;
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 4;
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 9;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;
	Partition().partition(n1, 5);
	return 0;
}