#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#define N 5

int main()
{
	double x[N] = { 0.4 ,0.55,0.8,0.9,1};
	double count = 0.5;
	int i = 0;
	int k = 0;
	double m;
	while (i <3)
	{
		double a[N] = { 0.41075, 0.57815, 0.88811, 1.02652, 1.17520 };
		double cs = a[0];
		scanf("%lf", &count);
		for (k = 0; k<N - i - 1; k++)
		{
			a[k] = (a[k + 1] - a[k]) / (x[1] - x[0]);
		}
		m = a[0];
		for (k = 0; k<1; k++)
		{
			m *= (count - x[k]);
		}
		cs += m;
		printf("f(%.2lf)=%lf\n", count, cs);
		i++;
	}
	return 0;
}
