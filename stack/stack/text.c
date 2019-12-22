#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"

// ��ʼ��ջ
void StackInit(Stack* ps)
{
	assert(ps);

	ps->capacity = MAX;
	ps->arr = (STDataType*)calloc(ps->capacity,sizeof(STDataType));
	ps->top = 0;
}

void AddCapacity(Stack* ps)
{
	assert(ps);

	ps->capacity *= 2;
	ps->arr = (STDataType*)realloc(ps->arr, sizeof(STDataType)*ps->capacity);
}

// ��ջ
void StackPush(Stack* ps, STDataType data)
{
	assert(ps && data);

	if (ps->top == ps->capacity)
	{
		AddCapacity(ps);
	}

	ps->arr[ps->top++] = data;
}
// ��ջ
void StackPop(Stack* ps)
{
	assert(ps);

	if (ps->top == 0)
	{
		return;
	}

	ps->top--;
}
// ��ȡջ��Ԫ��
STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->arr[ps->top - 1];
}

// ��ȡջ����ЧԪ�ظ���
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0 ? 1 : 0;
}

// ����ջ
void StackDestroy(Stack* ps)
{
	assert(ps);

	ps->top = 0;
}

void StackPrintf(Stack* ps)
{
	assert(ps);

	int i = 0;
	for (i = 0; i < ps->top; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
}

int main()
{
	Stack* s;
	s = (Stack*)malloc(sizeof(Stack));
	StackInit(s);
	StackPush(s,1);
	/*StackPush(s, 2);
	StackPush(s, 3);
	StackPush(s, 4);
	StackPush(s, 5);
	StackPush(s, 6);
	StackPush(s, 7)*/;
	StackPop(s);
    printf("%d\n",StackTop(s));
	printf("%d\n", StackSize(s));
    printf("%d\n",StackEmpty(s));
	StackPrintf(s);
    StackDestroy(s);
	return 0;
}