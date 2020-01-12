#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node* next;
	struct node* prev;
}node;

node* a[100005] = {0};

void Initlist(node* phead)
{
	phead->prev = phead->next = phead;
}

void Insertleft(node* phead,int val,int x)
{
	node* n = a[val];
	node* prev = n->prev;
	node* nod = (node*)malloc(sizeof(node));
	nod->val = x;
	
	prev->next = nod;
	nod->prev = prev;
	
	nod->next = n;
	n->prev = nod;
	a[x] = nod;
}

void Insertright(node* phead,int val,int x)
{
	node* n = a[val];
	node* next = n->next;
	node* nod = (node*)malloc(sizeof(node));
	nod->val = x;
	
	n->next = nod;
	nod->prev = n;
	
	next->prev = nod;
	nod->next = next;
	a[x] = nod;
}

int main()
{
	node* head = (node*)malloc(sizeof(node));
	Initlist(head);
	node* nod = (node*)malloc(sizeof(node));
	int n;
	scanf("%d",&n);
	int first;
	scanf("%d",&first);
	nod->val = first;
	head->next = nod;
	nod->prev = head;
	
	head->prev = nod;
	nod->next = head;
	a[nod->val] = nod;
	int i = 0;
	int a,b,c;
	for(i = 0; i < n - 1; i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(c)
		{
			Insertright(head,b,a);
		}
		else
		{
			Insertleft(head,b,a);
		}
	}
	
	for(i = 0;i < n;i++)
	{
		printf("%d ",head->next->val);
		head = head->next;
	}
	
	return 0; 
}
