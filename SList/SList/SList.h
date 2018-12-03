#define _CRT_SECURE_NO_WARNINGS 1
#pragma once

//���� + ��ѭ�� + ����ͷ

typedef int SLDataType;

typedef struct SListNode{
	SLDataType data;
	struct SListNode *next;
} SListNode;

typedef struct SList{
	struct SListNode *first;//first{? , next}
}SList;

//�ӿ�
//��ʼ��/����
void SListInit(SList *list);
void SListDestroy(SList *list);
//��/ɾ/��/��
//ͷ��
void SListPushFront(SList *list, SLDataType data);
//ͷɾ
void SListPopFront(SList *list);

//β��
void SListPushBack(SList *list, SLDataType data);
//βɾ
void SListPopBack(SList *list);

//����
SListNode *SListFind(SList *list, SLDataType data);

//��pos���������
void SListInsertAfter(SListNode *pos, SLDataType data);

//ɾ��pos������Ľ��
void SListEraseAfter(SListNode *pos);

//ɾ����һ��������data���
void SListRemove(SList *list, SLDataType data);

//��ӡ
void SListPrint(SList *list);