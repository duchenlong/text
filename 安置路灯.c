#include <stdio.h>

//小Q正在给一条长度为n的道路设计路灯安置方案。
//
//为了让问题更简单,小Q把道路视为n个方格,需要照亮的地方用'.'表示, 不需要照亮的障碍物格子用'X'表示。
//
//小Q现在要在道路上设置一些路灯, 对于安置在pos位置的路灯, 这盏路灯可以照亮pos - 1, pos, pos + 1这三个位置。
//小Q希望能安置尽量少的路灯照亮所有'.'区域, 希望你能帮他计算一下最少需要多少盏路灯。 


int ans[1005] = {0};
int len = 0;
 
int slove(char* str,int l)
{
    int num = 0;
    int i = 0;
    while(i < l)
    {
        if(str[i] == '.')
        {
            num++;
            i += 2;
        }
        i++;
    }
    return num;
}
 
int main()
{
    int t;
    scanf("%d",&t);
     
    while(t--)
    {
        int l;
        scanf("%d",&l);
        char str[1005] = {'\0'};
        scanf("%s",str);
         
        ans[len++] = slove(str,l);
    }
     
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d\n",ans[i]);
    }
    return 0;
}
