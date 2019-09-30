#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

#define NUM 10
typedef struct node
{
	int a[NUM];
	int last;
}list;

list* Initlist(list* l)
{
	l->last = 0;
	printf("������:\n");
	for (int i = 0; i < 5; i++)
	{
		scanf("%d", &l->a[i]);
		l->last++;
	}
	return l;
}

list* Hebing(list* l1, list* l2,list* l3)
{
	l3->last = l1->last + l2->last;
	int i = l1->last-1;
	int j = l2->last-1;
	int t = 0;
	while (t<l3->last)
	{
		if ((l1->a[i] > l2->a[j]) || (i != 0 && j == 0))
		{
			l3->a[t] = l1->a[i];
			i--;
		}
		else if ((i == 0 && j != 0) || (l1->a[i] <= l2->a[j]))
		{
			l3->a[t] = l2->a[j];
			j--;
		}
		t++;
	}
	return l3;
}
int main()
{
	list* l1, *l2, *l3;
	l1 = (list*)malloc(sizeof(list));
	l2 = (list*)malloc(sizeof(list));
	l3 = (list*)malloc(sizeof(list));
	l1 = Initlist(l1);
	l2 = Initlist(l2);
	l3 = Hebing(l1, l2, l3);
	for (int i = 0; i < l3->last; i++)
	{
		printf("%d ", l3->a[i]);
	}
	return 0;
}
#if 0
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define NUM 10

typedef struct node
{
	int a[NUM];
	int last;
}node;

node* Initlist(node* l)
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < NUM; i++)
	{
		l->a[i] = rand() % 90 + 10;
		l->last+=1;
	}
	return l;
}

void BianLi(node* l)
{
	for (int i = 0; i < l->last; i++)
	{
		printf("%d ", l->a[i]);
	}
	printf("\n");
}

void Find(node* l)
{
	int n = 0;
	int i = 0;
	printf("��������ҵ�Ԫ��:");
	scanf("%d", &n);
	for (i = 0; i < NUM; i++)
	{
		if (l->a[i] == n)
		{
			printf("%d�ڵ�%d��λ��\n", n, l->last);
			break;
		}
	}
	if (i == NUM)
	{
		printf("û�и�Ԫ�أ�����ʧ��\n");
	}
}
void Delnode(node* l)
{
	int i = 0, n = 0;
	printf("����ɾ����Ԫ��");
	scanf("%d", &n);
	for (i = 0; i <l->last; i++)
	{
		if ((l->a[i] == n)&&(i!=l->last-1))
		{
			l->a[i] = l->a[i + 1];
		}
	}
	l->last--;
	printf("\n");
}

void ChaRu(node* l)
{
	if (l->last == NUM)
	{
		printf("˳������������ܲ���!\n");
	}
	else
	{
		int n = 0, num = 0;
		int i = 0;
		printf("��������Ԫ�غ�λ��\n");
		scanf("%d%d", &n, &num);
		int count = l->last;
		for (i = count; i > num + 1; i--)
		{
			l->a[i + 1] = l->a[i];
		}
		l->a[num - 1] = n;
		count++;
		l->last = count;
	}
}
int main()
{
	node* l;
	l = (node*)malloc(sizeof(node));
	l->last = 0;
	l = Initlist(l);//�����ֵ
	Find(l);//����
	BianLi(l);
	Delnode(l);//ɾ��
	ChaRu(l);//����
	BianLi(l);//����
	return 0;
}
#endif