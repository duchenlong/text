#define _CRT_SECURE_NO_WARNINGS 
//#pragma warning (disable:4996)
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

#include<stdio.h>
#include<stdlib.h>

void Swap(char* a, char* b)
{
	char t = *a;
	*a = *b;
	*b = t;
}
void Swap1(char* a,char* b)
{
	while (a< b)
	{
		Swap(a, b);
		a+=1;
		b-=1;
	}
}

void Fun(char *a, int len)
{
	int left = 0, right = len - 1;
	char *p1=NULL, *p2=NULL;
	int i=0,num = 0;
	for (i = 0; i < len; i++)
	{
		if (a[i] != ' '&&num == 0)
		{
			num = 1;
			p1 = &a[i];
		}
		if (a[i] == ' '&&num == 1)
		{
			num = 0;
			p2 = &a[i-1];
			Swap1(p1, p2);
		}
	}
	p2 = &a[len - 1];
	Swap1(p1, p2);
}
int main()
{
	char a[20] = "student a am i";
	int len = strlen(a);
	Swap1(a,(a+len-1));
	Fun(a, len);
	puts(a);
	return 0;
}
#if 0
//���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ�
//�����������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
#include<stdio.h>

int Fun(int* a,int len)
{
	int num = 0;
	int left = 0, right = len-1;
	int i = 0, all = 0;
	for (i = 0; i < len; i++)
	{
		all ^= a[i];
	}
	for (i = 0; i < len; i++)
	{
		if ((all^a[i]) == 0)
		{
			num = a[i];
			break;
		}
	}
	return num;
}

int main()
{
	int a[5] = { 1, 2, 1,3, 2 };
	int len = 0;
	len = sizeof(a) / sizeof(a[0]);
	int num = Fun(a,len);
	printf("%d\n", num);
	return 0;
}


//��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��

#include<stdio.h>
int main()
{
	int a = 3, b = 5;
	int t = 0;
	if (a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	int num = b + (a - b) / 2;
	printf("%d\n", num);
	return 0;
}

//��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵ��value�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
#include<stdio.h>
#include<math.h>

unsigned int reverse_bit(unsigned int value)
{
	int i = 0;
	unsigned int num = 0;
	for (i = 0; i <32; i++)
	{
		if (((value >> i) & 1 )== 1)
		{
			num += pow(2, 31-i);
		}
	}
	return num;
}
int main()
{
	int n = 25;
	unsigned int value = 0;
	value=reverse_bit(n);
	printf("%u\n", value);
	return 0;
}
#endif