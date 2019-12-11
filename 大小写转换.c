#include<stdio.h>
#include<string.h>

int main()
{
	char arr[30]={'\0'};
	scanf("%s",arr);
	int len=strlen(arr);
	int i=0;
	for(i=0;i<len;i++)
	{
		if(arr[i]>='A'&&arr[i]<='Z')
		{
			arr[i]=arr[i]-'A'+97;
		}
		else
		{
			arr[i]=arr[i]-'a'+65;
		}
	}
	puts(arr);
	return 0;
}
