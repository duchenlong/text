#include <stdio.h>

int many = 0;//客人手里的钞票 
int arr[120] = {0}; //记录老板手里的钞票数，arr[25],arr[50]

int int_cmp(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
} 

int main()
{
	int n;
	scanf("%d",&n);
	
	int i = 0;
//	for(i = 0; i < n; i++)
//	{
//		scanf("%d",&many[i]);
//		
//	}
//	
//	qsort(many,n,sizeof(int),int_cmp);
	
	for(i = 0; i < n; i++)
	{
		scanf("%d",&many);
		//printf("%d %d %d\n",many[i],arr[25],arr[50]);
		if(many == 25)
		{
			arr[25]++;
			continue;
		}
		
		if(many == 50 && arr[25])
		{
			arr[25]--;
			arr[50]++;
			continue;
		}
		else if(many != 100)
		{
			printf("NO\n");
			break;
		}
	
		if(arr[50] && arr[25])
		{
			arr[50]--;
			arr[25]--;
			continue;
		}
		else if(arr[25] >= 3)
		{
			arr[25] -= 3;
			continue;
		}
		
		printf("NO\n");
		break;
	}
	
	if(i == n)
	printf("YES\n");
	return 0;
} 
