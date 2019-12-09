#include<stdio.h>
#include<string.h>

char a[100000000]={'\0'}; 

void ShowChar(int n)
{
	int len=strlen(a);
	if(len==0)
	{
		a[0]='A';
		return ;
	}
	a[len]='A'+n;
	int i=1;
	while(i<=len)
	{
		a[i+len]=a[i-1];
		i++;
	}
} 

void Printf(int n)
{
	int i=0;
	if(n==1)
	{
		printf("A\n");
		return ;
	}
	int len=strlen(a);
	for(i=0;i<len;i++)
	{
		printf("%c",a[i]);
	}
	printf("%c",'A'+n-1);
	for(i=0;i<len;i++)
	{
		printf("%c",a[i]);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int j=0;
	for(j=0;j<n-1;j++)
	{
		ShowChar(j);
	}
	Printf(n); 
	return 0;
} 
