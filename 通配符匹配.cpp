
//给定一个字符串?(s) 和一个字符模式?(p) ，实现一个支持?'?'?和?'*'?的通配符匹配。
//
//'?' 可以匹配任何单个字符。
//'*' 可以匹配任意字符串（包括空字符串）。
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//动态规划 
bool isMatch1(char * s, char * p){
    int lens = strlen(s);
    int lenp = strlen(p);

    int i = 0;
    int j = 0;
    int** dp = (int**)malloc(sizeof(int*) * (lens + 1));
    for(i = 0; i <= lens; i++)
    {
        dp[i] = (int*)calloc((lenp + 1),sizeof(int));
    }

    dp[0][0] = true;
    for(i = 0; i < lenp; i++)
    {
        if(p[i] == '*')
        {
            dp[0][i+1] = true;
        }
        else
        {
            break;
        }
    }

    for(i = 1; i <= lens; i++)
    {
        for(j = 1; j <= lenp; j++)
        {
            if(p[j-1] == s[i-1] || p[j-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(p[j-1] == '*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[lens][lenp];
}


//回溯 
bool isMatch(char * s, char * p){
    int lens = strlen(s);
    int lenp = strlen(p);

    int i = 0;
    int j = 0;
    int start = -1;
    int k = 0;

    while(i < lens)
    {
        if(s[i] == p[j] || p[j] == '?')
        {
            i++;
            j++;
            continue;
        }

        if(p[j] == '*')
        {
            start = j;
            j++;
            k = i;
            continue;
        }
		// 如果没有一样的，回溯到 k + 1，即让 * 再多吞噬一个字符。
        if(start != -1)
        {
            i = ++k;
            j = start + 1;
            continue;
        }
        return false;
    }

    while(j < lenp && p[j] == '*')
    {
        j++;
    }

    return j == lenp;
}

int main()
{
	printf("%d\n",isMatch("adceb","*a*b"));
	
	printf("%d",isMatch1("adceb","*a*b"));
	
	return 0;	
} 
