#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num;//ľ������
int arr[100] = {0};//ÿһ��ľ���ĳ���
int visit[100] = {0};//�ж�ľ����û�б�����
int ans[10000] = {0}; //ÿһ��ľ������С��ϳ���
int len = 0; // ans����ĳ��� 
int max = 0; // ���������ɸó��ȵ�ľ���� 

int int_cmp(const void* a,const void* b)
{
	return *(int*)b - *(int*)a;
}

//now ������ϵ�ľ�����ȣ�size ��Ҫƴ��ľ��ĳ���
//res �Ѿ�ƴ��size ��ľ������ 
int dfs(int now,int res,int cur,int size)
{
	if(res == max)
	{
		return 1;
	}
	//printf("%d\n",now);
	int i = 0;
	for(i = cur; i < num; i++)
	{
		if(visit[i] || (i && arr[i] == arr[i-1]  && !visit[i-1]))
		{
			continue;
		}
		
		if(now + arr[i] == size)
		{
			visit[i] = 1;
			if(dfs(0,res+1,0,size))
			{
				return 1;
			}
			visit[i] = 0;
			return 0;
		}
		else if(now + arr[i] < size)
		{
			visit[i] = 1;
			if(dfs(now+arr[i],res,i+1,size))
			{
				return 1;
			}
			visit[i] = 0;
			
			if(!now)
			{
				return 0;
			}
		}
	}
	return 0;
}

int main()
{
	
	scanf("%d",&num);
	int i = 0;
	while(num)
	{
		int sum = 0;
		for(i = 0; i < num; i++)
		{
			scanf("%d",&arr[i]);
			sum += arr[i];
		}
		
		//����ľ���Ӵ�С���� 
		qsort(arr,num,sizeof(int),int_cmp);
		
//		for(i = 0; i< num; i++)
//		{
//			printf("%d ",arr[i]);
//		}
		
		int flag = 0;
		
		for(i = arr[0]; i <= sum/2; i++)
		{
			if(sum % i == 0)
			{
				memset(visit,0,sizeof(visit));
				max = sum / i; // ���������ɸó��ȵ�ľ���� 
				//����
				if(dfs(0,0,0,i))
				{
					ans[len++] = i;
					flag = 1;
					break;
				}
			}
		}
		
		if(!flag)
		{
			ans[len++] = sum;
		}
		
		scanf("%d",&num); 
	} 
	
	for(i = 0; i < len; i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;
}
