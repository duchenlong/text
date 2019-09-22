#define _CRT_SECURE_NO_WARNINGS 1
//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个。
//嫌疑犯的一个。以下为4个嫌疑犯的供词。
//A说：不是我。
//B说：是C。
//C说：是D。
//D说：C在胡说
//已知3个人说了真话，1个人说的是假话。
//现在请根据这些信息，写一个程序来确定到底谁是凶手。

#include<stdio.h>
int main()
{
	char a;
	char c;
	char b;
	char d;
	char kill;
	for (kill = 'a'; kill <= 'd'; kill++)
	{
		if (((kill != 'a') + (kill == 'c') + (kill == 'd') + (kill != 'd') )== 3)
		{
			printf("%c是犯罪嫌疑人\n",kill);
		}
	}
	return 0;
}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	for (a = 0; a < 2; a++)
//	{
//		for (b = 0; b < 2; b++)
//		{
//			if (a ==1&& b == 1)
//			{
//				continue;
//			}
//			for (c = 0; c < 2; c++)
//			{
//				if ((c ==1&& a == 1) || (b ==1&& c == 1))
//				{
//					continue;
//				}
//				for (d = 0; d < 2; d++)
//				{
//					if ((a == 1 && c == 1 && d == 1) || (a == 0 && c == 0 && d == 1 && d == 0) || (a == b == d == 0 && c == 1))
//					{
//						if (a == 1)
//						{
//							printf("a是罪犯\n");
//						}
//						if (b == 1)
//						{
//							printf("b是罪犯\n");
//						}
//						if (c == 1)
//						{
//							printf("c是罪犯\n");
//						}
//						if (d == 1)
//						{
//							printf("d是罪犯\n");
//						}
//					}
//				}
//			}
//		}
//	}
//}


#if 0
#include<stdio.h>
//杨辉三角
int main()
{
	int n = 5;
	int i = 0,j=0;
	int a[5][5] = {  0 };
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (i == j || j == 0)
			{
				a[i][j] = 1;
			}
			else if (i>1)
			{
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}











#include<stdio.h>
//5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果
//A选手说：B第二，我第三；
//B选手说：我第二，E第四；
//C选手说：我第一，D第二；
//D选手说：C最后，我第三；
//E选手说：我第四，A第一；
//比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	for (a = 1; a <= 5; a++)
	{
		
		for (b = 1; b <= 5; b++)
		{
			if (a == b)
			{
				continue;
			}
			for (c = 1; c<= 5;c++)
			{
				if (a == c||b==c)
				{
					continue;
				}
				for (d = 1; d <= 5; d++)
				{
					if (a == d||b==d||c==d)
					{
						continue;
					}
					for (e = 1;e <= 5; e++)
					{
						if (a == e||b==e||c==3||d==e)
						{
							continue;
						}
						if ((((a == 3) + (b == 2))==1)&&
							(((b == 2) + (e == 4))==1)&&
							(((e == 4) +( a == 1))==1)&&
							(((c == 1) + (d == 2))==1)&&
							(((d == 3) + (c == 5)==1)))//(c == 1 && d == 2) || (c != 1 && d != 2) || (d != 3 && c != 5) || (d == 3 && c == 5)
						{
							printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
						}
							
					}
				}
			}
		}
	}
	return 0;
}
#endif