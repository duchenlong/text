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

//ջ
void InitStack(Stack* s);
void PushStack(Stack* s, char* Pdata);
BinaryTree* PopStack(Stack* s);

//��
void InitTree(BinaryTree* root);
void InputTree(BinaryTree* root);

//�ݹ�
void PreOrder(BinaryTree* root);//����
void InOrder(BinaryTree* root);//����
void PostOrder(BinaryTree* root);//����

//�ǵݹ�
void _PreOrder(BinaryTree* root, Stack* s);//����
void _InOrder(BinaryTree* root, Stack* s);//����
void _PostOrder(BinaryTree* root, Stack* s);//����