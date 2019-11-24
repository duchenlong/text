#define _CRT_SECURE_NO_WARNINGS 1

//���⣺��ӡͼ��
//
//���µĳ�����ڿ���̨���Ʒ���ͼ������������ֲ������Ƶ�ͼ�Σ���
//
//��n = 1, 2, 3��ʱ��������£�
//����ϸ�������򣬲���д���߲���ȱ�ٵĴ��롣
//
//n = 1ʱ��
//o
//ooo
//o
//
//n = 2ʱ��
//o
//ooo
//o
//o  o  o
//ooooooooo
//o  o  o
//o
//ooo
//o
//
//n = 3ʱ��
//o
//ooo
//o
//o  o  o
//ooooooooo
//o  o  o
//o
//ooo
//o
//o        o        o
//ooo      ooo      ooo
//o        o        o
//o  o  o  o  o  o  o  o  o
//ooooooooooooooooooooooooooo
//o  o  o  o  o  o  o  o  o
//o        o        o
//ooo      ooo      ooo
//o        o        o
//o
//ooo
//o
//o  o  o
//ooooooooo
//o  o  o
//o
//ooo
//o
//
//Դ����


#include <stdio.h>
#include <stdlib.h>

void show(char* buf, int w){
	int i, j;
	for (i = 0; i < w; i++){
		for (j = 0; j < w; j++){
			printf("%c", buf[i*w + j] == 0 ? ' ' : 'o');
		}
		printf("\n");
	}
}

void draw(char* buf, int w, int x, int y, int size){
	if (size == 1){
		buf[y*w + x] = 1;
		return;
	}

	//int n = _________________________; //���
	int n = size/3;
	draw(buf, w, x, y, n);
	draw(buf, w, x - n, y, n);
	draw(buf, w, x + n, y, n);
	draw(buf, w, x, y - n, n);
	draw(buf, w, x, y + n, n);
}

int main()
{
	int N = 1;
	int t = 1;
	int i;
	for (i = 0; i < N; i++) t *= 3;

	char* buf = (char*)malloc(t*t);
	for (i = 0; i < t*t; i++) buf[i] = 0;

	draw(buf, t, t / 2, t / 2, t);
	show(buf, t);
	free(buf);

	return 0;
}