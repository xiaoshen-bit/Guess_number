#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

//三子棋游戏的设计

void menu()
{
	printf("**********************************\n");
	printf("***********三子棋游戏*************\n");
	printf("******** 1.play  0.exit **********\n");
	printf("**********************************\n");
}

void test()
{
	char ret = 'c';
	char chess[ROW][COL] = { 0 };
	//初始化棋子
	Init_chess(chess,ROW,COL);
	//打印模板
	Background(chess,ROW,COL);
	//玩家下棋
	while(1)
	{
		Play_chess(chess, ROW, COL);
		Background(chess, ROW, COL);
		ret = Is_win(chess, ROW, COL);
		if (ret != 'c')
		{
			goto win;
		}
		Com_chess(chess, ROW, COL);
		Background(chess, ROW, COL);
		ret = ret = Is_win(chess, ROW, COL);
		if (ret != 'c')
		{
			goto win;
		}
	}
win :
	if (ret == 'P')
		printf("玩家赢了！");
	else if (ret == 'C')
		printf("电脑赢了！");
	else
		printf("平局！");
}



int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择是否开始游戏：>");
1;		scanf("%d", &input);
		switch (input)
		{
		case 1:
			test();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
	return 0;
}




