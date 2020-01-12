#include <stdio.h>

int a[35000] = {0};

int int_cmp(const void* p1,const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

void Slove(int max,int num)
{
	int left = 0;
	int right = num - 1;
	int ans = 0;
	while(left <= right)
	{
		if(a[right] + a[left] > max)
		{
			right--;
			ans++;
		}
		else
		{
			int sum = a[right] + a[left];
			left++;
			while(left <= right && sum + a[left] < max)
			{
				sum += a[left++];
			}
			right--;
			ans++;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	int max;
	scanf("%d",&max);
	int num;
	scanf("%d",&num);
	int i = 0;
	for(i = 0; i < num; i++)
	{
		scanf("%d",&a[i]);
	}
	
	qsort(a,num,sizeof(int),int_cmp);
	Slove(max,num);
	return 0;	
} 
