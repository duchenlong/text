#include <stdio.h>
#include <string.h>

int a,b;
char str[1000] = {'\0'};
char src[100] = {'\0'};
char cub[1000] = {'\0'};

int Findf(int len)
{
	int i = len - 1;
	while(str[i] != 'f')
	{
		i--;
		if(i < 0)
		{
			return -1;
		}
	}
	return i;
}

void fun(int len)
{
	int left = 0;
	int right = 0;
	int i = 2;
	if(str[len + i] == '-')
	{
		i++;
	}
	while(str[len + i] != ',')
	{
		left = left * 10 + str[len + i] - '0';
		i++;
	}
	if(str[len + 2] == '-')
	{
		left = 0 - left;
	}
	
	i++;
	int j = i;
	if(str[len + j] == '-')
	{
		i++;
	}
	while(str[len + i] != ')')
	{
		right = right * 10 + str[len + i] - '0';
		i++;
	}
	if(str[len + j] == '-')
	{
		right = 0 - right;
	}
	
	memset(src,'\0',100);
	int num = a * left + b * right;
	i = 0;
	int count = num;
	if(count < 0)
	{
		num = 0 - num;
	}
	while(num)
	{
		src[i++] = num % 10 + '0';
		num /= 10;
	}
	if(count < 0)
	{
		src[i] = '-';
	}
}

int Findafter(int len)
{
	int i = 0;
	while(str[len + i] != ')')
	{
		i++;
	}
	return i + len;;
}

void Slove()
{
	int len = strlen(str);
	while(Findf(len) != -1)
	{
		int count = Findf(len);
		fun(count);
		int num = strlen(src);
		
		int l = Findafter(count);
	
		int i = 0;
		for(i = 0; i < num; i++)
		{
			str[count + i] = src[num - i - 1];
		}

		strcpy(str + count + num,str + l + 1);
	}
}

int main()
{
	scanf("%d%d",&a,&b);
	scanf("%s",str);
	
	Slove();
	int ans = 0;
	int len = strlen(str);
	int i = 0;
	if(str[0] == '-')
	{
		i++;
	}
	for(;i<len;i++)
	{
		ans = ans * 10 + str[i] - '0';
	}
	if(str[0] == '-')
	{
		ans = 0 - ans;
	}
	printf("%d\n",ans);
	return 0;
}
