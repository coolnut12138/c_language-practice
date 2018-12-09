#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdlib.h>
//用链表实现队列
//定义数据类型
typedef int QDataType;

//定义链表队列结点
typedef struct QNode{
	QDataType val;
	struct QNode *next;
}	QNode;

//队列
typedef struct Queue{
	int size; //队列元素个数
	QNode *front;//指向队列第一个元素，如果队列为空，则等于NULL
	QNode *rear;//指向队列最后一个元素，如果队列为空，则等于NULL
}	Queue;

//初始化
void QueueInit(Queue *queue);

//销毁
void QueueDestroy(Queue *queue);

//插入，由于是队列，只能从队尾插结点
void QueuePush(Queue *queue, QDataType val);

//删除，只能从队首删
void QueuePop(Queue *queue);

//返回队首结点的值
QDataType QueueFront(const Queue *queue);

//判断队列是否为空，为空返回1，不空返回0
int QueueEmpty(const Queue *queue);

//返回队列结点的个数
int QueueSize(const Queue *queue);

//打印
void QueuePrint(const Queue *queue);