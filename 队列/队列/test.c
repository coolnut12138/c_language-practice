#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include<stdio.h>
#include<stdlib.h>
void test()
{
	Queue queue;
	QueueInit(&queue);
	QueuePush(&queue, 1);
	QueuePush(&queue, 2);
	QueuePush(&queue, 3);
	QueuePush(&queue, 4);
	QueuePush(&queue, 7);
	QueuePrint(&queue);

	QueuePop(&queue);
	QueuePrint(&queue);

	printf("%d", QueueFront(&queue));//�������Ԫ��
	printf("\n");
	printf("%d", QueueEmpty(&queue));//�ж��Ƿ�Ϊ�գ�Ϊ�����1���������0
	printf("\n");
	printf("%d", QueueSize(&queue));//�������Ԫ�ظ���
	printf("\n");
	QueueDestroy(&queue);
}
int main()
{
	test();
	system("pause");
	return 0;
}