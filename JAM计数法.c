#include <stdio.h>
#include <string.h>

char str[50] = {'\0'};
char max[50] = {0}; //当前该位置最大的字母

int Judge(int len)
{
	int i = 0;
	for(i = 1; i < len; i++)
	{
		if(str[i] <= str[i - 1])
		{
			return 1;
		}
	}
	
	return 0;
}

void add(char left,char right,int len)
{
	int i = len - 1;
	int count = 1;
	for(; i > 0; i--)
	{
		if(str[i] == max[i])
		{
			continue;
		}
		int j = 0;
		char ch = str[i] + 1;
		for(j = i; j < len; j++)
		{
			str[j] = ch;
			ch++;
		}
		return ;
	}
//	while(count)
//	{
//		if(str[i] + 1 > right)
//		{
//			str[i] = left;
//		}
//		else
//		{
//			str[i]++;
//			count = 0;
//		}
//		i--;
//	}
}

int  main()
{
	int s,t,w;
	scanf("%d%d%d",&s,&t,&w);
	scanf("%s",str);
	char left = 'a' + s - 1;
	char right = 'a' + t - 1;
	char min[50] = {'\0'};
	
	int i = 0;
	int j = 0;
	for(i = w; i > 0; i--)
	{
		max[i-1] = right - j;
		j++;
	}
	
//	for(i = 0; i < w; i++)
//	{
//		min[i] = left;
//	}
	//printf("%c %c\n",left,right);
	for(i = 0; i < 5; i++)
	{
		add(left,right,w);
		if(strcmp(str,min) == 0)
		{
			break;
		}
		puts(str);
//		if(Judge(w))
//		{
//			i--;
//		}
//		else
//		{
//			puts(str);
//		}
	}
	
	
	return 0;	
} 
