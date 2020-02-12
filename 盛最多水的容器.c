#include <stdio.h>

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

int maxArea(int* height, int heightSize){
    int left = 0;
    int right = heightSize - 1;
    int ans = 0;
    while(left < right)
    {
        ans = MAX(ans,MIN(height[left] , height[right]) * (right - left));
        if(height[left] < height[right])
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return ans;
}

int main()
{
	int arr[] = {1,8,6,2,5,4,8,3,7};
	printf("%d\n",maxArea(arr,sizeof(arr)/sizeof(arr[0])));
	
	return 0;	
} 
