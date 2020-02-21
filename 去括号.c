#include <stdio.h>
#include <string.h>

char str[300] = {'\0'};
int len = 0;
int arr[300] = {0};//记录前置括号的下标
int right = 0;//arr数组的长度 
int left = 0;

void cut(int n,int m)
{
	strncpy(str+m,str+m+1,len-m-1);
	str[--len] = '\0';
	strncpy(str+n,str+n+1,len-n-1);
	str[--len] = '\0';
}

int Judge(int i)
{
	int src[500] = {'\0'};
	
	//printf("%d %d\n",arr[right-1],i);
	//括号在等式两边 
	if(arr[right-1] == 0 && i == len-1)
	{
		return 1;
	}
	
	int j = arr[right];
	for(;j<i;j++)
	{
		src[str[j]]++;
	}
	
	//后括号在等式最左侧 
	if(arr[right-1] == 0)
	{
		if(str[i+1] == '+' || str[i+1] == '-')
		{
			return 1; 
		}
	}
	
	//排除 a-(b+c)  
	if(str[arr[right-1] - 1] == '-')
	{
		if(!src['*'] || !src['/'])
		{
			return 0;
		}
	}
	
	//排除 a*(b*  / c)
	if(str[arr[right-1] - 1] == '*' )
	{
		if(!src['+'] || !src['-'])
		{
			return 0;
		}
	} 
	
	//括号在等式最右侧 
	if(i==len-1)
	{
		if(str[arr[right-1]-1]  == '+' || str[arr[right-1]-1]  == '-')
		{
			return 1; 
		}
	}
	//括号在等式中间 
	if((str[i+1] == '+' || str[i+1] == '-') && \
		(str[arr[right-1]-1] == '+' || str[arr[right-1]-1]  == '-'))
	{	
		return 1;
	}
	
	
	return 0;
}

void slove()
{
	int i = 0;
	while(i < len)
	{
		//printf("%d %d %d %d %c\n",left,right,i,len,str[i]);
		while(str[i] != ')' && i < len)
		{
			if(str[i] == '(')
			{
				arr[right++] = i;
			}
			i++;
		}
		
		if(right != 0 && i < len)
		{
			if(Judge(i))
			{
				cut(arr[right-1],i);
			}
			else
				i++;
			//puts(str);
			right--;
		}
		
		
	}
}

int main()
{
	scanf("%s",str);
	len = strlen(str);
	
	slove();
	
	puts(str);
	
	return 0;
}
