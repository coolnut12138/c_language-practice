#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$    ɨ����Ϸ   $$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$    1. ��ʼ    $$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$    0. �˳�    $$$$$$$$$$$$$$$$\n");
	printf("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("���������ѡ��\n");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ���˳�\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}while(input);
}