#define _CRT_SECURE_NO_WARNINGS 1
#if 0
//һ��������Ϊ����������������ָ����1������������Լ���⣬û��������Լ����
//������10000�����У����������Ƕ��� ?
#include<stdio.h>

int judege(int num)
{
	int i = 2;
	for (i = 2; i < num / 2; i++)
	{
		if (num%i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int num = 10000;
	for (num = 10000; num > 0; num--)
	{
		if (judege(num))
		{
			printf("%d", num);
			break;
		}
	}
	return 0;
}
#endif

#if 0
//����һ�����ʣ��������������е�һ�����ֵ�Ԫ����ĸ��
//Ԫ����ĸ���� a, e, i, o, u���������
#include<stdio.h>

int main()
{
	char str = '\0';
	char ch='\0';
	int flag = 0;
	scanf("%c", &ch);
	while (ch>='a'&&ch<='z')
	{
		if (((ch == 'a') || (ch == 'o') || (ch == 'e') || (ch == 'i') || (ch == 'u'))&&(flag==0))
		{
			flag = 1;
			str = ch;
		}
		scanf("%c", &ch);
	}
	if (flag == 1)
	{
		printf("%c\n", str);
	}
	else
	{
		printf("n\n");
	}
	return 0;
}
#endif

//
//С���ǳ���ϲ������ 2��������Щ��λ�ϰ������� 2 ���������һ��������λ���������� 2��С��������Ϊ�ྻ����
//���������� 1 �� n �У��ྻ���ж��ٸ���
#include<stdio.h>

int main()
{
	int i = 0;
	int ans = 0;
	int n = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		int num = i;
		while (num)
		{
			if (num % 10 == 2)
			{
				break;
			}
			num /= 10;
		}
		if (!num)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return  0;
}