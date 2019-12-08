#include<stdio.h>
#include<string.h>

int main()
{
	char str1[100]={'\0'};
	char str2[100]={'\0'};
	int len1,len2;
	int i=0;
	gets(str1);
	gets(str2);
	len1=strlen(str1);
	len2=strlen(str2);
	if(len1!=len2)
	{
		printf("1\n");
	}
	else if(strcmp(str1,str2)==0)
	{
		printf("2\n");
	}
	else
	{
		for(i=0;i<len1;i++)
		{
			if(str1[i]>='A'&&str1[i]<='Z')
			{
				str1[i]+=32;
			}
		}
		for(i=0;i<len2;i++)
		{
			if(str2[i]>='A'&&str2[i]<='Z')
			{
				str2[i]+=32;
			}
		}
		if((strcmp(str1,str2)==0))
		{
			printf("3\n");
		}
		else
		{
			printf("4\n");
		}
	}
	return 0;
}
