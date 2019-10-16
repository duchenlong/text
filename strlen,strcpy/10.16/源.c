#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<string.h>
char* my_strcpy(char* p1, const char* p)
{
	assert(p1);
	assert(p);
	char* p2 = p1;
	//while (*p1++ = *p++);
	do
	{
		*p1 = *p;
		p1++;
		p++;
	} while (*(p-1));
	/*do
	{
		*p1 = *p;
		p1++;
		p++;
	} while (p);*/
	return p2;
}
int main()
{
	char* p = "helloworld";
	//const char* p2 = "hello word";
	/*printf("%d\n", strlen(p));
	printf("%d\n", my_strlen1(p));
	printf("%d\n", my_strlen2(p));*/
	char p1[20];
	printf("%s\n", my_strcpy(p1, p));
	return 0;
}
#if 0
int my_strlen1(const char* str)
{
	assert(str);
	if (*str)
	{
		return 1 + my_strlen1(str + 1);
	}
	return 0;
}
int my_strlen2(const char* str)
{
	const char* end = str;
	while (*end)
	{
		++end;
	}
	return end - str;
}
int main()
{
	char* p = "hello word";
	const char* p2 = "hello word";
	printf("%d\n", strlen(p));
	printf("%d\n", my_strlen1(p));
	printf("%d\n", my_strlen2(p));
	return 0;
}
#endif