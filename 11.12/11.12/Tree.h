#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX 50

typedef struct BinaryTree
{
	char data;
	struct BinaryTree* leftchild;
	struct BinaryTree* rightchild;
}BinaryTree;

typedef struct Stack
{
	int _top;
	BinaryTree* _stackdata[MAX];
}Stack;

//’ª
void InitStack(Stack* s);
void PushStack(Stack* s, char* Pdata);
BinaryTree* PopStack(Stack* s);

// ˜
void InitTree(BinaryTree* root);
void InputTree(BinaryTree* root);

//µ›πÈ
void PreOrder(BinaryTree* root);//œ»–Ú
void InOrder(BinaryTree* root);//÷––Ú
void PostOrder(BinaryTree* root);//∫Û–Ú

//∑«µ›πÈ
void _PreOrder(BinaryTree* root, Stack* s);//œ»–Ú
void _InOrder(BinaryTree* root, Stack* s);//÷––Ú
void _PostOrder(BinaryTree* root, Stack* s);//∫Û–Ú