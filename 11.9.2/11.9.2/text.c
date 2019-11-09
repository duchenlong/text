#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	double money = 0.0;
	double a[100][2] = { 0 };
	int i = 0;
	int j = 0;
	while (1)
	{
		scanf("%lf%lf", &a[i][0], &a[i][1]);
		if (a[i][0] == 0)
		{
			break;
		}
		i++;
	}
	for (j = 0; j <= i; j++)
	{
		money+= a[j][0] * (a[j][1] * 0.01);
	}
	printf("%lf", money);
	return 0;
}