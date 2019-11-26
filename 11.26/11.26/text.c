#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


//Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	int lenA = 0, lenB = 0;
	int i = 0;
	struct ListNode* NodeA = headA;
	struct ListNode* NodeB = headB;
	if (!headA || !headB)
	{
		return NULL;
	}
	while (NodeA)
	{
		lenA++;
		NodeA = NodeA->next;
	}
	while (NodeB)
	{
		lenB++;
		NodeB = NodeB->next;
	}
	if (lenA<lenB)
	{
		for (i = 0; i<lenB - lenA; i++)
		{
			headB = headB->next;
		}
	}
	else
	{
		for (i = 0; i<lenA - lenB; i++)
		{
			headA = headA->next;
		}
	}
	while (headA != headB)
	{
		headA = headA->next;
		headB = headB->next;
	}
	if (headA == headB)
	{
		return headA;
	}
	else
	{
		return NULL;
	}
}

int main()
{
	struct ListNode* A;
	struct ListNode* B;
	A = (struct ListNode*)malloc(sizeof(struct ListNode));
	B = (struct ListNode*)malloc(sizeof(struct ListNode));

	struct ListNode* a1;
	a1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	a1->val = 1;

	struct ListNode* a2;
	a2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	a2->val = 2;

	struct ListNode* a3;
	a3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	a3->val = 3;

	a1->next = a2;
	a2->next = a3;
	a3->next = NULL;

	struct ListNode* b1;
	b1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	b1->val = 4;

	struct ListNode* b2;
	b2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	b2->val = 5;

	struct ListNode* b3;
	b3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	b3->val = 6;

	struct ListNode* b4;
	b4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	b4->val = 2;

	struct ListNode* b5;
	b5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	b5->val = 7;
	b1->next = b2;
	b2->next = b3;
	b3->next = b4;
	b4->next = a2;
	struct ListNode* c;
	c = (struct ListNode*)malloc(sizeof(struct ListNode));
	c= getIntersectionNode(a1, b1);

	printf("%d\n",c->val);
}