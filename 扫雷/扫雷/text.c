#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"

//打印菜单
void menu()
{
	printf("**********************************\n");
	printf("************ 0.退出 **************\n");
	printf("************ 1.游戏 **************\n");
	printf("**********************************\n");
}

//开始游戏
void game()
{
	//存放雷的信息
	char mine[ROWS][COLS] = { 0 };
	//排查雷的信息---》没有排查出来的话打印
	char mineInfo[ROWS][COLS] = { 0 };
	//还没有布置雷
	InitBorad(mine, ROWS, COLS, '0');
	//还没有排查出雷时的情况
	InitBorad(mineInfo, ROWS, COLS, '*');
	//打印棋盘
	show(mineInfo, ROWS, COLS);
    //设置雷的位置
	SetMine(mine, ROW, COL, '*');
	//打印二维数组
	//show(mine, ROWS, COLS);//打印雷的位置
	show(mineInfo, ROWS, COLS);//打印显示棋盘中的分布
	//扫雷
	FindMine(mine, mineInfo, ROW, COL);

}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));//设置随机种子
	do
	{
		menu();//打印菜单
		printf("请输入你的选择:  ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请输入正确的数字！\n");
			break;
		}
	} while (input);
	return 0;
}