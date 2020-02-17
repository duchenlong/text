#include <stdio.h>

int arr[5000] = {0};
int a,b,m,n;

int fac(int a,int b)
{
	int c = 0;
	if(a < b)
	{
		a = a^b;
		b = a^b;
		a = a^b;
	}
	//c = a % b;
	
	while(b != 0)
	{
		c = a % b;
		a = b;
		b = c;
		
	}
	return a;
}

int ple(int a,int b)
{
	int count = fac(a,b);
	return a / count * b;
}

int judge(int num)
{
    if(num % b!=0)
    	return 0;
    return fac(a/b,num/b)==1 && fac(n/m,n/num)==1;   //通过数学方法推导求得
}

int main()
{
	
	int num;
	scanf("%d",&num);
	int len = 0;
	int i = 0;
	while(num--)
	{
		scanf("%d%d%d%d",&a,&b,&m,&n);
		int cnt = 0;
		for(i = 1; i * i < n; i++)
		{
			if(n % i != 0)
			{
				continue;
			}
			
			cnt += judge(i);
			cnt += judge(n / i);
		}
		
		//判断开根号的因数 
		if(i*i == n)
		{
			cnt += judge(i);
		}
		arr[len] = cnt;
		
//		//枚举 
//		for(i = 1; i <= n; i++)
//		{
//			if(n % i != 0)
//			{
//				continue;
//			}
//			
//			if( fac(i,a) == b && (i / fac(i,m) * m == n))
//			{
//				//printf("%d ",i);
//				arr[len]++;
//			}
//		}
		len++;
	}
	
	for(i = 0; i < len; i++)
	{
		printf("%d\n",arr[i]);
	}
	
	return 0;
}
