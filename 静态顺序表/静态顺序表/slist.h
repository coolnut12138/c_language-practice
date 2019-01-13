#pragma once

#include <stddef.h>
#define N 100
typedef int SLDataType;

typedef struct SeqList{
	SLDataType array[N];//定长数组
	size_t size; //有效数据的个数
}	SeqList;

void SeqListInit(SeqList *sl);

void SeqListDestory(SeqList* sl);
//尾插
void SeqListPushBack(SeqList* sl, SLDataType val);
//尾删
void SeqListPopBack(SeqList* sl); 
//头插
void SeqListPushFront(SeqList* sl, SLDataType val); 
//头删
void SeqListPopFront(SeqList* sl);
//查找
int SeqListFind(SeqList* sl, SLDataType val);
//插入
void SeqListInsert(SeqList* sl, size_t pos, SLDataType val);
//删除指定位置
void SeqListErase(SeqList* sl, size_t pos); 
//删除所有等于val的值
void SeqListRemove(SeqList* sl, SLDataType val); 
//修改指定位置的值
void SeqListModify(SeqList* sl, size_t pos, SLDataType val);
//冒泡排序
void SeqListBubbleSort(SeqList *sl);
//二分查找
int SeqListBinarySearch(SeqList *sl, SLDataType val);

void SeqListPrint(SeqList* sl);