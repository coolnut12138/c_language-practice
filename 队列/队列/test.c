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

	printf("%d", QueueFront(&queue));//输出队首元素
	printf("\n");
	printf("%d", QueueEmpty(&queue));//判断是否为空，为空输出1，不空输出0
	printf("\n");
	printf("%d", QueueSize(&queue));//输出队列元素个数
	printf("\n");
	QueueDestroy(&queue);
}
int main()
{
	test();
	system("pause");
	return 0;
}