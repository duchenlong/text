#include <stdio.h>
#include <string.h>

char str[10000] = {'\0'};
char src[10000] = {'\0'};
char arr[20] = {'\0'};
int n;

int Find(char* a,char ch)
{
	int i = 0;
	while(1)
	{
		if(a[i] == ch)
		{
			return i;
		}
		i++;
	}
}

void Slove()
{
	int len = strlen(str);
	int i = 0;
	for(i=0;i<=len/2;i++)
	{
		src[i] = str[len-1-i];
		src[len-1-i] = str[i];
	}
	
	int num = 0;
	for(i=0;i<len;i++)
	{
		int a,b;
		a = Find(arr,str[i]);
		b = Find(arr,src[i]);
		num += a + b;
		str[i] = arr[num % n];
		num /= n;
	}
	
	while(num)
	{
		str[i++] = arr[num % n];
		num /= n;
	}
}

int Judge()
{
	int len = strlen(str);
	int i = 0;
	for(i=0;i<len/2;i++)
	{
		if(str[i] != str[len-i-1])
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	
	scanf("%d",&n);
	scanf("%s",str);
	int i =0 ;
	for(i = 0; i <= 9; i++)
	{
		arr[i] = i + '0';
	}
	for(;i < 16;i++)
	{
		arr[i] = i + 'A' - 10;
	}
	
	int num = 0;
	while(num != 30)
	{
		Slove();
		num++;
		if(Judge())
		{
			printf("STEP=%d\n",num);
			return 0;
		}
		
	}
	printf("Impossible!\n");
	return 0;
}
