#include <stdio.h>
#include <string.h>

char str[100] = {0};
int len;

void slove_D()
{
	char s1;
	scanf(" %c",&s1);
	int i = 0;
	while(str[i])
	{
		if(str[i] == s1)
		{
			//puts(str+i);
			strcpy(str+i,str+i+1);
			break;
		}
		i++;
	}
}

void slove_I()
{
	char s1,s2;
	scanf(" %c %c",&s1,&s2);
	int i = len-1;
	while(str[i])
	{
		if(str[i] == s1)
		{
			//puts(str+i);
			memmove(str+i+1,str+i,len-i);
			str[i] = s2;
			break;
		}
		
		i--;
	}
}

void slove_R()
{
	char s1,s2;
	scanf(" %c %c",&s1,&s2);
	int i = 0;
	
	while(str[i])
	{
		if(str[i] == s1)
		{
			str[i] = s2;
		}
		
		i++;
	}
}
int main()
{
	while(1)
	{
		scanf("%c",&str[len++]);
		if(str[len-1] == '.')
		{
			break;
		}
	}
	getchar();
	char choose;
	scanf("%c",&choose);
	switch(choose)
	{
		case 'D':
			slove_D();
			break;
		case 'I':
			slove_I();
			break;
		case 'R':
			slove_R();
			break;
	}
	puts(str);
	return 0;
} 
