#define _CRT_SECURE_NO_WARNINGS 1

#if 0
//��������
//
//ĳ������ʶһ���ѡ�
//���ʼ�����ʱ����������˵��
//���ҵ������Ǹ�2λ�����ұȶ��Ӵ�27��,
//������ҵ��������λ���ֽ���λ�ã��պþ����Ҷ��ӵ����䡱
//
//������㣺���ѵ�����һ���ж����ֿ��������
//
//��ʾ��30���������һ�ֿ���Ŷ.
//
//����д��ʾ���������������
//ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�

#include<stdio.h>

int main()
{
	int age = 2;
	int num = 0;
	for (age = 2; age < 73; age++)
	{
		if ((age % 10 * 10 + age / 10)==age+27)
		{
			num++;
			//printf("age=%2d,age+27=%2d\n", age, age + 27);
		}
	}
	printf("%d\n", num);
	return 0;
}
#endif

//��������
//
//ĳ����ĳ�꿪ʼÿ�궼�ٰ�һ������party������ÿ�ζ�Ҫ��Ϩ��������ͬ����������
//
//��������������һ����Ϩ��236������
//
//���ʣ����Ӷ����꿪ʼ������party�ģ�
//
//����д����ʼ������party����������
//ע�⣺���ύ��Ӧ����һ����������Ҫ��д�κζ�������ݻ�˵�������֡�
#if 0
#include<stdio.h>

//int main()
//{
//	int age = 100;
//	int count = 0;
//	for (age = 100;age>0; age--)
//	{
//		int num = 236;
//		count = age;
//		while (num>count)
//		{
//			num = num - count;
//			count = count - 1;
//			if (num == count)
//			{
//				printf("%d\n", count);
//				break;
//			}
//		}
//	}
//	return 0;
//}

int main()
{
	int age = 1;
	int count = 0;
	for (age = 1;age<236; age++)
	{
		int num = 236;
		count = age;
		int n = 0;
		while (num > n)
		{
			n += count;
			count++;
		}
		if (n == num)
		{
			printf("%d\n", age);
		}
	}
	return 0;
}
#endif
