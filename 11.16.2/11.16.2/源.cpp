#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>


struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};

class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (!pHead)
		{
			return pHead;
		}
		struct ListNode* before = pHead;
		struct ListNode* curhead = (struct ListNode*)malloc(sizeof(struct ListNode));
		struct ListNode* cur = curhead;
		struct ListNode* src = pHead->next;
		while (before)
		{
			if (!src)
			{
				cur->next = before;
				before = before->next;
			}
			else if (src->val != before->val)
			{
				cur->next = before;
				cur = cur->next;
				
				before = before->next;
				src = src->next;
			}
			else
			{
				int num = before->val;
				while (src&&src->val == num)
				{
					
					src = src->next;
				}
				if (!src)
				{
					cur->next = NULL;
					return curhead->next;
				}
				before = src;
				src = src->next;
			}
		}
		return curhead->next;
	}
};


void Show(struct ListNode* n)
{
	while (n)
	{
		printf("%d->", n -> val);
		n = n->next;
	}
}
int main()
{
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n1->val = 1;
	struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n2->val = 2;
	struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n3->val = 3;
	struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n4->val = 3;
	struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n5->val = 4;
	struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n6->val = 4;
	struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n7->val = 4;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = NULL;
	Show(Solution().deleteDuplication(n1));
	return 0;
}