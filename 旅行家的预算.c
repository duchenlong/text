#include <stdio.h>
#define MAX 0xffffffff
struct node
{
	double path;//����վ�������ľ��� 
	double money;//����վÿ���͵ļ۸� 
}arr[100000];

double C;//�������������
double d;//ÿ���Ϳ�����ʹ�ľ���
double N;//��;����վ���� 
double d1;//d1 ��������֮��ľ���
double p;//p ������ÿ�����͵ļ۸�
double ans = 0;

void sort()
{
	int i = N + 1;
	int j = 0;
	for(i = 1; i < N; i++)
	{
		for(j = 0; j < N - i; j++)
		{
			if(arr[j].path > arr[j + 1].path)
			{
				struct node tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp; 
			}
		}	
	} 
}

void slove()
{
	double mpath = 0;//��ʾ��ǰ����վ�����Ϳ��Ե���ľ���
	int now = 0;//��ǰ����վ�ı�� 
	double tank = 0;//��ǰ���������� 
	
	while(now < N)
	{
		mpath = C * d;
		int i = now + 1;
		double minoil = MAX;
		int k = now; 
		
		for(; i <= N && arr[i].path - arr[now].path <= mpath; i++)
		{
			//�ҵ������ĵ�һ�����ͼ۵��±� 
			if(arr[i].money < arr[k].money)
			{
				k = i;
				break;
			}
			
			//������Դﵽ��Χ���ͼ۶��ȵ�ǰ���ҵ�����ͼ۵��±� 
			if(minoil > arr[now].money)
			{
				minoil =  arr[i].money;
				k = i;
			}	
		}
		
		//��������͵��ﲻ������ļ���վ���˳� 
		if(k == now)
		{
			//printf("%d\n",now);
			printf("No Solution\n");
			return; 
		}
		//�����������ü���վ����Ҫ������
		double need = (arr[k].path - arr[now].path) / d; 
		if(arr[k].money < arr[now].money)//�ҵ��бȵ�ǰ����վ�����͵ļ���վ 
		{
			//ֻ��Ҫ�򵽸ü���վ����
			if(need <= tank)
			{
				tank -= need;	
			} 
			else
			{
				ans += (need - tank) * arr[now].money;
				//printf("%.2lf %d\n",ans,k);
				tank = 0;
			}
		}
		else
		{
			ans += (C - tank) * arr[now].money;
			tank = C - need;
		}
		//printf("%d %.2lf\n",tank,ans);
		now = k; //�������վk ,������һ��ѭ�� 
	}
	
	printf("%.2lf\n",ans);	 
} 

int main()
{
	 
	scanf("%lf%lf%lf%lf%lf",&d1,&C,&d,&p,&N);
	int i = 0;
	arr[i].path = 0,arr[i].money=p;
	for(i = 1; i <= N; i++)
	{
		scanf("%lf%lf",&arr[i].path,&arr[i].money);
	}
	arr[i].path = d1,arr[i].money=0;
	N++;
	sort();
	slove();
//	for(i = 0; i <= N; i++)
//	{
//		printf("%.2lf %.2lf %d\n",arr[i].path,arr[i].money,i);
//	}
	
	return 0;
}
