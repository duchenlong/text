#include <stdio.h>

//СQ���ڸ�һ������Ϊn�ĵ�·���·�ư��÷�����
//
//Ϊ�����������,СQ�ѵ�·��Ϊn������,��Ҫ�����ĵط���'.'��ʾ, ����Ҫ�������ϰ��������'X'��ʾ��
//
//СQ����Ҫ�ڵ�·������һЩ·��, ���ڰ�����posλ�õ�·��, ��յ·�ƿ�������pos - 1, pos, pos + 1������λ�á�
//СQϣ���ܰ��þ����ٵ�·����������'.'����, ϣ�����ܰ�������һ��������Ҫ����յ·�ơ� 


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
