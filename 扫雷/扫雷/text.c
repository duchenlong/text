#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

//��ӡ�˵�
void menu()
{
	printf("**********************************\n");
	printf("************ 0.�˳� **************\n");
	printf("************ 1.��Ϸ **************\n");
	printf("**********************************\n");
}

//��ʼ��Ϸ
void game()
{
	//����׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//�Ų��׵���Ϣ---��û���Ų�����Ļ���ӡ
	char mineInfo[ROWS][COLS] = { 0 };
	//��û�в�����
	InitBorad(mine, ROWS, COLS, '0');
	//��û���Ų����ʱ�����
	InitBorad(mineInfo, ROWS, COLS, '*');
	//��ӡ����
	show(mineInfo, ROWS, COLS);
    //�����׵�λ��
	SetMine(mine, ROW, COL, '*');
	//��ӡ��ά����
	//show(mine, ROWS, COLS);//��ӡ�׵�λ��
	show(mineInfo, ROWS, COLS);//��ӡ��ʾ�����еķֲ�
	//ɨ��
	FindMine(mine, mineInfo, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//�����������
	do
	{
		menu();//��ӡ�˵�
		printf("���������ѡ��:  ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������ȷ�����֣�\n");
			break;
		}
	} while (input);
	return 0;
}