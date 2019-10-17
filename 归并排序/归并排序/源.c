#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//µ›πÈ–¥∑®
void sort(int left, int l1, int l2, int right, int a[10])
{
	int t[10] = { 0 };
	int x = 0, y = 0, i = 0, j = 0;
	while ((x <= l1 - left) && (y <= right - l2))
	{
		if (*(a + left + x) < *(a + l2 + y))
		{
			t[i] = a[left + x];
			x++;
		}
		else
		{
			t[i] = a[l2 + y];
			y++;
		}
		i++;
	}
	while (x <= l1 - left)
	{
		t[i] = a[left + x];
		x++;
		i++;
	}
	while (y <= right - l2)
	{
		t[i] = a[l2 + y];
		y++;
		i++;
	}
	for (j = 0; j < i; j++)
	{
		a[left + j] = t[j];
	}
}
void merge_sort_1(int* a, int left,int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		merge_sort_1(a, left, mid);
		merge_sort_1(a, mid + 1, right);
		sort(left, mid, mid + 1, right, a);
	}
}

int main()
{
	int a[10] = { 8, 5, 2, 1, 4, 7, 9, 6, 3, 10 };
	int i = 0;
	merge_sort_1(a, 0,9);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
#if 0
//∑«µ›πÈ–¥∑®
void sort(int left,int l1,int l2,int right,int a[10])
{
	int t[10] = { 0 };
	int x=0,y=0,i=0,j=0;
	while ((x <=l1 - left) && (y <=right - l2))
	{
		if (*(a + left + x) < *(a + l2 + y))
		{
			t[i] = a[left + x];
			x++;
		}
		else
		{
			t[i] = a[l2 + y];
			y++;
		}
		i++;
	}
	while (x <=l1 - left)
	{
		t[i] = a[left + x];
		x++;
		i++;
	}
	while (y <= right - l2)
	{
		t[i] = a[l2 + y];
		y++;
		i++;
	}
	for (j = 0; j < i;j++)
	{
		a[left+j] = t[j];
	}
}

int min(int left, int size, int len)
{
	if (left + size <= len)
	{
		return left + size-1;
	}
	return len-1;
}

void merge_sort(int* a,int len)
{
	int size= 2;
	int i = 0;
	for (size = 2; size / 2 <= len; size *= 2)
	{
		for (i = 0; i < len; i += size)
		{
			int mid = i + size / 2-1 ;
			if (mid+1<=len)
			{
				sort(i,mid, mid+1, min(mid+1, size / 2, len), a);
			}
		}
	}
}

int main()
{
	int a[10] = { 8, 5, 2, 1, 4, 7, 9, 6, 3, 10 };
	int i = 0;
	merge_sort(a,10);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
#endif