#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
int main()
{
	void (*p1) ();  //����ָ��
	void (*p2[5])();  //����ָ������
	void ( * (*p3)[5]) ()=&p2;
	//p3��һ��ָ��   ָ��һ������ ����Ϊ5
	//��������ŵ��� void (*)();  ����ָ��

	return 0;
}
#if 0
int add(int a, int b)
{
	return a + b;
}
int sub(int a, int b)
{
	return a - b;
}
int mul(int a, int b)
{
	return a*b;
}
int div(int a, int b)
{
	return a / b;
}

int main()
{
	int input = 1;
	int x = 0;
	int y = 0;
	int ret = 0;
	int (*p[5])(int ,int) = {0,add,sub,mul,div};//p-->����ָ������ ���鳤��Ϊ5
	//  int (*) (int,int);
	while(input) 
	{
		printf("*******************************\n");
		printf("*****1.add********2.sub*******\n");
		printf("*****3.mul********4.dev********\n");
		printf("*********************************\n");
		printf("��������Ĳ�����");
		scanf("%d",&input);
		if(input >= 1 && input <= 4)
		{
			printf("������������������");
			scanf("%d%d",&x,&y);
			ret = (*p[input]) (x,y);//���ú���ָ��
			printf("ret = %d\n",ret);
		}
	}
	return 0;
}

#include<stdio.h>
void text()
{
}
int main()
{
	printf("%p\n", text);
	printf("%p\n", &text);
	return 0;
}

//void printf_p(int p[3][5], int row, int col)
void printf_p(int(*p)[5], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%d ", *(*(p + i) + j));// p[i][j]�൱��*(*(p + i) + j)
		}
		printf("\n");
	}
}
int main()
{
	int a[3][5] = { 1, 2, 3, 4, 5, 6, 7 };
	printf_p(a, 3, 5);
	//��ά�����ڴ��ε�ʱ����������ʾ��һ������Ԫ�صĵ�ַ
	//����������ָ����գ��������һ�еĵ�ַ���н�����
	return 0;
}


int main()
{
	int arr[3] = { 0 };
	printf("%d\n", arr);//������Ԫ�صĵ�ַ
	printf("%d\n", &arr);//��������ĵ�ַ
	printf("%d\n", arr + 1);//����ڶ���Ԫ�صĵ�ַ
	printf("%d\n", &arr + 1);//��ʾ�������һ���ڴ浥Ԫ+1
	return 0;
}


int main()
{
	int* str1 = "hello word";
	int* str2 = "hello word";
	if (str1 == str2)
	{
		printf("str1 = str2\n");
	}
	else
	{
		printf("str1 != str2\n");
	}
	printf("%c", *str1);
	return 0;
}

int main()
{
	int n = 0x1112;
	char* p1 = (char*)&n;
	int *pi = &n;
	*p1 = 0;
	printf("%d,%p,%d", *p1);
	/*int a = 0;
	int* p=&a;
	printf("%p,%p,%d",&a,p,*p);*/
}

#include<stdio.h>
int main()
{
	int a[3][4] = { 0 };
	//char *p = "asdfgh";
	printf("%p,%p", &a[0][0],&a[0][1]);
	return 0;
}
#endif