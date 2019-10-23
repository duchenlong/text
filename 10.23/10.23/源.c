#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
}Node;

//前序遍历
void preorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
}
//中序遍历
void inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}
//后序遍历
void postorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}

Node* buyNode(int val)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->left = node->right;
	return node;
}

void Test()
{
	Node* a = buyNode(1);
	Node* b = buyNode(2);
	Node* c = buyNode(3);
	Node* d = buyNode(4);
	Node* e = buyNode(5);
	Node* f = buyNode(6);
	Node* g = buyNode(7);
	a->left = b;
	a->right = c;
	b->left = NULL;
	b->right = NULL;
	c->left = d;
	c->right = f;
	d->left = NULL;
	d->right = e;
	f->left = NULL;
	f->right = g;
	e->right = e->left = NULL;
	g->right = g->left = NULL;
	preorder(a); 
	printf("\n");
	inorder(a);
	printf("\n");
	postorder(a);
}

int main()
{
	Test();
	return 0;
}

