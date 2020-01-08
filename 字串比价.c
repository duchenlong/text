#include <stdio.h>
#include <string.h>

int my_strncmp(const char* arr,const char* brr,const int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		if(*arr - *brr > 0)
		{
			return 1;
		}
		else if(*arr - *brr < 0)
		{
			return -1;
		}
		
		arr++;
		brr++;
	}
	return 0;
}

int main()
{
	char arr[100000] = {0};
	char brr[100000] = {0};
	int n=0;
	scanf("%s",arr);
	scanf("%s",brr);
	scanf("%d",&n);
	printf("%d\n",my_strncmp(arr,brr,n));
	
	return 0;
}
