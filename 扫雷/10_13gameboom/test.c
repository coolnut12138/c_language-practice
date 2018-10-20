#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$    扫雷游戏   $$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$    1. 开始    $$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$    0. 退出    $$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入你的选择：\n");
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
			printf("输入错误，请重新输入\n");
			break;
		}
	}while(input);
}