#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef int STDataType;
#define MAX 50

typedef struct Stack
{
	STDataType* arr;
	int top;
	int capacity;
}Stack;
// 初始化栈
void StackInit(Stack* ps);
// 入栈
void StackPush(Stack* ps, STDataType data);
// 出栈
void StackPop(Stack* ps);
// 获取栈顶元素
STDataType StackTop(Stack* ps);

int Tonum(char* str)
{
    char* src = str;
    int num = 0;
    if(*str == '-' || *str == '+')
    {
        src++;
    }
    while(*src)
    {
        num = num * 10 + *src - '0';
        src++;
    }
    if(*str == '-')
    {
        num = 0 - num;
    }
    return num;
}
// 初始化栈
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

// 入栈
void StackPush(Stack* ps, STDataType data)
{
	//assert(ps && data);

	if (ps->top == ps->capacity)
	{
		AddCapacity(ps);
	}

	ps->arr[ps->top++] = data;
}
// 出栈
void StackPop(Stack* ps)
{
	assert(ps);

	if (ps->top == 0)
	{
		return;
	}

	ps->top--;
}
// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
	assert(ps);

	return ps->arr[ps->top - 1];
}

int cmp(int n,int m,char ch)
{
    switch(ch)
    {
        case '+':
        {
            return n + m;
        }
        case '-':
        {
            return n - m;
        }
        case '*':
        {
            return n * m;
        }
        case '/':
        {
            return n / m;
        }
    }
    return -1;
}

int evalRPN(char tokens[][10], int tokensSize){
    int i = 0;
    Stack* st = (Stack*)malloc(sizeof(Stack));
    StackInit(st);

    for(i = 0; i < tokensSize; i++)
    {
        if((tokens[i][0]>='0' && tokens[i][0]<='9') || (strlen(tokens[i]) > 1))
        {
            int num = Tonum(tokens[i]);
            StackPush(st,num);
        }
        else
        {
            int n = StackTop(st);
            StackPop(st);
            int m = StackTop(st);
            StackPop(st);
            int num = cmp(m,n,tokens[i][0]);
            StackPush(st,num);
        }
        
    }
    return StackTop(st);
}

int main()
{
	///char** str = {{"10"},{"6"},{"9"},{"3"},{"+"},{"-11"},{"*"},{"/"},{"*"},{"17"},{"+"},{"5"},{"+"}};
	char str[][10] = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
	int len = 13;
	printf("%d\n",evalRPN(str,len));
	return 0;
}
