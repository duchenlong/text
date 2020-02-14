#include <stdio.h>

int arr[10005] = {0};

int int_cmp(const void* a,const void* b)
{
	return *(int*)a > *(int*)b;
}

int swap(int left,int right)
{
	arr[left] = arr[left] ^ arr[right];
	arr[right] = arr[left] ^ arr[right];
	arr[left] = arr[left] ^ arr[right]; 
}

void slove(int n,int m)
{
	int i = 0;
	int j = 0;
	while(m--)
	{
		int max = 10001;
		for(i = n - 2; i >= 0; i--)
		{
			if(arr[i] < arr[i + 1])
			{
				int span = n+1;
				int count = 0;//比arr[i]大的最小的数 的下标 
				for(j = i + 1; j < n; j++)
				{
					if(arr[j] > arr[i] && arr[j] - arr[i] < span)
					{
						span = arr[j] - arr[i];
						count = j;
					}
				}
				swap(i,count);
				qsort(arr + i + 1,n - i - 1,sizeof(int),int_cmp);
//				for(j = 0; j < n; j++)
//				{
//					printf("%d ",arr[j]);
//				}
//				printf("\n");
				break;
			}
		}
	}
}

int main()
{
	int m,n;
	scanf("%d",&n);//火星人手指的数目 
	scanf("%d",&m);//需要加的数
	
	int i = 0;
	for(i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	slove(n,m);
	
	for(i = 0; i < n; i++)
	{
		printf("%d ",arr[i]);
	}
	
	return 0;
}
