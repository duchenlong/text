#include <stdio.h>

//СQ�õ�һ�����������: 1, 12, 123,...12345678910,1234567891011...��
//
//����СQ�����ܷ�3����������ʺܸ���Ȥ��
//
//СQ����ϣ�����ܰ�������һ�´����еĵ�l������r��(�����˵�)�ж��ٸ������Ա�3������
 
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
    // 1 2 0 1 2 0 1 2  ����ȡ���Ľ�� 
    // �����0��˵���������Ա�������
	// �����2,2�ټ���ǰ��ȡ���1��Ҳ���Ա�3����
	//����˵��ֻҪ������3ȡ��󣬽������1���Ϳ��Ա������� 
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
