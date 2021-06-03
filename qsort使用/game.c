#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Init_chess(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			chess[i][j] = ' ';
		}
	}
}

void Background(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", chess[i][j]);
			if (j != col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i != (row - 1))
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j != col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

void Play_chess(char chess[ROW][COL], int row, int col)
{
	int x, y = 0;
	while (1)
	{
		printf("请输入需要走的坐标：>");
		scanf("%d%d", &x, &y);
		if (chess[x - 1][y - 1] == ' ')
		{
			chess[x - 1][y - 1] = 'P';
			break;
		}
		else
		{
			printf("输入的坐标非法,请重新输入 ：>");
		}
	}
}

char Is_win(char chess[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//判断行三个赢的情况  返回
	for (i = 0; i < row; i++)
	{
		if (chess[i][0] == chess[i][1] && chess[i][1] == chess[i][2] && chess[i][2] != ' ')
			return chess[i][0];
	}
	for (j = 0; j < col; j++)
	{
		if (chess[0][j] == chess[1][j] && chess[1][j] == chess[2][j] && chess[2][j] != ' ')
			return chess[0][j];
	}
	//交叉获胜情况
	if ((chess[0][0] == chess[1][1]) && (chess[1][1] == chess[2][2]) && (chess[2][2] != ' '))
	{
		return chess[0][0];
	}
	else if ((chess[0][2] == chess[1][1]) && (chess[1][1] == chess[2][0]) && (chess[1][1] != ' '))
	{
		return chess[1][1];
	}
	else
	{
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (chess[i][j] == ' ')
				{
					return 'c';
				}
			}
		}

	}
	return 'q';
}

char Com_chess(char chess[ROW][COL], int row, int col)
{
	int x, y = 0;
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;   //产生 0 到 2的坐标
		if(chess[x][y] == ' ')
		{
			chess[x][y] = 'C';
			break;
		}
	}
}