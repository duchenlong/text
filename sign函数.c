#include <stdio.h>
#include <string.h>

int main()
{
	char arr[105] = {'\0'};
	scanf("%s",arr);
	int flag = 0;
	int len = strlen(arr);
	char* a = arr;
	int ans = 0;
	int i=0;
	int count =0;
	for(i=0;i<len;i++)
	{
		if(arr[i] == '.')
		{
			flag = 1;
		}
		
		if(arr[i]  == '0')
		{
			count++;
		}
	}
	if(!flag)
	{
		if(count == len)
		{
			ans=0;
		}
		else if(arr[0] == '-')
		{
			ans = -1;
		}
		else
		{
			ans = 1;
		}
	}
	else
	{
		
		if( (arr[0] == '-' && count == len-2) ||count == len - 1)
		{
			ans=0;
		}
		else if(arr[0] == '-')
		{
			ans = -1;
		}
		else
		{
			ans = 1;
		}
	}
	printf("%d",ans);
	return 0;	
} 
