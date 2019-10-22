#define _CRT_SECURE_NO_WARNINGS 1

//实现strcpy

#if 0
#include<stdio.h>

char* my_strcpy(char* str1, const char* str2)
{
	char* src = str1;
	while ((*str1++ = *str2++));
	return src;
}

int main()
{
	char a[] = "good morning";
	char b[20] = "hello";
	my_strcpy(b, a);
	puts(b);
	return 0;
}
#endif

#if 0
//实现strcat
#include<stdio.h>

char* my_strcat(char* str1, const char* str2)
{
	char* src = str1;
	while (*str1++);
	str1--;
	while ((*str1++ = *str2++));
	return src;
}

int main()
{
	char a[20] = "good";
	char b[] = " morning";
	my_strcat(a, b);
	puts(a);
	return 0;
}

#endif
//实现strstr

#if 0
#include<stdio.h>

char* my_strstr(const char* str1, const char* str2)
{
	const char* src = str1;
	const char* sub = str2;
	const char* stact = str1;
	while (*src)
	{
		if (*src == *sub)
		{
			src++;
			sub++;
		}
		else
		{
			sub = str2;
			src = ++stact;
		}
		if (*sub == '\0')
		{
			return stact;
		}
	}
	return NULL;
}

int main()
{
	char a[20] = "i am a student";
	char* p;
	p = my_strstr(a, " ");
	printf("%s\n", p);
	return 0;
}

#endif

//实现strchr
#include<stdio.h>
#include<string.h>

char* my_strchr(const char* str1, const char str2)
{
	const char* src = str1;
	const char sub = str2;
	while (*src != sub)
	{
		src++;
	}
	return src;
}

int main()
{
	char a[20] = "i am a student";
	char* p;
	p = my_strchr(a, 'a');
	printf("%s\n", p);
	return 0;
}