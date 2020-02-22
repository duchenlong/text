#include <stdio.h>

int arr[2][2] = {0};

void mul(int c[2][2],int n[2][2],int m)
{
	int a,b,x,y;
	a = c[0][0] * n[0][0] % m + c[0][1] * n[1][0] % m;
	b = c[0][0] * n[0][1] % m + c[0][1] * n[1][1] % m;
	x = c[1][0] * n[0][0] % m + c[1][1] * n[1][0] % m;
	y = c[1][0] * n[0][1] % m + c[1][1] * n[1][1] % m;
	
	arr[0][0] = a % m;
	arr[0][1] = b % m;
	arr[1][0] = x % m;
	arr[1][1] = y % m; 
}

void mod(int m)
{
	arr[0][0] %= m;
	arr[0][1] %= m;
	arr[1][0] %= m;
	arr[1][1] %= m; 
}

void zero(int m)
{
	arr[0][0] = 1 % m;
	arr[0][1] = 0;
	arr[1][0] = 0;
	arr[1][1] = 1 % m;
}

void Fun(int b,int m)
{
	
	if(b == 0)
		zero(m);
	else
		if(b % 2 == 0)
		{
			Fun(b/2,m);
			mul(arr,arr,m);
		}
		else
		{
			int c[2][2] = {0};
			c[0][0] = arr[0][0];
			c[0][1] = arr[0][1];
			c[1][0] = arr[1][0];
			c[1][1] = arr[1][1];
			Fun(b-1,m);
			mod(m);
			mul(arr,c,m);
		}
}

int main()
{
	int b,m;
	scanf("%d%d",&b,&m);

	int i = 0;
	int j = 0;
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	
	Fun(b,m);
	
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
