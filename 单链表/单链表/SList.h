#pragma once
//无头单向非循环链表

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
//头插
void SListPushFront(SList* plist, SLTDataType x);
//头删
void SListPopFront(SList* plist);
//尾插
void SListPushBack(SList *plist, SLTDataType x);
//尾删
void SListPopBack(SList *plist);
//查找
SListNode* SListFind(SList* plist, SLTDataType x); 
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x); 
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos);
//删除结点
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);