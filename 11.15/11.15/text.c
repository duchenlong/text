#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main() {
	int n, i = 0, sum = 0, sum2 = 0;
	scanf("%d", &n);
	while (sum2 <n)
	{
		i++;
		sum2 += sum + 1;
		sum += i;
		printf("%3d %3d %3d\n", sum, sum2, i);
	}
	printf("%d", i);
	return 0;
}