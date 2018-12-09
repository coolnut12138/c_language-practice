#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdlib.h>
//������ʵ�ֶ���
//������������
typedef int QDataType;

//����������н��
typedef struct QNode{
	QDataType val;
	struct QNode *next;
}	QNode;

//����
typedef struct Queue{
	int size; //����Ԫ�ظ���
	QNode *front;//ָ����е�һ��Ԫ�أ��������Ϊ�գ������NULL
	QNode *rear;//ָ��������һ��Ԫ�أ��������Ϊ�գ������NULL
}	Queue;

//��ʼ��
void QueueInit(Queue *queue);

//����
void QueueDestroy(Queue *queue);

//���룬�����Ƕ��У�ֻ�ܴӶ�β����
void QueuePush(Queue *queue, QDataType val);

//ɾ����ֻ�ܴӶ���ɾ
void QueuePop(Queue *queue);

//���ض��׽���ֵ
QDataType QueueFront(const Queue *queue);

//�ж϶����Ƿ�Ϊ�գ�Ϊ�շ���1�����շ���0
int QueueEmpty(const Queue *queue);

//���ض��н��ĸ���
int QueueSize(const Queue *queue);

//��ӡ
void QueuePrint(const Queue *queue);