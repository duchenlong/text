#include <stdio.h>
char arr[25]={'0','\0'};

void div(int a,int b)
{
	int i = 0;
	int count = 20;
	
	while(count)
	{
		if(a == 0)
		{
			return ;
		}
		a = a * 10 ;
		int num = a / b;  	
		arr[i++] = num % 10 + '0';
		
		a -= num * b;
		
		count--;
	}
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	div(a%b,b);
	
	printf("%d.%s\n",a/b,arr);
	
	return 0;
}
