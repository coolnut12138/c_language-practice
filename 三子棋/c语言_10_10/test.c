#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("\n#################################\n");
	printf("##########  三子棋游戏  #########\n");
	printf("###########  1. 开始  ###########\n");
	printf("###########  0. 退出  ###########\n");
	printf("#################################\n");
	system("color e0");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏已退出\n");
			break;
		default:
			printf("输入错误请重新输入\n");
			break;
		}
	}while(input);
}