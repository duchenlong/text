#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

char in[100] = { 0 };
char post[100] = { 0 };
char pre[100] = { 0 };
int n = 0;

void Slove(int postl, int postr, int inl, int inr)
{
	if (postl > postr)
	{
		return;
	}

	if (inl > inr)
	{
		return;
	}

	pre[n++] = post[postr];

	int k;
	for (k = inl; k <= inr; k++)
	{
		if (in[k] == post[postr])
		{
			break;
		}
	}
	/*if (k == postl)
	{
		return;
	}*/
	int num = k - inl;

	Slove(postl, postl + num - 1, inl, k - 1);
	Slove(postl + num, postr - 1, k + 1, inr);
}

int main()
{
	scanf("%s", in);
	scanf("%s", post);

	int leni = strlen(in);
	int lenpo = strlen(post);

	Slove(0, lenpo - 1, 0, leni - 1);

	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%c ", pre[i]);
	}
	return 0;
}