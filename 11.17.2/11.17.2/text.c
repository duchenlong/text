#define _CRT_SECURE_NO_WARNINGS 1

//������������ a, b, c�����һ�������Ȳ��� a ��������Ҳ���� b �������������� c �������������������Ϊ��������
//������ 1 �� n ���ж��ٸ���������
#if 0
#include<stdio.h>

int main()
{
	int n, a, b, c;
	int ans = 0;
	int i = 0;
	scanf("%d", &n);
	scanf("%d%d%d", &a, &b, &c);
	for (i = 1; i <= n; i++)
	{
		if (i%a == 0 || i%b == 0 || i%c == 0)
		{
			continue;
		}
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
#endif

//��һ��8x8�Ĺ����������̵����ϽǷ�һö���ӣ�ÿһ��ֻ�����������һ������ƶ�һ�񣬲������Ƴ����̣�14������ƶ������̵����½ǡ�
//���ʱ��ʲ�ͬ���ƶ������ж����֣�
//�����ƶ�������Ϊ���ʲ�ͬ�ģ���ָ�����ַ��������ٴ���ĳһ����һ�ַ������������ߣ�һ�ַ������������ߡ�

#if 0
#include<stdio.h>

int ans = 0;
int a[8][8] = { 0 };
int div[2][2] = { { 0, 1 }, { 1,0 } };

void slove()
{
	if (a[7][7])
	{
		ans++;
	}
}

void dfs(int index, int x, int y)
{
	if (index == 15)
	{
		slove();
		return;
	}
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		int tx = x + div[i][0];
		int ty = y + div[i][1];
		if (tx>7 || ty > 7)
		{
			continue;
		}
		if (!a[tx][ty])
		{
			a[tx][ty] = 1;
			dfs(index + 1, tx, ty);
			a[tx][ty] = 0;
		}
	}
}

int main()
{
	a[0][0] = 1;
	dfs(1,0,0);
	printf("%d\n", ans);
}
#endif

//С����һ��յأ��������յػ���Ϊ n �� m �е�С�飬ÿ�к�ÿ�еĳ��ȶ�Ϊ 1��
//С��ѡ�����е�һЩС��յأ������˲ݣ�����С����Ȼ�����ǿյء�
//��Щ�ݳ��úܿ죬ÿ���£��ݶ������ⳤ��һЩ�����һ��С�����˲ݣ����������Լ����ϡ��¡�������С��յ���չ������С��յض�����Ϊ�вݵ�С�顣
//�����С����k ���º�յ�����Щ�ط��вݡ�

#include<stdio.h>

char a[1050][1050] = { '\0' };
char b[1050][1050] = { '\0' };
int div[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
int n=0, m=0;
int k = 0;

void visit(int x,int y)
{
	int tx = 0;
	int ty = 0;
	int i = 0,j=0;
	for (i = 0; i < 4; i++)
	{
		tx = x + div[i][0];
		ty = y + div[i][1];
		if (tx < 0 || tx >= n || ty < 1 || ty > m)
		{
			continue;
		}
		b[tx][ty] = 'g';
	}
	
}

void slove()
{
	int i = 0;
	int j = 0;
	while (k--)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (a[i][j] == 'g')
				{
					visit(i,j);
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				a[i][j] = b[i][j];
			}
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			scanf("%c", &a[i][j]);
			b[i][j] = a[i][j];
		}
	}
	scanf("%d", &k);
	slove();
	for (i = 0; i < n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}