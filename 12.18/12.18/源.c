#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


	void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
		if (m == 0 && n == 0)
		{
			return;
		}

		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;

		while (i >= 0 || j >= 0)
		{
			if (nums1[i] > nums2[j])
			{
				nums1[k--] = nums1[i--];
			}
			else
			{
				nums1[k--] = nums2[j--];
			}

		}

		while (j >= 0)
		{
			nums1[k--] = nums2[j--];
		}

	}

int main()
{
	int a[6] = { 1, 2, 3 };
	int b[3] = { 2, 5, 6 };
	merge(a, 6, 3, b, 3, 3);
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}