#define _CRT_SECURE_NO_WARNINGS 1

//���⣺�Թ�
//
//X�����һ���Թ����ֳ�����ĳ��Сɽ���ϡ�
//������10x10�໥��ͨ��С������ɵġ�
//
//����ĵذ���д��һ���ܴ����ĸ��
//���Ǽ���������泯���µķ���վ������
//L��ʾ�ߵ���ߵķ��䣬
//R��ʾ�ߵ��ұߵķ��䣬
//U��ʾ�ߵ����·���ķ��䣬
//D��ʾ�ߵ����·���ķ��䡣
//
//X����ľ����е�������Ը�����˼����
//���Ǹ�ϲ�������������Ϸ�������ϷҲ����ˣ�
//
//��ʼ��ʱ��ֱ������100����ҷ���һ����С�����ڡ�
//���һ��Ҫ���յ��ϵ���ĸ�ƶ���
//
//�Թ���ͼ���£�
//------------
//UDDLUULRUL
//UURLLLRRRU
//RRUURLDLRD
//RUDDDDUUUU
//URUDLLRRUU
//DURLRLDLRL
//ULLURLLRDU
//RDLULLRDDD
//UUDDUDUDLL
//ULRDLUURRR
//------------
//
//�������һ�£�����ж�����һ��߳��Թ� ?
//����������߶�Ȧ�ӡ�
//
//���ύ����������ʾ�߳��Թ��������Ŀ����Ҫ��д�κζ��������

#include<stdio.h>
#include<string.h>

char* arr = "UDDLUULRULUURLLLRRRURRUURLDLRDRUDDDDUUUUURUDLLRRUUDURLRLDLRLULLURLLRDURDLULLRDDDUUDDUDUDLLULRDLUURRR";
int i = 0;
int j = 0;
char a[10][10];
int ans = 0;
int visit[10][10];

int walk(const int people)
{
	memset(visit,0,sizeof(visit));
	int x = people / 10;
	int y = people % 10;
	while (1)
	{
		if (visit[x][y])
		{
			return 0;
		}
		visit[x][y] = 1;
		switch (a[x][y])
		{
		case 'L':
			--y;
			break;
		case 'R':
			++y;
			break;
		case 'U':
			--x;
			break;
		case 'D':
			++x;
			break;
		}
		if (x<0 || x>9 || y<0 || y>9)
		{
			return 1;
		}
	}
}

void slove()
{
	int people = 1;
	for (people = 1; people <= 100; people++)
	{
		if (walk(people))
		{
			ans++;
		}
	}
}

int main()
{
	int count = 0;
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			a[i][j] = arr[count];
			count++;
		}
	}
	slove();
	printf("%d", ans);
	return 0;
}