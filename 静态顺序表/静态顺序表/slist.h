#pragma once

#include <stddef.h>
#define N 100
typedef int SLDataType;

typedef struct SeqList{
	SLDataType array[N];//��������
	size_t size; //��Ч���ݵĸ���
}	SeqList;

void SeqListInit(SeqList *sl);

void SeqListDestory(SeqList* sl);
//β��
void SeqListPushBack(SeqList* sl, SLDataType val);
//βɾ
void SeqListPopBack(SeqList* sl); 
//ͷ��
void SeqListPushFront(SeqList* sl, SLDataType val); 
//ͷɾ
void SeqListPopFront(SeqList* sl);
//����
int SeqListFind(SeqList* sl, SLDataType val);
//����
void SeqListInsert(SeqList* sl, size_t pos, SLDataType val);
//ɾ��ָ��λ��
void SeqListErase(SeqList* sl, size_t pos); 
//ɾ�����е���val��ֵ
void SeqListRemove(SeqList* sl, SLDataType val); 
//�޸�ָ��λ�õ�ֵ
void SeqListModify(SeqList* sl, size_t pos, SLDataType val);
//ð������
void SeqListBubbleSort(SeqList *sl);
//���ֲ���
int SeqListBinarySearch(SeqList *sl, SLDataType val);

void SeqListPrint(SeqList* sl);