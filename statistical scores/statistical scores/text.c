#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_N 20
#define MAX_T 20
#define  MAX 50

typedef struct Score
{
	char _name[MAX_N];
	char _num[MAX_T];
	int _score;
}Score;

typedef struct List
{
	Score* _arr;
	int _size;
	int _capacity;
}List;

//初始化
void ListInit(List* pl)
{
	pl->_capacity = MAX;
	pl->_arr = (Score*)malloc(sizeof(Score)*pl->_capacity);
	pl->_size = 0;
}
//扩容
void AddCapacity(List* pl)
{
	pl->_capacity *= 2;
	pl->_arr = (Score*)realloc(pl->_arr, sizeof(Score)*pl->_capacity);
}

//输入信息
void ListPush(List* pl)
{
	if (pl->_size == pl->_capacity)
	{
		AddCapacity(pl);
	}

	printf("学生姓名：");
	scanf("%s", pl->_arr[pl->_size]._name);
	printf("学生学号：");
	scanf("%s", pl->_arr[pl->_size]._num);
	printf("学生分数：");
	scanf("%d", &pl->_arr[pl->_size]._score);

	pl->_size++;
}

int Judge(List* pl, int after, int before)
{
	if (pl->_arr[after]._score > pl->_arr[before]._score)
	{
		return 1;
	}
	
	if (pl->_arr[after]._score == pl->_arr[before]._score)
	{
		return strcmp(pl->_arr[after]._num, pl->_arr[before]._num);
	}
	return 0;
	
}

void Swap(List* pl, int after, int before)
{
	char name[MAX_N] = { 0 }, num[MAX_T] = { 0 }, tmp = 0;
	strcpy(name, pl->_arr[after]._name);
	strcpy(pl->_arr[after]._name, pl->_arr[before]._name);
	strcpy(pl->_arr[before]._name, name);

	strcpy(num, pl->_arr[after]._num);
	strcpy(pl->_arr[after]._num, pl->_arr[before]._num);
	strcpy(pl->_arr[before]._num, num);

	tmp=pl->_arr[after]._score;
	pl->_arr[after]._score= pl->_arr[before]._score;
	pl->_arr[before]._score=tmp;
}

//排序
void Sort(List* pl)
{
	int i = 0;
	for (i = 0; i < pl->_size-1; i++)
	{
		int j = 0;
		for (j = 0; j < pl->_size - i - 1; j++)
		{
			if (Judge(pl, j, j + 1)==1)
			{
				Swap(pl, j, j + 1);
			}
		}
	}
}

int main()
{
	List* list = (List*)malloc(sizeof(List));
	ListInit(list);
	int n = 0;
	int i = 0;
	printf("请输入学生数量-->  ");
	scanf("%d", &n);
	while (i != n)
	{
		printf("请输入第 %d 个同学信息 -->\n",i+1);
		ListPush(list);
		i++;
	}
	
	//排序
	Sort(list);

	for (i = 0; i < list->_size; i++)
	{
		printf("%s\t%s\t%d\n", list->_arr[i]._name,list->_arr[i]._num,list->_arr[i]._score);
	}
	return 0;
}