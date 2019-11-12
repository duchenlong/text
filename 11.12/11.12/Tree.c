#define _CRT_SECURE_NO_WARNINGS 1

#include"Tree.h"

//ջ
void InitStack(Stack* s)
{
	assert(s);
	s->_top = 0;
}

void PushStack(Stack* s, BinaryTree* P)
{
	assert(s);
	s->_stackdata[s->_top++] = P;
}

BinaryTree* PopStack(Stack* s)
{
	assert(s);
	BinaryTree* n = s->_stackdata[--s->_top];
	return n;
}
BinaryTree* GetStack(Stack* s)
{
	assert(s);
	BinaryTree* n = s->_stackdata[s->_top-1];
	return n;
}
//��
void InitTree(BinaryTree* root)
{
	assert(root);
	root->data = '\0';
	root->leftchild = root->rightchild = NULL;
}
//����Ԫ��
void InputTree(BinaryTree* root)
{
	assert(root);
	char letter;
	scanf("%c", &letter);
	root->data = letter;
	if (letter == ' ')
	{
		return;
	}
	root->leftchild = (BinaryTree*)malloc(sizeof(BinaryTree));
	InitTree(root->leftchild);
	InputTree(root->leftchild);
	root->rightchild = (BinaryTree*)malloc(sizeof(BinaryTree));
	InitTree(root->rightchild);
	InputTree(root->rightchild);
}

//�ݹ��������
void PreOrder(BinaryTree* root)
{
	assert(root);

	if (root->data == ' ')
	{
		return;
	}
	printf("%c", root->data);
	PreOrder(root->leftchild);
	PreOrder(root->rightchild);
}
//�ݹ��������
void InOrder(BinaryTree* root)
{
	assert(root);

	if (root->data == ' ')
	{
		return;
	}
	InOrder(root->leftchild);
	printf("%c", root->data);
	InOrder(root->rightchild);
}
//�ݹ�������
void PostOrder(BinaryTree* root)
{
	assert(root);

	if (root->data == ' ')
	{
		return;
	}
	PostOrder(root->leftchild);
	PostOrder(root->rightchild);
	printf("%c", root->data);
}
//�ǵݹ��������
void _PreOrder(BinaryTree* root, Stack* s)
{
	assert(s&&root);
	InitStack(s);
	BinaryTree* p = root;
	while (p != NULL || s->_top != 0)
	{
		if (p != NULL)
		{
			PushStack(s, p);
			if (p->data != ' ')
			{
				printf("%c", p->data);
			}
			p = p->leftchild;
		}
		else
		{
			p = PopStack(s);
			p = p->rightchild;
		}
	}
}
//�ǵݹ��������
void _InOrder(BinaryTree* root,Stack* s)
{
	assert(s&&root);
	InitStack(s);
	BinaryTree* p = root;
	while (p!= NULL || s->_top != 0)
	{
		if (p!= NULL)
		{
			PushStack(s, p);
			p = p->leftchild;
		}
		else
		{
			p = PopStack(s);
			if (p->data != ' ')
			{
				printf("%c", p->data);
			}
			p=p->rightchild;
		}
	}
}
//�ǵݹ�������
void _PostOrder(BinaryTree* root, Stack* s)
{
	assert(s&&root);
	InitStack(s);
	BinaryTree* p = root;
	BinaryTree* q = NULL;
	while (p != NULL || s->_top != 0)
	{
		if (p != NULL)
		{
			PushStack(s, p);
			p = p->leftchild;
		}
		else
		{
			p = GetStack(s);
			if ((p->rightchild == NULL) || (p->rightchild == q))
			{
				if (p->data != ' ')
				{
					printf("%c", p->data);
				}
				q = p;
				p = PopStack(s);
				p = NULL;
			}
			else
			{
				p = p->rightchild;
			}
		}
	}
}
