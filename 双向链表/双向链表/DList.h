#pragma once

//数据类型
typedef int DLDataType;

//结点类型
typedef struct DListNode{
	DLDataType val;
	struct DListNode *next;
	struct DListNode *prev;
}	DListNode;

//双向链表类型
typedef struct {
	DListNode *head; //指向头结点
}	DList;

//接口
//初始化/销毁
void DListInit(DList *dlist);

//清空
void DListClear(DList *dlist);

//销毁
void DListDestroy(DList *dlist);

//增删查改
//头插
void DListPushFront(DList *dlist,DLDataType val);

//尾插
void DListPushBack(DList *dlist, DLDataType val);

//查找结点
DListNode *DListFind(DList *dlist,DLDataType val);

//在pos前面插入
void DListInsert(DListNode *pos, DLDataType val);

//删除pos结点，pos不是头结点
void DListErase(DListNode *pos);

//头删
void DListPopFront(DList *dlist);
//尾删
void DListPopBack(DList *dlist);
//打印
void DListPrint(DListNode *head);