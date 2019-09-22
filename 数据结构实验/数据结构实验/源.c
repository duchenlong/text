#define _CRT_SECURE_NO_WARNINGS 1
//循环单链表中查找字母第一次出现的位置
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char data;
	struct node* next;
}list;

list Initlist(list* l)
{
	list* head,*p;
	head = (list*)malloc(sizeof(list));
	head = l;
	int i = 0;
	char a;
	printf("请输入字母:\n");
	for (i = 0; i < 20;i++)
	{
		
		p = (list*)malloc(sizeof(list));
		a= getchar();
		p->data = a;
		head->next = p;
		head = p;
	}
	head->next=l;
	return *l;
}

void Get(list* l, char n)
{
	int i = 0;
	for (i = 0; i < 20; i++)
	{
		if (l->data == n)
		{
			printf("%c第一次出现的位置是%d\n", n, i/2 +1);
			break;
		}
		l = l->next;
	}
}
int main()
{
	list* l;
	l = (list*)malloc(sizeof(list));
	l->next = NULL;
	*l=Initlist(l);
	char n;
	printf("输入要查找的字母:\n");
	scanf("%c", &n);
	Get(l, n);
	return 0;
}
#if 0
//建立一个顺序表存放10位同学的信息（学号，班级，姓名）,并输出第五位同学信息
#include<stdio.h>
#include<stdlib.h>

#define NUM 10

typedef struct
{
	char id[20];
	char name[20];
	int number;
}student;

typedef struct
{
	student* stu;
	int last;
}list;

void InitList(list* l)
{
	int i = 0;
	for (i = 0; i < NUM; i++)
	{
		printf("输入第%d位同学学号\n",i+1);
		scanf("%s", l->stu[i].id);
		printf("输入第%d位同学姓名\n", i + 1);
		scanf("%s", l->stu[i].name);
		printf("输入第%d位同学班级\n", i + 1);
		scanf("%d", &l->stu[i].number);
		system("cls");
		l->last++;
	}
}

void Locate(list l, int n)
{
	if (n > l.last || n < 0)
	{
		printf("没有这位同学信息!\n");
	}
	else
	{
		printf("%s,%s,%d\n", l.stu[n].id, l.stu[n].name, l.stu[n].number);
	}
}
int main()
{
	list l;
	l.stu = (student*)malloc(sizeof(student));
	l.last = 0;
	InitList(&l);
	int n = 0;
	printf("输入要查询的第几位学生信息：\n");
	scanf("%d", &n);
	Locate(l, n-1);
	return 0;
}
#endif