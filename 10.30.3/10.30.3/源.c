#define _CRT_SECURE_NO_WARNINGS 1

//����ʽ
//
//B      DEF
//A + -- - +------ - = 10
//C      GHI
//
//�������ʾ�����⣬���Բμ���ͼ1.jpg����
//
//
//�����ʽ��A~I����1~9�����֣���ͬ����ĸ����ͬ�����֡�
//
//���磺
//6 + 8 / 3 + 952 / 714 ����һ�ֽⷨ��
//5 + 3 / 1 + 972 / 486 ����һ�ֽⷨ��
//
//�����ʽһ���ж����ֽⷨ��
//
//ע�⣺���ύӦ���Ǹ���������Ҫ��д�κζ�������ݻ�˵�������֡�

#include<stdio.h>
#include<string.h>

int arr[10] = { 0 };
int ans = 0;
int my_arr[10] = { 0 };

void slove()
{
	double x = arr[1] + (double)arr[2] / arr[3] + (double)(arr[4] * 100 + arr[5] * 10 + arr[6]) / (arr[7] * 100 + arr[8] * 10 + arr[9]);
	if (x == 10)
	{
		ans++;
	}
}

void dfs(int index)
{
	if (index == 10)
	{
		slove();
		return;
	}
	int i = 0;
	for (i = 1; i < 10; i++)
	{
		if (!my_arr[i])
		{
			my_arr[i] = 1;
			arr[index] = i;
			dfs(index + 1);
			my_arr[i] = 0;
		}
	}
}

int main()
{
	dfs(1);
	printf("%d", ans);
	return 0;
}