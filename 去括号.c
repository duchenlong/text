#include <stdio.h>
#include <string.h>

char str[300] = {'\0'};
int len = 0;
int arr[300] = {0};//��¼ǰ�����ŵ��±�
int right = 0;//arr����ĳ��� 
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
	//�����ڵ�ʽ���� 
	if(arr[right-1] == 0 && i == len-1)
	{
		return 1;
	}
	
	int j = arr[right];
	for(;j<i;j++)
	{
		src[str[j]]++;
	}
	
	//�������ڵ�ʽ����� 
	if(arr[right-1] == 0)
	{
		if(str[i+1] == '+' || str[i+1] == '-')
		{
			return 1; 
		}
	}
	
	//�ų� a-(b+c)  
	if(str[arr[right-1] - 1] == '-')
	{
		if(!src['*'] || !src['/'])
		{
			return 0;
		}
	}
	
	//�ų� a*(b*  / c)
	if(str[arr[right-1] - 1] == '*' )
	{
		if(!src['+'] || !src['-'])
		{
			return 0;
		}
	} 
	
	//�����ڵ�ʽ���Ҳ� 
	if(i==len-1)
	{
		if(str[arr[right-1]-1]  == '+' || str[arr[right-1]-1]  == '-')
		{
			return 1; 
		}
	}
	//�����ڵ�ʽ�м� 
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
