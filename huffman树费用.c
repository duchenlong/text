#include<stdio.h>
#include<stdlib.h>

void my_sqrt(int* arr,const int len)
{
	int i=0,j=0;
	int flag=0;
	for(i=0;i<len;i++)
	{
		flag=0;
		for(j=0;j<len-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
				flag=1;
			}
		}
		if(!flag)
		{
			break;
		}
	}
}

int main()
{
	int n,i;
	int* huffman;
	int num=0;
	int ans=0;
	int len=3;
	scanf("%d",&n);
	huffman=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&huffman[i]);
	}
	while(n!=1)
	{
		my_sqrt(huffman,n);
//		for(i=0;i<n;i++)
//		{
//			printf("%d ",huffman[i]);
//		}
//		printf("\n");
		num=huffman[0]+huffman[1];
		ans+=num;
		//printf("%d %d\n",num,ans);
		huffman[0]=num;
		for(i=2;i<n;i++)
		{
			huffman[i-1]=huffman[i];
		}
		n--;
	}
	
	
	printf("%d\n",ans);
	return 0;
}
