#include <stdio.h>
#include <math.h>

double a;
double b;
double c;
double d;
double arr[5] = {0};
int count = 0;

double fun1(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}

double fun2(double x)
{
	return 3 * a * x * x + 2 * b * x + c;
}

double (*f[3])(double) = {0,fun1,fun2};

double binary(double left,double right,int i)
{
	double mid = (left + right) / 2;
	double ans = (*f[i])(mid);
	double ans_left = (*f[i])(left);
	double ans_right = (*f[i])(right);
	if(fabs(ans_left) < 0.01)
	{
		return left;
	}
	
	if(ans_left * ans < 0)
	{
		return binary(left,mid,i);
	}
	else
	{
		return binary(mid,right,i);
	}
}

void slove()
{
	//二次求导的零点 
	double x31 = (-1 * b) / (3 * a);
	//一次求导的零点
	double x21 = binary(-100,x31,2);
	double x22 = binary(x31,100,2);
	//printf("%lf %lf %lf\n",x21,x22,x31);
	arr[0] = binary(-100,x21,1);
	arr[1] = binary(x21,x22,1);
	arr[2] = binary(x22,100,1);
}


int main()
{
	//printf("%d",1100.000000>=100.000000);
	scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
	double i;
	//遍历法 
	for(i = -100; i <= 100; i += 0.01)
	{
		if(count == 3)
		{
			break;
		}
		else if(fabs(fun1(i)) < 0.001) 
		{
			arr[count++] = i;
		}
	}
	
	//printf("%lf %lf %lf\n",arr[0],arr[1],arr[2]);
	//二分查找法 
	slove();
	printf("%.2lf %.2lf %.2lf",arr[0],arr[1],arr[2]);
	return 0;
}
