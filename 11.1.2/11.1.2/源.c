#define _CRT_SECURE_NO_WARNINGS 1

//���⣺������
//
//��ͼ p1.png ��ʾ��
//��9ֻ���ӣ��ų�1��ԲȦ��
//����8ֻ������װ��8ֻ���죬��һ���ǿ��̡�
//���ǰ���Щ����˳ʱ����Ϊ 1~8
//
//ÿֻ���춼�����������ڵĿ����У�
//Ҳ�������õ�����Խ��һ�����ڵ��������������С�
//
//�������һ�£����Ҫʹ�������ǵĶ��θ�Ϊ������ʱ�����У�
//���ұ��ֿ��̵�λ�ò��䣨Ҳ����1 - 8��λ��2 - 7��λ, ...��������Ҫ�������ٴ���Ծ��

#include<stdio.h>

int a[9] = { 0 };
int count = 0;
int i = 0;

void Init(int* a)
{
	for (i = 0; i < 9; i++)
	{
		a[i] = i;
	}
}

int judge(int* a)
{
	int n = 0;
	int m = 8;
	for (n = 8; n >1; n--)
	{
		if (a[n] != a[n-1]-1)
		{
			return 0;
		}
		m--;
	}
	return 1;
}

void slove()
{
	int j = 0;
	int k = 0;
	while (1)
	{
		i = (k + 7) % 9;
		j = (k + 8) % 9;
		if (a[k] == 0)
		{
			if (a[i] < a[j])
			{
				a[k] = a[i];
				a[i] = 0;
				count++;
			}
			else if (a[i] - a[j]==1)
			{
				a[k] = a[j];
				a[j] = a[i];
				a[i] = 0;
				count++;
			}
			int n = 0;
			for (n = 0; n < 9; n++)
			{
				printf("%d ", a[n]);
			}
			printf("\n");
			if (judge(a))
			{
				break;
			}
		}
		k = i;
	}
}

int main()
{
	Init(a);
	slove();
	printf("%d", count);
	return 0;
}