#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void SListInit(SList* plist){
	assert(plist);
	plist->first = NULL;
}
void SListDestory(SList* plist){
	SListNode *next;
	for (SListNode *cur = plist->first; cur != NULL; cur = next){
		next = cur->next;
		free(cur);
	}
	plist->first = NULL;
}

SListNode* BuySListNode(SLTDataType x){
	//1.创建结点
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	//2.赋值
	node->data = x;
	node->next = NULL;
	return node;
}
//头插
void SListPushFront(SList* plist, SLTDataType x){
	assert(plist);
	SListNode *node = BuySListNode(x);
	//3.新的结点的下一个结点就是原来的的第一个结点
	node->next = plist->first;
	//4.记录新的第一个结点
	plist->first = node;
}
//头删
void SListPopFront(SList* plist){
	assert(plist);
	assert(plist->first != NULL);
	SListNode *oldfirst = plist->first;
	plist->first = plist->first->next;
	free(oldfirst);
}

//尾插
void SListPushBack(SList *plist, SLTDataType x){
	assert(plist);
	assert(plist->first != NULL);
	if (plist->first == NULL){
		SListPushFront(plist, x);
		return;
	}
	SListNode *cur = plist->first;
	for (; cur->next != NULL; cur = cur->next){
	}
	SListNode *node = BuySListNode(x);
	cur->next = node;
}

//尾删
void SListPopBack(SList *plist){
	assert(plist);
	assert(plist->first);
	if (plist->first->next == NULL){
		SListPopFront(plist);
		return;
	}
	SListNode *cur = plist->first;
	for (; cur->next->next != NULL; cur = cur->next){
	}
	free(cur->next);
	cur->next = NULL;
}

//查找
SListNode* SListFind(SList* plist, SLTDataType x){
	for (SListNode *cur = plist->first; cur != NULL; cur = cur->next){
		if (x == cur->data){
			return cur;
		}
	}
	return NULL;
}
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x){
	assert(pos != NULL);
	SListNode *node = BuySListNode(x);
	node->next = pos->next;
	pos->next = node;
}
// 删除pos结点后面的结点 
void SListEraseAfter(SListNode* pos){
	assert(pos != NULL);
	SListNode *old = pos->next;
	pos->next = pos->next->next;
	free(old);
}
//删除第一个遇到的x结点
void SListRemove(SList* plist, SLTDataType x){
	assert(plist);
	assert(plist->first != NULL);
	SListNode *prev = NULL;
	SListNode *cur = plist->first;
	while (cur != NULL && cur->data != x){
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL){
		return;
	}
	if (prev == NULL){
		SListPopFront(plist);
		return;
	}
	if (cur->data == x){
		prev->next = cur->next;
		free(cur);
		return;
	}
}

void SListPrint(SList* plist){
	for (SListNode *cur = plist->first; cur != NULL; cur = cur->next){
		printf("%d->", cur->data);
	}
	printf("NULL\n");
}