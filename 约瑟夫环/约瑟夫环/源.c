#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	int position;
	struct node* next;
}node;

node* CreatList(node* l,int n)
{
	
	int i = 0,num=0;
	node* ret, *s;
	ret = (node*)malloc(sizeof(node));
	ret = l;
	ret->next = NULL;
	for (i = 0; i < n; i++)
	{
		printf("请输入第%d个数---->",i+1);
		scanf("%d", &num);
		s = (node*)malloc(sizeof(node));
		s->position = i + 1;
		s->data = num;
		ret->next = s;
		ret = s;
	}
	l = l->next;
	ret->next = l;
	return l;
}

void game(node* l,int n)
{
	printf("m=");
	int m = 0;
	scanf("%d", &m);
	int count = 0;
	node* point;
	point = (node*)malloc(sizeof(node));
	while (l->next!=l)
	{
		if (count < m-1)
		{
			count++;
			point = l;
			l = l->next;
		}
		else
		{
			printf("%d ", l->position);
			count = 0;
			m = l->data;
			node* p;
			p = (node*)malloc(sizeof(node));
			p = l;
			l = l->next;
			point->next = l;
			free(p);
		}
	}
	printf("%d ", l->position);
}

int main()
{
	printf("n=");
	int n = 0;
	scanf("%d", &n);
	node* l;
	l = (node*)malloc(sizeof(node));
	l = CreatList(l,n);
	game(l,n);
	return 0;
}