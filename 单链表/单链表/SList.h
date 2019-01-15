#pragma once
//��ͷ�����ѭ������

typedef int SLTDataType;

typedef struct SListNode{
	SLTDataType data;
	struct SListNode *next;
}	SListNode;

typedef struct SList{
	SListNode *first;
}	SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);
//ͷ��
void SListPushFront(SList* plist, SLTDataType x);
//ͷɾ
void SListPopFront(SList* plist);
//β��
void SListPushBack(SList *plist, SLTDataType x);
//βɾ
void SListPopBack(SList *plist);
//����
SListNode* SListFind(SList* plist, SLTDataType x); 
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x); 
// ��pos��ǰ����в��� 
void SListEraseAfter(SListNode* pos);
//ɾ�����
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);