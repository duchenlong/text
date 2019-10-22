#define _CRT_SECURE_NO_WARNINGS 1


#if 0
//实现strcmp
#include<stdio.h>
#include<string.h>

int my_strcmp(const char* str1, const char* str2)
{
	while (*str1&&*str2)
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		else
		{
			str1++;
			str2++;
		}
	}
	return 0;
}

int main()
{
	char* a = "hello";
	char* b = "hello";
	int i=strcmp(a, b);
	printf("%d\n", i);
	int j = my_strcmp(a, b);
	printf("%d\n", j);
	return 0;
}

#endif

#if 0
//实现memcpy

#include<stdio.h>
#include<string.h>

void* my_memcpy(void* str1, const void* str2, int size)
{
	int i = 0;
	void* src = str1;
	while (size--)
	{
		*((char*)str1 + size) = *((char*)str2 + size);
	}
	return src;
}

int main()
{
	char a[] = "hello world";
	memcpy(a+2, a , 4 * sizeof(a[0]));
	printf("%s\n", a);
	char c[] = "hello world";
	my_memcpy(c+2, c, 4*sizeof(c[0]));
	printf("%s\n", c);
	return 0;
}
#endif

//实现memmove

#if 0
#include<stdio.h>
#include<string.h>

void* my_memmove(void* str1, const void* str2, int size)
{
	void* src = str1;
	if ((str1<=str2)||((char*)str1 >= ((char*)str2+size)))
	{
		int i = 0;
		for (i = 0; i < size; i++)
		{
			*((char*)str1 + i) = *((char*)str2 + i);
		}
	}
	else
	{
		while (size--)
		{
			*((char*)str1 + size) = *((char*)str2 + size);
		}
	}
	return src;
}

int main()
{
	char a[] = "hello world";
	memmove(a, a + 2, 4 * sizeof(a[0]));
	char c[] = "hello world";
	my_memmove(c, c+2,4*sizeof(a[0]));
	printf("%s\n", a);
	printf("%s\n", c);
	return 0;
}
#endif
//#if 0
#include<stdio.h>
#include<string.h>

int main()
{
	char a[] = "hello world";
	char c[] = "hellO world";
	//int i=memcmp(a, c, 3);
	int i = strncmp(a, c,3);
	//my_memmove(c, c + 2, 4 * sizeof(a[0]));
	printf("%d\n", i);
	return 0;
}
//#endif

#if 0
//strlen
#include<stdio.h>
#include<string.h>

int my_strlen(const char* str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}

int main()
{
	char a[] = "hello world";
	int i = my_strlen(a);
	printf("%d\n", i);
	return 0;
}
#endif
#if 0
#include<stdio.h>
#include<string.h>

int main()
{
	char a[30] = "hello world";
	char b[] = "morning";
	printf("%s\n", strncat(a, b, 6));
	return 0;
}
#endif