#define _CRT_SECURE_NO_WARNINGS 1
//ѭ���������в�����ĸ��һ�γ��ֵ�λ��
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
	printf("��������ĸ:\n");
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
			printf("%c��һ�γ��ֵ�λ����%d\n", n, i/2 +1);
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
	printf("����Ҫ���ҵ���ĸ:\n");
	scanf("%c", &n);
	Get(l, n);
	return 0;
}
#if 0
//����һ��˳�����10λͬѧ����Ϣ��ѧ�ţ��༶��������,���������λͬѧ��Ϣ
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
		printf("�����%dλͬѧѧ��\n",i+1);
		scanf("%s", l->stu[i].id);
		printf("�����%dλͬѧ����\n", i + 1);
		scanf("%s", l->stu[i].name);
		printf("�����%dλͬѧ�༶\n", i + 1);
		scanf("%d", &l->stu[i].number);
		system("cls");
		l->last++;
	}
}

void Locate(list l, int n)
{
	if (n > l.last || n < 0)
	{
		printf("û����λͬѧ��Ϣ!\n");
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
	printf("����Ҫ��ѯ�ĵڼ�λѧ����Ϣ��\n");
	scanf("%d", &n);
	Locate(l, n-1);
	return 0;
}
#endif