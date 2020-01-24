/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
int Binary(int num,int left,int right,int* arr)
{
    int mid = 0;
    while(left <= right)
    {
        mid  = (left + right) / 2;
        if(arr[mid] == num)
        {
            return mid;
        }
        else if(arr[mid] > num)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* a = (int*) malloc (sizeof(int) * 2);
    *returnSize = 2;
    int count = Binary(target,0,numsSize-1,nums);
    if(count == -1)
    {
        a[0] = -1;
        a[1] = -1;
    }
    else
    {
        //left
        int left = count;
        int right = count;
        while(1)
        {
            int n = left;
            left = Binary(target,0,left - 1,nums);
            if(left == -1)
            {
                a[0] = n;
                break;
            }
        }

        //right
        while(1)
        {
            int n = right;
            right = Binary(target,right+1,numsSize-1,nums);
            if(right == -1)
            {
                a[1] = n;
                break;
            }
        }
    }
    return a;
}
int main()
{
	int nums[] = {1,2,2,5,6,8,8,8,9};
	int numsize = sizeof(nums) / sizeof(nums[0]);
	int retrunsize = 0;
	int t = 8;
	int* a=searchRange(nums,numsize,t,&retrunsize);
	int i = 0;
	for(i = 0;i<retrunsize;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
