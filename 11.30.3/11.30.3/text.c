#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>

//Definition for singly-linked list.
 struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
	if (!head || !head->next)
	{
		return head;
	}
	Node* sortHead = (Node*)malloc(sizeof(Node));
	Node* sortprev;
	sortHead->next = head;
	Node* sorttail = sortHead->next;
	head = head->next;
	sorttail->next = NULL;
	while (head)
	{
		Node* headnext = head->next;

		sorttail = sortHead->next;
		sortprev = sortHead;
		while (sorttail && (sorttail->val<head->val))
		{
			sortprev = sorttail;
			sorttail = sorttail->next;
		}
		sortprev->next = head;
		head->next = sorttail;
		head = headnext;
	}
	return sortHead->next;
}

void show(Node* pHead)
{
	while (pHead)
	{
		printf("%d ", pHead->val);
		pHead = pHead->next;
	}
}

int main()
{
	Node* n1 = (Node*)malloc(sizeof(Node));
	n1->val = 2;

	Node* n2 = (Node*)malloc(sizeof(Node));
	n2->val = 1;

	Node* n3 = (Node*)malloc(sizeof(Node));
	n3->val = 4;

	Node* n4 = (Node*)malloc(sizeof(Node));
	n4->val = 3;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;
	show(insertionSortList(n1));
	return  0;
}