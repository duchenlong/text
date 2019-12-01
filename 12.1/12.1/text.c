#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>

typedef struct TreeNode 
{
	int data;
	struct TreeNode* lchild;
	struct TreeNode* rchild;
}TreeNode;

void InitTree(TreeNode* pr)
{
	pr->data = 0;
	pr->lchild = pr->rchild = NULL;
}

void InsertTree(TreeNode** pr, int key)
{
	TreeNode* node;
	node = (TreeNode*)malloc(sizeof(TreeNode));
	InitTree(node);
	if (!*pr)
	{
		node->data = key;
		*pr = node;
	}
	else if (key < (*pr)->data)
	{
		InsertTree(&(*pr)->lchild, key);
	}
	else
	{
		InsertTree(&(*pr)->rchild, key);
	}
}

void CreatTree(TreeNode** pr)
{
	int key = 0;
	scanf("%d", &key);
	while (key != 0)
	{
		InsertTree(&(*pr), key);
		scanf("%d", &key);
	}
}

void SearchTree(TreeNode* pr,int key)
{
	if (!pr)
	{
		printf("no find\n");
		return;
	}
	if (pr->data == key)
	{
		printf("key is root\n");
	}
	if (pr->lchild || pr->rchild)
	{
		if (pr->lchild&&pr->lchild->data == key)
		{
			printf("key is left\n");
			return;
		}	
		else if (pr->rchild&&pr->rchild->data == key)
		{
			printf("key id right\n");
			return;
		}
	}
	if (pr->data > key)
	{
		SearchTree(pr->lchild,key);
	}
	else if (pr->data < key)
	{
		SearchTree(pr->rchild, key);
	}
}

int main()
{
	TreeNode* root=NULL;
	int key;
	//root = (TreeNode*)malloc(sizeof(TreeNode));
	//InitTree(root);
	CreatTree(&root);
	scanf("%d", &key);
	SearchTree(root, key);
	return 0;
}