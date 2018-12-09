#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
//初始化
void QueueInit(Queue *queue)
{
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

//销毁
void QueueDestroy(Queue *queue)
{
	//队内如果有元素，就先释放
	QNode *next;
	for (QNode *cur = queue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

//插入
void QueuePush(Queue *queue, QDataType val)
{
	//先创建结点
	QNode *node = (QNode *)malloc(sizeof(QNode));
	assert(node != NULL);
	node->val = val;
	node->next = NULL;
	queue->size++;
	//再判断队列是否为空
	if (queue->rear == NULL)
	{
		queue->front = queue->rear = node;
	}
	else
	{
		queue->rear->next = node;
		queue->rear = node;
	}
}

//删除
void QueuePop(Queue *queue)
{
	assert(queue->rear != NULL);//确保队列不为空
	queue->size--;
	QNode *old_front = queue->front;
	queue->front = queue->front->next;
	free(old_front);
	//如果删完队列空了的话，就要设置rear的指向NULL
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}
}

//返回队首结点的值
QDataType QueueFront(const Queue *queue)
{
	assert(queue->size > 0);

	return queue->front->val;
}

//判断队列是否为空，为空返回1，不空返回0
int QueueEmpty(const Queue *queue)
{
	return queue->size == 0 ? 1 : 0;
}

//返回队列结点的个数
int QueueSize(const Queue *queue)
{
	return queue->size;
}

void QueuePrint(const Queue *queue)
{
	for (QNode *cur = queue->front; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->val);
	}
	printf("\n");
}