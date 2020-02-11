#include <stdio.h>
#include <string.h>
#include <math.h>

int arr[600] = {2};

int len = 1;

void my_pow()
{
	int tmp[600] = {0};
	memset(tmp,0,sizeof(tmp));
	int i = 0;
	int j = 0;
	for(i = 0; i < 500; i++)
	{
		for(j = 0; j < 500; j++)
		{
			if(i + j > 500)
			{
				break;
			}
			tmp[i + j] += arr[i] * arr[j];
		}
	}
	
	int num = 0;
	for(i = 0; i < 500; i++)
	{
		//printf("%d ",tmp[i]);
		num += tmp[i];
		tmp[i] = num % 10;
		num /= 10;
	}
	for(i = 0; i < 500; i++)
	{
		arr[i] = tmp[i];
	}
}

void my_pow2()
{
	int num = 0;
	int i = 0;
	for(i = 0; i < 500; i++)
	{
		//printf("%d ",arr[i]);
		num += arr[i] * 2;
		arr[i] = num % 10;
		num /= 10;
	}
}

void slove(int p)
{
	if(p / 2 != 1)
	{
		slove(p / 2);
	}
	my_pow(); 
	
	if(p % 2 == 1)
	{
		my_pow2();
	}
}


void my_sub()
{
	int num = 1;
	int i = 0;
	while(arr[i] == 0 && i < 500)
	{
		arr[i++] = 9;
	}
	
	arr[i]--;
}

int main()
{
	int p;
	scanf("%d",&p);
	//p--;
	int i = 0;
	slove(p);
	my_sub();
	// 麦森数的位数  (n*log10(2))+1 
	printf("%d\n",(int)(p*log10(2))+1);
	for(i = 499; i >= 0; i--)
	{
		printf("%d",arr[i]);
		
		if(i % 50 == 0)
		{
			printf("\n");
		}
	}
	printf("\n");
	return 0;	
} 
