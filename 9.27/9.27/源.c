#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#define MAX 10

typedef struct
{
	int a[MAX];
	int front;
	int rear;
}SeqQueue;

void InitQueue(SeqQueue* l)
{
	l->front = l->rear=0;
}

int  PanDuan(SeqQueue* l,int* tag)
{
	if ((l->front == l->rear) && (*tag == 1))
	{
		printf("��������\n");
		return 2;
	}
	if ((l->front == l->rear) && (*tag == 0))
	{
		printf("����Ϊ��\n");
		return 1;
	}
	return 0;
}

SeqQueue* EnterQueue(SeqQueue* l,int* tag)
{
	int i=PanDuan(l, *(&tag));
	if (i !=2)
	{
		scanf("%d",& (l->a[l->rear]));
		l->rear = (l->rear + 1) % MAX;
		*tag = 1;
	}	
	return l;
}

SeqQueue* DeleteQueue(SeqQueue* l, int* tag)
{
	int i = PanDuan(l, *(&tag));
	if (i != 1)
	{
		l->front = (l->front + 1) % MAX;
		if (l->front==l->rear)
		{
			*tag= 0;
		}
	}
	return l;
}

int main()
{
	SeqQueue* l;
	l = (SeqQueue*)malloc(sizeof(SeqQueue));
	InitQueue(l);
	int tag = 0;
	int i = 0;
	printf("���������Ԫ�أ�");
	while (i < 10)
	{
		l = EnterQueue(l, &tag);
		i++;
	}
	/*while (i >=0)
	{*/
		l = DeleteQueue(l, &tag);
		/*i--;
	}*/
	printf("hahah");
	int num = 0;
	if (PanDuan(l,&tag)==2)
	{
		num = MAX;
	}
	else
	{
		num = MAX-;
	}
	for (i = l->front; i <num; i++)
	{
		printf("%d ", l->a[i]);
	}
	return 0;
}

#if 0
void pr()
{
	char ch;
	scanf("%c", &ch);
	if (ch != '#')
	{
		pr();
	}
	printf("%c", ch);
}
int main()
{
	pr();
	return 0;
}





int main()
{
	unsigned char i = 0;//i���޷���char����
	for (i = 0; i < 255; i++)
	{
		printf("hello word\n");
	}
	return 0;
}

#include<Windows.h>
int main()
{
	unsigned int i;//i���з�������
	for (i = 9; i >= 0; i--)
	{
		Sleep(100);
		printf("%u\n", i);
	}
	return 0;
}
#endif
//#include<stdio.h>
//union uu//���Ͻṹ��
//{
//	int i;
//	char a;
//};//�ص㣺i��a����һ���ڴ�
//int CheakSys()
//{
//	union uu un;
//	un.i = 20;
//	return un.a;
//}
//int main()
//{
//	int ret = CheakSys();
//	if (ret == 0x14)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}