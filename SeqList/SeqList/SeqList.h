#pragma once
// Sequence List

#include <stddef.h>//size_t��ͷ�ļ�(ͷ�ļ���ʲô����дʲô������Ҫһͨ��д)

typedef int SLDataType;

struct SeqList {
	SLDataType *array;	// ָ�룬ָ�������ݵĿռ䣬�����Ŀռ��ڶ���
	int capacity;		// ˳������������
	int size;			// ˳�����������Ч�ĸ���
	// ��ʼֵΪ 0��ͬʱҲ��ʾ��һ����Чλ�õ��±�
};

typedef struct SeqList	SeqList;

// ��װ�Ľӿ�

// ��ʼ��/����
//Ϊʲô��ָ�룬��վ���û��ĽǶ�����д�ģ������û���ô��
void SeqListInit(SeqList *sl, size_t capacity);
void SeqListDestroy(SeqList *sl);

// ��ɾ���
// β�壬������˳�����β��
void SeqListPushBack(SeqList *sl, SLDataType data);

// ͷ�壬������˳�����ͷ�� ([0])
void SeqListPushFront(SeqList *sl, SLDataType data);

// βɾ��ɾ��˳���β��������
void SeqListPopBack(SeqList *sl);

// ͷɾ��ɾ��˳���ͷ��������
void SeqListPopFront(SeqList *sl);

//������м��,��pos���ڵ��±������ݲ���
void SeqListInsert(SeqList *sl,size_t pos,SLDataType data);

//ɾ��pos���ڵ��±�����
void SeqListErase(SeqList *sl, size_t pos);

//����
//�Ҵ�0��ʼ�ĵ�һ�������֪���ˣ������������ڵ��±�
//���û�ҵ�����-1
int SeqListFind(SeqList *sl, SLDataType data);

//ɾ����һ��������data
void SeqListRemove(SeqList *sl, SLDataType data);

//ɾ�����������е�data
void SeqListRemoveAll(SeqList *sl, SLDataType data);

//�޸�pos ���ڵ��±�
void SeqListModify(SeqList *sl, size_t pos, SLDataType data);

//ð������
void SeqListBubbleSort(SeqList *sl);

//���ֲ��ң�ǰ������������
int SeqListBinarySearch(SeqList *sl, SLDataType data);

// ��ӡ
void SeqListPrint(SeqList *sl);

// �ڲ��ӿ�
void CheckCapacity(SeqList *sl);