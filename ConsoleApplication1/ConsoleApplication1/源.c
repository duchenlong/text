#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//[left,right]
int BinarySearch(int* a, int left, int right, int x)
{
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == x)
		{
			return mid;
		}
		else if (a[mid] > x)
		{
			right = mid + 1;
		}
		else
		{
			left = mid - 1;
		}
	}
	return -1;
}


//[left,right)
int BinarySearch2(int* a, int left, int right, int x)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (a[mid] == x)
		{
			return mid;
		}
		else if (a[mid] > x)
		{
			right = mid;
		}
		else
		{
			left = mid+1;
		}
	}
	return -1;
}


int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	//int pit=BinarySearch1(a, 0, sizeof(a) / sizeof(a[0]), 4);
	int pit = BinarySearch2(a, 0, sizeof(a) / sizeof(a[0])+1, 11);
	printf("%d\n",pit);
	return 0;
}