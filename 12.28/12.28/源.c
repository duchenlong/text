#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

char a[10000][100] = { 0 };

typedef struct Stack
{
	int* arr;
	int top;
	int capacity;
}Stack;

void StackInit(Stack* st)
{
	st->top = 0;
	st->capacity = 1;
	st->arr = (int*)malloc(sizeof(Stack)*st->capacity);
}

void StackPush(Stack* st, int x)
{
	if (st->top == st->capacity)
	{
		st->capacity *= 2;
		st->arr = (int*)realloc(st->arr, sizeof(int)*st->capacity);
	}

	st->arr[st->top++] = x;
}

void StackPop(Stack* st)
{
	if (st->top == 0)
	{
		return;
	}

	st->top--;
}

int StackTop(Stack* st)
{

	return st->arr[st->top-1];
}

int StackEmoty(Stack* st)
{
	return st->top == 0 ? 1 : 0;
}

int main()
{

	Stack* st = (Stack*)malloc(sizeof(Stack));
	int n = 1;
	int ans = 0;
	scanf("%d", &n);
	while (n != 0)
	{
		getchar();
		StackInit(st);
		int i = 0;
		int num = 0;
		for (i = 0; i < n; i++)
		{
			
			char ch = getchar();
			getchar();
			if (ch == 'A')
			{
				if (StackEmoty(st) == 1)
				{
					a[ans][num++] = 'E';
				}
				else
				{
					a[ans][num++] = StackTop(st)+'0';
				}
			}
			else if (ch == 'P')
			{
				int count = 0;
				scanf("%d", &count);
				StackPush(st, count);
				char b=getchar();
			}
			else if (ch == 'O')
			{
				getchar();
				if (StackEmoty(st) == 1)
				{
					continue;
				}
				StackPop(st);
			}
		}
		ans++;
		scanf("%d", &n);
	}

	int i = 0;
	for (i = 0; i < ans; i++)
	{
		int j = 0;
		while (a[i][j] != '\0')
		{
			printf("%c\n", a[i][j]);
			j++;
		}
		printf("\n");
	}

	return 0;
}