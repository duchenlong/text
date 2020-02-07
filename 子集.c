#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = pow(2,numsSize);
    int** arr = (int**)malloc(sizeof(int*) * (*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int*) * (*returnSize));
    *returnSize--;
    int i = 0;
    int col = 0; //ÁÐ
    int row = 0; //ÐÐ
    returnColumnSizes[0][row++] = 0;
    for(i = 0; i < numsSize; i++)
    {
        int j = 0;
        int num = row;
        arr[row] = (int*)malloc(sizeof(int));
        arr[row][0] = nums[i];
        returnColumnSizes[0][row++] = 1;
        for(j = 1; j < num; j++)
        {
            int row_size = returnColumnSizes[0][j];
            arr[row] = (int*)malloc(sizeof(int) * (row_size + 1));
            memcpy(arr[row],arr[j],row_size * sizeof(int));
            arr[row][row_size] = nums[i];
            returnColumnSizes[0][row++] = row_size + 1;
        }

    }
    
    return arr;
}

int main()
{
	int nums[3] = {1,2,3};
	int numsSize = 3;
	int row = 0;
	int* col;
	int** arr = subsets(nums,numsSize,&row,&col);
	int i,j;
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col[i]; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
