#define _CRT_SECURE_NO_WARNINGS 1
//��������������
//
//����һ�ּ򵥵�������ʽ��
//ֻ�� x() | ��ɵ�������ʽ��
//С����������������ʽ�ܽ��ܵ���ַ����ĳ��ȡ�
//
//����((xx | xxx)x | (x | xx))xx �ܽ��ܵ���ַ����ǣ� xxxxxx��������6��
//
//����
//----
//һ����x() | ��ɵ�������ʽ�����볤�Ȳ�����100����֤�Ϸ���
//
//���
//----
//���������ʽ�ܽ��ܵ���ַ����ĳ��ȡ�
//
//���磬
//���룺
//((xx | xxx)x | (x | xx))xx
//
//����Ӧ�������
//6
//
//��ԴԼ����
//��ֵ�ڴ����ģ���������� < 256M
//CPU����  < 1000ms

#include<stdio.h>
#include<string.h>

int len = 0;
char* str;
int visit = 0;
int num = 0;
int flag = 0;

int Fun()
{
	int i = 0;
	int ans = 0;
	while (visit<len - 1)
	{
		if (str[visit] == 'x')
		{
			++visit;
			ans++;
		}
		else if (str[visit] == '(')
		{
			flag = 1;
			++visit;
			ans += Fun();
			flag = 0;
		}
		else if (str[visit] == '|')
		{
			++visit;
			if (num<ans)
			{
				num = ans;
			}
		}
		if ((str[visit]) == ')')
		{
			++visit;
			break;
		}
	}
	if ((visit<len-1) && (flag == 0))
	{
		Fun();
	}
	return ans;
}

int main()
{
	str= "((xx|xxxx|x)|(xx))xx";
	len = strlen(str);
	Fun();
	printf("%d",num);
	return 0;
}