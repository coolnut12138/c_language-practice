#pragma once

//��������
typedef int DLDataType;

//�������
typedef struct DListNode{
	DLDataType val;
	struct DListNode *next;
	struct DListNode *prev;
}	DListNode;

//˫����������
typedef struct {
	DListNode *head; //ָ��ͷ���
}	DList;

//�ӿ�
//��ʼ��/����
void DListInit(DList *dlist);

//���
void DListClear(DList *dlist);

//����
void DListDestroy(DList *dlist);

//��ɾ���
//ͷ��
void DListPushFront(DList *dlist,DLDataType val);

//β��
void DListPushBack(DList *dlist, DLDataType val);

//���ҽ��
DListNode *DListFind(DList *dlist,DLDataType val);

//��posǰ�����
void DListInsert(DListNode *pos, DLDataType val);

//ɾ��pos��㣬pos����ͷ���
void DListErase(DListNode *pos);

//ͷɾ
void DListPopFront(DList *dlist);
//βɾ
void DListPopBack(DList *dlist);
//��ӡ
void DListPrint(DListNode *head);