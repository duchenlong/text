#include <stdio.h>

int arr[50000] = {0};
int a[50000] = {0}; //��������������Ŀ 
int b[50000] = {0}; //���ݼ���������Ŀ 

int subsum(int len)
{
	int i = 0,j = 0;
	b[0] = 1; //����ÿһλ��ʾ���ڵ�ǰ�±�֮ǰ����n���������� 
	int max = 0;
	for(i = 1;i < len; i++)
	{
		int k = 0;
		for(j = i - 1; j >= 0; j--)
		{
			if(arr[i] < arr[j])
			{
				if(b[j] > k)
				{
					k = b[j];
				}
			} 
		}
		
		b[i] = k + 1;
		if(max < b[i])
		{
			max = b[i];
		}
	}
	return max;
}

//int addsum(int len)
//{
//	int i = 0,j = 0;
//	a[0] = 1;
//	int max = 0;
//	for(i = 1;i < len; i++)
//	{
//		int k = 0;
//		for(j = i - 1; j >= 0; j--)
//		{
//			if(arr[i] > arr[j])
//			{
//				if(a[j] > k)
//				{
//					k = a[j];
//				}
//			} 
//		}
//		
//		a[i] = k + 1;
//		if(max < a[i])
//		{
//			max = a[i];
//		}
//	}
//	return max;
//}

//�����������еĳ���Ϊ����Ҫ�䱸��ϵͳ�� 
int BinaryFind(int right,int num)
{
	int left = 0;
	int mid = 0;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(a[mid] == num)
		{
			return mid;
		} 
		else if(a[mid] < num)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return left;
}

int addsum(int len)
{
	int i = 0;
	int count = 0;
	for(i = 0; i < len; i++)
	{
		if(arr[i] > a[count])
		{
			a[++count] = arr[i];
		}
		else
		{
			int c = BinaryFind(count,arr[i]);
			a[c] = arr[i];
		}
	}
	return count;
}

int main()
{
	int len = 0;
	int i = 0;
	while(1)
	{
		scanf("%d",&arr[len++]);
		char ch = getchar();
		if(ch == '\n')
		{
			break;
		}
	}
	//�������صĵ�����
	printf("%d\n",subsum(len)); 
	
	//ϵͳ�� 
	printf("%d\n",addsum(len));
	return 0;	
} 
