#define _CRT_SECURE_NO_WARNINGS 1


//���⣺�Ȳ�������
//
//2, 3, 5, 7, 11, 13, ....���������С�
//���ƣ�7, 37, 67, 97, 127, 157 ������ȫ��������ɵĵȲ����У��еȲ��������С�
//�ϱߵ����й���Ϊ30������Ϊ6��
//
//2004�꣬�����뻪������������֤���ˣ��������ⳤ�ȵ������Ȳ����С�
//������������һ��˵ĳɹ���
//
//����һ����Ϊ����������������еļ�������������ĵ�������
//
//����Ϊ10�ĵȲ������У��乫����Сֵ�Ƕ��٣�

#include<stdio.h>

int judge(int num)
{
	int i = 0;
	if (num == 2 || num == 3)
	{
		return 1;
	}
	else if ((num % 6 != 5) && (num % 6 != 1))
	{
		return 0;
	}
	for (i = 5; i <= num/2; i+=6)
	{
		if ((num % i == 0) || (num % (i + 2) == 0))
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i = 0;
	int a[10000] = { 0 };
	int b[10] = { 0 };
	int j = 0;
	int k = 0;
	for (i = 2; i < 100000; i++)
	{
		if (judge(i))
		{
			a[j] = i;
			j++;
		}
	}
	int n = 0;
	int count = j;
	for (i = 0; i < count; i++)//a[i]��ʾ����
	{
		for (n = 1; n < 1000; n++)//6*n   ��ʾ����
		{
			k = 1;
			b[0] = a[i];
			//j��ʾ������������9����
			for (j = 1; j < 10; j++)
			{
				int num = a[i] + n*6* (j + 1);
				if (judge(num))
				{
					b[k] = num;
					k++;
				}
				else
				{
					break;
				}
			}
			if (k == 10)
			{
				for (i = 0; i <k; i++)
				{
					printf("%d ", b[i]);
				}
				printf("\n%d\n", 6 * n);
				return 0;
			}
		}
		
	}
	return 0;
}