#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//回文判断
#define MAX 10
typedef struct 
{
	char a[MAX];
	int last;
}list;

list* Initlist(list* l)
{
	l->a[MAX] = '0';
	l->last = 0;
	return l;
}

list* Enterlist(list* l)
{
	char arr;
	arr = getchar();
	while (arr != '@')
	{
		l->a[l->last] = arr;
		l->last++;
		arr = getchar();
	}
	return l;
}
void PanDuan(list* l)
{
	int i = 0;
	while (l->a[i] != '&')
	{
		i++;
	}
	int left = i-1;
	int right = i+1;
	for (i = 0; i < (l->last / 2); i++)
	{
		if (l->a[left] != l->a[right])
		{
			printf("不是回文数\n");
			break;
		}
		left--;
		right++;
	}
	if (i = (l->last / 2))
	{
		printf("是回文数\n");
	}
}

int main()
{
	list* l;
	l = (list*)malloc(sizeof(list));
	l=Initlist(l);
	l = Enterlist(l);
	PanDuan(l);
	return 0;
}