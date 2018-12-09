#define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
//��ʼ��
void QueueInit(Queue *queue)
{
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

//����
void QueueDestroy(Queue *queue)
{
	//���������Ԫ�أ������ͷ�
	QNode *next;
	for (QNode *cur = queue->front; cur != NULL; cur = next)
	{
		next = cur->next;
		free(cur);
	}
	queue->front = queue->rear = NULL;
	queue->size = 0;
}

//����
void QueuePush(Queue *queue, QDataType val)
{
	//�ȴ������
	QNode *node = (QNode *)malloc(sizeof(QNode));
	assert(node != NULL);
	node->val = val;
	node->next = NULL;
	queue->size++;
	//���ж϶����Ƿ�Ϊ��
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

//ɾ��
void QueuePop(Queue *queue)
{
	assert(queue->rear != NULL);//ȷ�����в�Ϊ��
	queue->size--;
	QNode *old_front = queue->front;
	queue->front = queue->front->next;
	free(old_front);
	//���ɾ����п��˵Ļ�����Ҫ����rear��ָ��NULL
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}
}

//���ض��׽���ֵ
QDataType QueueFront(const Queue *queue)
{
	assert(queue->size > 0);

	return queue->front->val;
}

//�ж϶����Ƿ�Ϊ�գ�Ϊ�շ���1�����շ���0
int QueueEmpty(const Queue *queue)
{
	return queue->size == 0 ? 1 : 0;
}

//���ض��н��ĸ���
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