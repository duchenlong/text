#include <stdio.h>
#include <string.h>

char str[300] = {'\0'};
char ji[150] = {'\0'};

void slove(int len)
{
	int i = 0;
	for(i = 0; i < len / 2; i++)
	{
		char ch = ji[i];
		ji[i] = ji[len - 1 - i];
		ji[len - 1 - i] = ch;
	}
}

int main()
{
	scanf("%s",str);
	int len = strlen(str);
	
	int i = 1;
	int count = 0;
	for(; i < len; i += 2)
	{
		ji[count++] = str[i]; 
	}
	slove(count);
	for(i = 0; i < len ; i++)
	{
		if(i % 2 == 0)
		{
			printf("%c",str[i]);
		}
		else
		{
			printf("%c",ji[i/2]);
		}
	}
	return 0;
}
