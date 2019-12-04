#include<stdio.h>
#include<string.h>

int main()
{
	char a[105]={'\0'},b[105]={'\0'};
	char c[105]={'\0'};
	int lena,lenb,lenc;
	int i=0;
	int num=0;
	gets(a);
	gets(b);
	lena=strlen(a);
	lenb=strlen(b);
	lenc=lena<lenb?lenb:lena;
	i=lenc;
	while(lena&&lenb)
	{
		num+=(int)(a[lena-1]+b[lenb-1]-'0'*2);
		c[i-1]=num%10+'0';
		num=num/10;
		i--;
		lena--;
		lenb--;
	}
	if(lena)
	{
		while(i)
		{
			num+=(int)(a[lena-1]-'0');
			c[i-1]=num%10+'0';
			num/=10;
			i--;
			lena--;
		}
	}
	else
	{
		while(i)
		{
			num+=(int)(b[lenb-1]-'0');
			c[i-1]=num%10+'0';
			num/=10;
			i--;
			lenb--;
		}
	}
	if(num)
	{
		printf("%c",num+'0');
	}
	puts(c);
	return 0;
}
