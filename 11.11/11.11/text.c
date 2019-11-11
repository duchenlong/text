#define _CRT_SECURE_NO_WARNINGS 1
//���⣺��������
//
//С����������һ����ʷ���ס���Щ��ʷ�����г����˺ܶ����ڡ�С��֪����Щ���ڶ���1960��1��1����2059��12��31�ա�
//��С��ͷ�۵��ǣ���Щ���ڲ��õĸ�ʽ�ǳ���ͳһ��
//�в����� / �� / �յģ�
//�в����� / �� / ��ģ�
//���в����� / �� / ��ġ�
//�����鷳���ǣ����Ҳ��ʡ����ǰ��λ��ʹ�������ϵ�һ�����ڣ����ںܶ���ܵ����������Ӧ��
//
//����02 / 03 / 04��������2002��03��04�ա�2004��02��03�ջ�2004��03��02�ա�
//
//����һ�������ϵ����ڣ����ܰ���С���ж�����Щ���ܵ����ڶ����Ӧ��
//
//����
//----
//һ�����ڣ���ʽ��"AA/BB/CC"��(0 <= A, B, C <= 9)
//
//����
//----
//������ɸ�����ͬ�����ڣ�ÿ������һ�У���ʽ��"yyyy-MM-dd"��������ڰ����絽�����С�
//
//��������
//----
//02 / 03 / 04
//
//�������
//----
//2002 - 03 - 04
//2004 - 02 - 03
//2004 - 03 - 02
//
//��ԴԼ����
//��ֵ�ڴ����ģ���������� < 256M
//CPU����  < 1000ms

#include<stdio.h>
#include<string.h>

int arr[13][2] = { {0,0},{ 31, 31 }, { 28, 29 }, { 31, 31 }, { 30, 30 }, \
                       { 31, 31 }, { 30, 30 }, { 31, 31 }, { 31, 31 }, \
                       { 30, 30 }, { 31, 31 }, { 30, 30 }, { 31, 31 } };
int a[3] = { 0 };
char b[3][15] = { '\0' };

int JudgeYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}

int JudgeMonth(int month)
{
	if (month > 12||month==0)
	{
		return 0;
	}
	return 1;
}

void judegYMD(int year, int month, int day,int j)
{
	if (JudgeMonth(month))
	{
		if (year >= 60)
		{
			year += 1900;
		}
		else
		{
			year += 2000;
		}
		int i = JudgeYear(year);
		if (day > arr[i][month])
		{
			return;
		}
		int k = 3;
		while (year)
		{
			b[j][k] = (year % 10) + '0';
			k--;
			year /= 10;
		}
		b[j][4] = '-';
		if (month < 10)
		{
			b[j][5] = '0';
			b[j][6] = month + '0';
		}
		else
		{
			k = 6;
			while (month)
			{
				b[j][k] = (month % 10) + '0';
				k--;
			}
		}
		b[j][7] = '-';
		if (day < 10)
		{
			b[j][8] = '0';
			b[j][9] = day + '0';
		}
		else
		{
			k = 9;
			while (day)
			{
				b[j][k] = (month % 10) + '0';
				k--;
			}
		}
	}
	return;
}

int main()
{
	int i = 0,k=0,j=0;
	scanf("%d/%d/%d", &a[0], &a[1], &a[2]);
	judegYMD(a[0],a[1],a[2],0);
	judegYMD(a[2], a[0], a[1],1);
	judegYMD(a[2], a[1], a[0],2);
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3 - i - 1; j++)
		{
			if (strcmp(b[j], b[j+1]) == 1)
			{
				char* src='\0';
				strcpy(src, b[j]);
				strcpy(b[j], b[i]);
				strcpy(b[i], src);
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (b[i][0] != '0')
		{
			puts(b[i]);
		}
	}
	return 0;
}