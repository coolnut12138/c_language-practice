#pragma once
#include <stddef.h>

typedef int SLDataType;

typedef struct SeqList{
	SLDataType *array;  //指向动态开辟的数组
	size_t size;  //有效数据的个数
	size_t capacity;  //容量空间的大小
} SeqList;

void SeqListInit(SeqList* psl, size_t capacity);
void SeqListDestory(SeqList* psl);
//扩容
void CheckCapacity(SeqList* psl);
//尾插
void SeqListPushBack(SeqList* psl, SLDataType x);
//尾删
void SeqListPopBack(SeqList* psl);
//头插
void SeqListPushFront(SeqList* psl, SLDataType x);
//头删
void SeqListPopFront(SeqList* psl);
//查找
int SeqListFind(SeqList* psl, SLDataType x);
//插入
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x);
//删除
void SeqListErase(SeqList* psl, size_t pos);
//删除所有x
void SeqListRemove(SeqList* psl, SLDataType x);
//修改pos位置
void SeqListModify(SeqList* psl, size_t pos, SLDataType x);
void SeqListPrint(SeqList* psl);

// 扩展面试题实现
void SeqListBubbleSort(SeqList* psl);
int SeqListBinaryFind(SeqList* psl, SLDataType x);
// 本题要求：时间复杂度：O(N) 空间复杂度 O(1) 
void SeqListRemoveAll(SeqList* psl, SLDataType x);