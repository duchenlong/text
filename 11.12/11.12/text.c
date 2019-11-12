#define _CRT_SECURE_NO_WARNINGS 1

#include"Tree.h"

//µ›πÈ¥Ú”°
void RecursiveShowTree(BinaryTree* root)
{
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
}
//∑«µ›πÈ¥Ú”°
void NoRecursiveShowTree(BinaryTree* root,Stack* s)
{
	_PreOrder(root,s);
	printf("\n");
	_InOrder(root,s);
	printf("\n");
	_PostOrder(root,s);
	printf("\n");
}

int main()
{
	BinaryTree* root;
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));
	root = (BinaryTree*)malloc(sizeof(BinaryTree));
	InitTree(root);
	InputTree(root);
	printf("∑«µ›πÈ±È¿˙\n");
	NoRecursiveShowTree(root,s);
	printf("µ›πÈ±È¿˙\n");
	RecursiveShowTree(root);
	return 0;
}