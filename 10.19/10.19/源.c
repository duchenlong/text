#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//网友年龄
//
//某君新认识一网友。
//当问及年龄时，他的网友说：
//“我的年龄是个2位数，我比儿子大27岁,
//如果把我的年龄的两位数字交换位置，刚好就是我儿子的年龄”
//
//请你计算：网友的年龄一共有多少种可能情况？
//
//提示：30岁就是其中一种可能哦.
//
//请填写表示可能情况的种数。
//注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

#include<stdio.h>

int main()
{
	int age = 2;
	int num = 0;
	for (age = 2; age < 73; age++)
	{
		if ((age % 10 * 10 + age / 10)==age+27)
		{
			num++;
			//printf("age=%2d,age+27=%2d\n", age, age + 27);
		}
	}
	printf("%d\n", num);
	return 0;
}
#endif

//生日蜡烛
//
//某君从某年开始每年都举办一次生日party，并且每次都要吹熄与年龄相同根数的蜡烛。
//
//现在算起来，他一共吹熄了236根蜡烛。
//
//请问，他从多少岁开始过生日party的？
//
//请填写他开始过生日party的年龄数。
//注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。
#if 0
#include<stdio.h>

//int main()
//{
//	int age = 100;
//	int count = 0;
//	for (age = 100;age>0; age--)
//	{
//		int num = 236;
//		count = age;
//		while (num>count)
//		{
//			num = num - count;
//			count = count - 1;
//			if (num == count)
//			{
//				printf("%d\n", count);
//				break;
//			}
//		}
//	}
//	return 0;
//}

int main()
{
	int age = 1;
	int count = 0;
	for (age = 1;age<236; age++)
	{
		int num = 236;
		count = age;
		int n = 0;
		while (num > n)
		{
			n += count;
			count++;
		}
		if (n == num)
		{
			printf("%d\n", age);
		}
	}
	return 0;
}
#endif
