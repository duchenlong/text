#include<stdio.h>

double max(double a,double b)
{
	return a>b?a:b;
}

double min(double a,double b)
{
	return a<b?a:b;
}

int main()
{
	double x1,y1,x2,y2;
	double x3,y3,x4,y4;
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	scanf("%lf%lf%lf%lf",&x3,&y3,&x4,&y4);
	
	double m1,m2,n1,n2;
	
	m1=min(max(x1,x2),max(x3,x4));
	m2=max(min(x1,x2),min(x3,x4));
	n1=min(max(y1,y2),max(y3,y4));
	n2=max(min(y1,y2),min(y3,y4));
	
	if(m1>m2&&n1>n2)
	{
		printf("%.2lf\n",(m1-m2)*(n1-n2));
	}
	else
	{
		printf("0.00\n");
	}
	return 0;	
} 
