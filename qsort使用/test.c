#include "game.h"
#define _CRT_SECURE_NO_WARNINGS 1

//��������Ϸ�����

void menu()
{
	printf("**********************************\n");
	printf("***********��������Ϸ*************\n");
	printf("******** 1.play  0.exit **********\n");
	printf("**********************************\n");
}

void test()
{
	char ret = 'c';
	char chess[ROW][COL] = { 0 };
	//��ʼ������
	Init_chess(chess,ROW,COL);
	//��ӡģ��
	Background(chess,ROW,COL);
	//�������
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
		printf("���Ӯ�ˣ�");
	else if (ret == 'C')
		printf("����Ӯ�ˣ�");
	else
		printf("ƽ�֣�");
}



int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ���Ƿ�ʼ��Ϸ��>");
1;		scanf("%d", &input);
		switch (input)
		{
		case 1:
			test();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
	return 0;
}




