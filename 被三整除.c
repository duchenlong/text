#include <stdio.h>

//小Q得到一个神奇的数列: 1, 12, 123,...12345678910,1234567891011...。
//
//并且小Q对于能否被3整除这个性质很感兴趣。
//
//小Q现在希望你能帮他计算一下从数列的第l个到第r个(包含端点)有多少个数可以被3整除。
 
/*
int main()
{
    int l,r;
    scanf("%d%d",&l,&r);
     
    long long i = 0;
    int num = 0;
    for(i = 1; i < l; i++)
    {
        long long count = i;
        while(count)
        {
            num += count%10;
            count /= 10;
            num %= 3;
        }
    }
     
    int ans = 0;
    for(i = l; i <= r; i++)
    {
        long long count = i;
        while(count)
        {
            num += count%10;
            count /= 10;
            num %= 3;
        }
        if(num == 0)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
*/
 
int main()
{
    int l,r;
    scanf("%d%d",&l,&r);
     
    int i = 0;
    int ans = 0;
    // 1 2 0 1 2 0 1 2  对三取余后的结果 
    // 如果是0，说明改数可以被三整除
	// 如果是2,2再加上前面取余的1，也可以被3整除
	//所以说，只要该数对3取余后，结果不是1，就可以被三整除 
    for(i = l; i <= r; i++)
    {
        if(i % 3 != 1)
        {
            ans++;
        }
    }
     
    printf("%d\n",ans);
     
    return 0;
}
