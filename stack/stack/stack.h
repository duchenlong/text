#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;
#define MAX 50

typedef struct Stack
{
	STDataType* arr;
	STDataType top;
	STDataType capacity;
}Stack;

// 初始化栈
void StackInit(Stack* ps);
// 入栈
void StackPush(Stack* ps, STDataType data);
// 出栈
void StackPop(Stack* ps);
// 获取栈顶元素
STDataType StackTop(Stack* ps);
// 获取栈中有效元素个数
int StackSize(Stack* ps);
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps);
// 销毁栈
void StackDestroy(Stack* ps);

//打印栈
void StackPrintf(Stack* ps);