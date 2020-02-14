#include <stdio.h>
#include <string.h>
#include <math.h>

char str[100000] = {'\0'};
int n;

void Printf_FBI(int left,int right)
{
	//printf("\n%d %d\n",left,right);
	int zero = 0;
	int one = 0;
	int i = 0;
	for(i = left; i < right; i++)
	{
		if(str[i] == '0')
		{
			zero++;
		}
		else
		{
			one++;
		}
		
		if(zero && one)
		{
			printf("F");
			return; 
		}
	}
	
	if(zero)
	{
		printf("B");
	}
	else
	{
		printf("I");
	}
}

void Binary_slove(int left,int right)
{
	if((right == left) || (abs(right - left) == 1))
	{
		Printf_FBI(left,right);
		return;
	}
	
	int mid = (left + right) / 2;
	Binary_slove(left,mid);
	Binary_slove(mid,right);
	Printf_FBI(left,right);
}

int main()
{
	scanf("%d",&n);
	scanf("%s",str);
	int len = pow(2,n);
	//printf("%d",len);
	Binary_slove(0,len);
	
	return 0;
}
