#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

#define ROW 3
#define COL 3

//打印菜单
void menu()
{
	printf("*****************************\n");
	printf("**********0.不玩游戏*********\n");
	printf("**********1.要玩游戏*********\n");
	printf("*****************************\n");
}
//游戏开始
void game()
{
	int ret =0;
	char board[3][3] = { 0 };
	InitBoard(board, ROW, COL);
	ShowBoard(board, ROW, COL);
	while (1)
	{
		PlayerMove(board);//玩家移动
		ret = IsWin(board, ROW, COL);//判断玩家移动后，玩家和电脑的输赢情况
		if (ret != 0)
		{
		break;
		}
		ShowBoard(board, ROW, COL);//打印玩家移动后的棋盘
		printf("电脑移动\n");
		ComputerMove(board);//电脑移动
		ShowBoard(board, ROW, COL);//打印电脑移动后的棋盘
		ret = IsWin(board, ROW, COL);//判断电脑移动后，玩家和电脑的输赢情况
		if (ret != 0)
		{
		break;
		}
	}
		if (ret == 'x')
		{
			printf("牛逼傲\n");
		}
		else if (ret == 'o')
		{
			printf("真菜\n");
		}
		else if (ret==1)
		{
			printf("平局\n");
		}
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//设置随机种子
	do
	{
		menu();
		printf("请输入您的玩法-->>");
		scanf("%d", &input);
		system("cls");//清屏操作
		switch (input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("感谢使用！\n");
			break;
		default:
			printf("请输入正确的玩法~~~\n");
			break;
		}
	} while (input);
	return 0;
}