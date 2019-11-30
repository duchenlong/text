#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

void text(char* str, int length)
{
	int i = 0;
	int len = 0;
	char* src;
	src = (char*)malloc(sizeof(char)* 3 * length);
	for (i = 0; i < length; i++)
	{
		if (*(str + i) == ' ')
		{
			*(src + len) = '%';
			*(src + len + 1) = '2';
			*(src + len + 2) = '0';
			len += 3;
			continue;
		}
		*(src + len) = *(str + i);
		len++;
	}
	for (i = 0; i < len; i++)
	{
		*(str + i) = *(src + i);
	}
}

int main()
{
	char str[50] = "we are heppy";
	text(str, 12);
	puts(str);
	return 0;
}
