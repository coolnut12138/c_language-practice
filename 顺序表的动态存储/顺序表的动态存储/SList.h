#pragma once
#include <stddef.h>

typedef int SLDataType;

typedef struct SeqList{
	SLDataType *array;  //ָ��̬���ٵ�����
	size_t size;  //��Ч���ݵĸ���
	size_t capacity;  //�����ռ�Ĵ�С
} SeqList;

void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);
//����
void CheckCapacity(SeqList* psl);
//β��
void SeqListPushBack(SeqList* psl, SLDataType x);
//βɾ
void SeqListPopBack(SeqList* psl);
//ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x);
//ͷɾ
void SeqListPopFront(SeqList* psl);
//����
int SeqListFind(SeqList* psl, SLDataType x);
//����
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
//ɾ��
void SeqListErase(SeqList* psl, size_t pos);
//ɾ������x
void SeqListRemove(SeqList* psl, SLDataType x);
//�޸�posλ��
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);

// ��չ������ʵ��
void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
// ����Ҫ��ʱ�临�Ӷȣ�O(N) �ռ临�Ӷ� O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);