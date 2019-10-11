#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct stack
{
	char data[MAX];
	int top;
}stack;

void InitStack(stack* l)
{
	l->top = -1;
}

void PushStack(stack* l,char a)
{
	if (l->top== MAX-1)
	{
		return;
	}
	l->data[++l->top] = a;
}

char PopStack(stack* l)
{
	if (l->top < 0)
	{
		return 0;
	}
	char x = l->data[l->top--];
	return x;
}

int main()
{
	stack *l1,*l2;
	char a;
	int count = 1;
	l1 = (stack*)malloc(sizeof(stack));
	l2 = (stack*)malloc(sizeof(stack));
	InitStack(l1);
	while (count)
	{
		do
		{
			a = getchar();
			if (a == '&')
			{
				count = 0;
			}
			PushStack(l1, a);
		} while (a != '@');
		if (count == 1)
		{
			printf("输入不合法，请重新输入\n");
		}
	}
	InitStack(l2);
	a = PopStack(l1);
	while (a != '&')
	{
		a=PopStack(l1);
		PushStack(l2,a);
	}
	PopStack(l2);
	while (l1->top&&l2->top)
	{
		if (PopStack(l1) != PopStack(l2))
		{
			printf("不是回文数\n");
			return 0;
		}
	}
	printf("是回文数\n");
	return 0;
}