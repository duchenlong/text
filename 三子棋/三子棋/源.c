#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

#define ROW 3
#define COL 3

//��ӡ�˵�
void menu()
{
	printf("*****************************\n");
	printf("**********0.������Ϸ*********\n");
	printf("**********1.Ҫ����Ϸ*********\n");
	printf("*****************************\n");
}
//��Ϸ��ʼ
void game()
{
	int ret =0;
	char board[3][3] = { 0 };
	InitBoard(board, ROW, COL);
	ShowBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board);//����ƶ�
		ret = IsWin(board, ROW, COL);//�ж�����ƶ�����Һ͵��Ե���Ӯ���
		if (ret != 0)
		{
		break;
		}
		ShowBoard(board, ROW, COL);//��ӡ����ƶ��������
		printf("�����ƶ�\n");
		ComputerMove(board);//�����ƶ�
		ShowBoard(board, ROW, COL);//��ӡ�����ƶ��������
		ret = IsWin(board, ROW, COL);//�жϵ����ƶ�����Һ͵��Ե���Ӯ���
		if (ret != 0)
		{
		break;
		}
	}
		if (ret == 'x')
		{
			printf("ţ�ư�\n");
		}
		else if (ret == 'o')
		{
			printf("���\n");
		}
		else if (ret==1)
		{
			printf("ƽ��\n");
		}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//�����������
	do
	{
		menu();
		printf("�����������淨-->>");
		scanf("%d", &input);
		system("cls");//��������
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("��лʹ�ã�\n");
			break;
		default:
			printf("��������ȷ���淨~~~\n");
			break;
		}
	} while (input);
	return 0;
}