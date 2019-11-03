#define _CRT_SECURE_NO_WARNINGS 1

//Ä£ÄâÊµÏÖstrncpy
#if 0
#include<stdio.h>

char* my_strncpy(char* a, const char* b,const size_t size)
{
	size_t i = 0;
	for (i = 0; i < size; i++)
	{
		a[i] = b[i];
	}
	return a;
}

int main()
{
	char a[10] = "worlo";
	char b[10] = "helld";
	my_strncpy(a, b, 3);
	//strncpy(a, b, 8);
	puts(a);
	return 0;
}
#endif

//strncat
#if 0
#include<stdio.h>

char* my_strncat(char* str1, const char* str2, const size_t num)
{
	char* src = str1;
	while (*str1)
	{
		str1++;
	}
	for (size_t i = 0; i < num; i++)
	{
		*(str1 + i) = *(str2 + i);
	}
	return src;
}

int main()
{
	char a[20] = "hello ";
	char b[10] = "world";
	my_strncat(a, b, 0);
	//strncat(a, b, 3);
	puts(a);
	return 0;
}
#endif

//strncmp
#include<stdio.h>

int my_strncmp(const char* str1, const char* str2, const size_t num)
{
	size_t i = 0;
	for (i = 0; i < num; i++)
	{
		if (*(str1 + i) > *(str2 + i))
		{
			return 1;
		}
		else if (*(str1 + i) < *(str2 + i))
		{
			return -1;
		}
	}
	return 0;
}
int main()
{
	char a[10] = "hello";
	char b[10] = "helld";
	printf("%d", my_strncmp(a,b,2));
	return 0;
}