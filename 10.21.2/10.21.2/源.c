#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�

#include<stdio.h>

void find(const int* a, const int size)
{
	int i = 0;
	int count = 0;
	int flag = 0;
	int num1= 0;
	int num2 = 0;
	for (i = 0; i < size; i++)
	{
		count ^= a[i];
	}
	for (i = 1; i <= 32; i++)
	{
		if ((count >> i) & 1 != 1)
		{
			flag=i;
		}
		else
		{
			break;
		}
	}
	for (i = 0; i < size; i++)
	{
		if (((a[i] >> flag)&1) == 1)
		{
			num1 ^= a[i];
		}
		else
		{
			num2 ^= a[i];
		}
	}
	printf("%d %d\n", num1, num2);
}

int main()
{
	int a[] = { 1,1,2,2,3,4,5,5 };
	int size = sizeof(a) / sizeof(a[0]);
	find(a, size);
	return 0;
}

#endif

#if 0
/*.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
��20Ԫ�����Զ�����ˮ��
���ʵ�֡�*/

#include<stdio.h>

int main()
{
	int much = 20;
	int pop = 0;
	int bottle =much;
	int count = 0;
	while (bottle >1)
	{
		pop += bottle;
		if (bottle % 2 != 0)
		{
			bottle = bottle / 2+count;
			count = 1;
		}
		else
		{
			bottle = bottle / 2 + count;
			count = 0;
		}
	}
	printf("%d\n", pop);
	return 0;
}
#endif


//ģ��ʵ��strcpy

#include<stdio.h>
#include<string.h>

char* my_strcpy(char* str1, const char*str2)
{
	char* src = str1;
	//while ((*str1++ = *str2++));
	/*do
	{
		*str1 = *str2;
		str1++;
	} while (*(++str2));*/
	while (*str2)
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return src;
}

int main()
{
	char a[] = "hello word";
	char b[20]="hello";
	printf("%s\n", strcpy(b, a));
	printf("%s\n", my_strcpy(b, a));
	return 0;
}



#if 0
//ģ��ʵ��strcat

#include<stdio.h>
#include<string.h>

char* my_strcat(char* str1, const char* str2)
{
	char* src = str1;
	while (*src)
	{
		src++;
	}
	while ((*src++ = *str2++));
	return str1;
}

int main()
{
	char a[20] = "hello";
	char b[10] = " word";
	printf("%s\n", strcat(a,b));
	char d[20] = "hello";
	char c[10] = " word";
	printf("%s\n", my_strcat(d,c));
	return 0;
}
#endif