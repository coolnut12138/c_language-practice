#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("\n#################################\n");
	printf("##########  ��������Ϸ  #########\n");
	printf("###########  1. ��ʼ  ###########\n");
	printf("###########  0. �˳�  ###########\n");
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
			printf("��Ϸ���˳�\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}while(input);
}