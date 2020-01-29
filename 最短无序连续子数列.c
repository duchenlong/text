#include <stdio.h>

int findUnsortedSubarray(int* nums, int numsSize){
    int left = 0;
    int right = numsSize;
    int i = 0;
    int j = 0;
    for(left = 0; left < numsSize - 1; left++)
    {
        for(j = left + 1; j < numsSize; j++)
        {
            if(nums[left] > nums[j])
            {
                break;
            }
        }
    
        if(j < numsSize && nums[left] > nums[j])
        {
            break;
        }
    }

    for(right = numsSize; right > left; right--)
    {
        for(j = right - 1; j > left; j--)
        {
            if(nums[right-1] < nums[j-1])
            {
                break;
            }
        }
        if(j>left && nums[right - 1] < nums[j - 1])
        {
            break;
        }
    }
    return right - left;
}

int main()
{
	int arr[] = {2, 6, 4, 8, 10, 9, 15};
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d ",findUnsortedSubarray(arr,len));
	
	return 0;
}
