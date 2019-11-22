#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
void mov(char p1, int n, char p2)
{
	printf("%c->%c ", p1, p2);
}
void Fun(int n, char p1, char p2, char p3)
{
	if (n == 1)
	{
		mov(p1, 1, p3);
	}
	else
	{
		Fun(n - 1, p1, p3, p2);
		mov(p1, n - 1, p2);
		Fun(n - 1, p2, p1, p3);
	}
}
int main()
{
	Fun(8, 'A', 'B', 'C');
	return 0;
}