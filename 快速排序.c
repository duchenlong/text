#include<stdio.h>

int arr[100005] = {0};

void Show(int n)
{
	int i = 0;
	for(i = 0; i < n; i++)
	{
		printf("%d\n",arr[i]);
	}
}

void swap(int a,int b)
{
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp;
}

void Fast_sort(int left,int right)
{
	if(left >= right)
	{
		return ;
	}
	
	int l = left;
	int r = right;
	
	int num = arr[left];
	while(l < r)
	{
		//找右边第一个小于 num
		while(arr[r] >= num && l < r)
		{
			r--;
		} 
		
		//找左边第一个大于 num
		while(arr[l] <= num && l < r)
		{
			l++;
		} 
		
		swap(l,r);
		r--;
	}
	
	swap(left,l);
	Fast_sort(left,l-1);
	Fast_sort(l+1,right); 
}

int main()
{
	int n;
	scanf("%d",&n);
	int i = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	Fast_sort(0,n-1);
	
	Show(n);
	return 0;
} 
