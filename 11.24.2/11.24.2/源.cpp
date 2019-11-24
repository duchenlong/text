#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) : val(x), next(NULL) {}
};

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		if (!A)
		{
			return false;
		}
		struct ListNode* slow = A;
		struct ListNode* fast = A;
		struct ListNode* node;
		struct ListNode* n1=NULL;
		struct ListNode* n2 = NULL;
		struct ListNode* n3 = NULL;
		if (!A->next)
		{
			return false;
		}
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		node = slow;

		n1 = slow;

		if (n1)
		{
			n2 = n1->next;
			if (n2)
			{
				n3 = n2->next;
			}
		}
		while (n2)
		{
			n2->next = n1;
			n1 = n2;
			n2 = n3;
			if (n3)
			{
				n3 = n3->next;
			}
		}

		while (A != slow)
		{
			if (A->val != n1->val)
			{
				return false;
			}
			A = A->next;
			n1 = n1->next;
		}
		return true;
	}
};

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
	n5->val =2;
	 struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n6->val = 1;
	/*struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
	n7->val = 4;*/
	 n1->next = n2;
	 n2->next = n3;
	 n3->next = n4;
	n4->next = n5;
	 n5->next = n6;
	//n6->next = n7;
	 n6->next = NULL;
	printf("%d",PalindromeList().chkPalindrome(n1));
   return 0; 
}