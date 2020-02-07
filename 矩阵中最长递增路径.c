#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int dfs(int** matrix, int matrixSize, int matrixColSize,int row,int col,int** dp)
{
    //上下左右四个方向
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    int i = 0;
    int j = 0;
    int path = 0;
    int max = 0;
    for(i = 0; i < 4; i++)
    {
        int x = row + dir[i][0];
        int y = col + dir[i][1];
        //判断是否出界
        if(x < 0 || x >= matrixSize || y < 0 || y >= matrixColSize)
        {
            continue;
        }

        //判断该方向是否满足递减
        if(matrix[x][y] >= matrix[row][col])
        {
            continue;
        }
        if(!dp[x][y])
        {
            dp[x][y] = dfs(matrix,matrixSize,matrixColSize,x,y,dp);
        }
        path = dp[x][y] + 1;
        if(path > max)
        {
            max = path;
        }
    }

    return max;
}

int longestIncreasingPath(int** matrix, int matrixSize, int matrixColSize){
    int** dp = (int**)malloc(sizeof(int*) * (matrixSize + 1));
    int i = 0;
    int j = 0;
    for(i = 0; i < matrixSize; i++)
    {
        dp[i] = (int*)malloc(sizeof(int) * matrixColSize);
        memset (dp[i], 0,matrixColSize * sizeof(int));
    }

    int path = 0;
    int max = 0;
    for(i = 0; i < matrixSize; i++)
    {
        for(j = 0; j < matrixColSize; j++)
        {
           if(!dp[i][j])
            {
                dp[i][j] = dfs(matrix,matrixSize,matrixColSize,i,j,dp);
            }
            path = dp[i][j] + 1;
            if(path > max)
            {
                max = path;
            }
        }
    }
    return max;
}

int main()
{
	int i = 0;
    int j = 0;
    int row,col;
    scanf("%d%d",&row,&col);
    int** dp = (int**)malloc(sizeof(int*) * row);
    
    for(i = 0; i < row; i++)
    {
        dp[i] = (int*)calloc(0,sizeof(int) * col);
    }
	for(i = 0; i < row; i++)
	{
		for(j = 0; j < col; j++)
		{
			scanf("%d",&dp[i][j]);
		}
	}
	
	

	printf("%d",longestIncreasingPath(dp,row,col));

	

	
	return 0;
} 
