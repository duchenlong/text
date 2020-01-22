#include <stdio.h>

void sort(int* arr,int len)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < len - 1; i++)
    {
        for(j = 0; j < len - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int thirdMax(int* nums, int numsSize){
    int arr[3] = {0};
    int i = 0,j = -1, k = 0;
    int len = 0;
    for(i = 0; i < 3 && numsSize > i && numsSize > (j + 1); i++)
    {
        j++;
        int flag = 0;
        for(k = 0; k < len; k++)
        {
            if(arr[k] == nums[j])
            {
                i--;
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            continue;
        }
        arr[i] = nums[j];
        len++;
    }
    sort(arr,len);
    
    for(i = j + 1; i < numsSize; i++)
    {
        for(j = 2; j >= 0; j--)
        {
            if(arr[j] == nums[i])
            {
                break;
            }
            if(arr[j] < nums[i])
            {
                for(k = 0; k < j; k++)
                {
                    arr[k] = arr[k + 1];
                }
                arr[j] = nums[i];
                break;
            }
        }
    }

    if(len < 3)
    {
        return arr[len - 1];
    }
    else
    {
        return arr[0];
    }
}

int main()
{
	int arr[] = {1,-2147483647,2,5,5};
	printf("%d\n",thirdMax(arr,5));
	return 0;
}
