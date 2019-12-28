#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
	char data;
	struct tree* lchild;
	struct tree* rchild;
}tree;

void TreeInit(tree* root)
{
	root->data = '\0';
	root->lchild = root->rchild = NULL;
}

void TreeCreat(tree* root)
{
	char ch = '\0';
	scanf("%c", &ch);
	if (ch == '#'||ch=='\n')
	{
		return;
	}
	root->data = ch;
	root->lchild = (tree*)malloc(sizeof(tree));
	TreeInit(root->lchild);
	TreeCreat(root->lchild);

	root->rchild = (tree*)malloc(sizeof(tree));
	TreeInit(root->rchild);
	TreeCreat(root->rchild);
}

void InPrintf(tree* root)
{
	if (root->data=='\0')
	{
		return;
	}
	InPrintf(root->lchild);
	printf("%c ", root->data);
	InPrintf(root->rchild);
}

int main()
{
	tree* root;
	root = (tree*)malloc(sizeof(tree));
	TreeInit(root);
	TreeCreat(root);

	InPrintf(root);
}