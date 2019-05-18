#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

#if 0
//内部结点
//创建新结点空间
DListNode *BuyNode(DLDataType val)
{
	DListNode * node = (DListNode *)malloc(sizeof(DListNode));
	assert(node != NULL);
	node->val = val;
	node->next = node->prev = NULL;

	return node;
}

void DListInit(DList *dlist)
{
	//创建头结点
	//DListNode * head = (DListNode *)malloc(sizeof(DListNode));
	DListNode * head = BuyNode(0);

	//head->val = 0;
	head->next = head;
	head->prev = head;

	dlist->head = head;
}


void DListClear(DList *dlist)
{
	DListNode *cur, *next;
	for (cur = dlist->head->next; cur != dlist->head; cur = next)
	{
		next = cur->next;
		free(cur);
	}

	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}

void DListDestroy(DList *dlist)
{
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}
//头插
void DListPushFront(DList *dlist, DLDataType val)
{
	//也可以调用在pos前插入
	DListInsert(dlist->head->next, val);

#if 0
	//创建新结点
	DListNode *node = BuyNode(val);
	//调整node的前后指针指向
	node->next = dlist->head->next;
	node->prev = dlist->head;
	//调整头结点的下一个结点的前指针指向
	dlist->head->next->prev = node;
	//调整头结点的后指针
	dlist->head->next = node;
#endif
}

//尾插
void DListPushBack(DList *dlist, DLDataType val)
{
	//也可以调用在pos前插入
	DListInsert(dlist->head, val);
#if 0
	DListNode *node = BuyNode(val);
	node->next = dlist->head;
	node->prev = dlist->head->prev;
	dlist->head->prev->next = node;
	dlist->head->prev = node;
#endif
}

//查找
DListNode *DListFind(DList *dlist, DLDataType val)
{
	for (DListNode *cur = dlist->head->next; cur != dlist->head; cur = cur->next)
	{
		if (cur->val == val)
		{
			return cur;
		}
	}
	return NULL;
}
//在pos结点前面插入
void DListInsert(DListNode *pos, DLDataType val)
{
	DListNode *node = BuyNode(val);
	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}

void DListErase(DListNode *pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

//头删
void DListPopFront(DList *dlist)
{
	assert(dlist->head->next != dlist->head);

	//DListNode *OldFirst = dlist->head->next;
	//dlist->head->next = dlist->head->next->next;
	//dlist->head->next->prev = dlist->head;
	//free(OldFirst);
	//也可以调用删除pos结点
	DListErase(dlist->head->next);
}

//尾删
void DListPopBack(DList *dlist)
{
	//链表不为空
	assert(dlist->head->next != dlist->head);
	//DListNode *OldBack = dlist->head->prev;
	//dlist->head->prev->prev->next = dlist->head;
	//dlist->head->prev = dlist->head->prev->prev;
	//free(OldBack);
	//也可以用删除pos结点
	DListErase(dlist->head->prev);
}

void DListPrint(DListNode *head)
{
	for (DListNode *cur = head->next; cur != head; cur = cur->next)
	{
		printf("%d-->", cur->val);
	}
	printf("\n");
}
#endif

#if 1
DListNode* BuyNode(DLDataType val)
{
	DListNode *node = (DListNode*)malloc(sizeof(DListNode));	//申请的字节数如果不对会导致free崩溃
	assert(node != NULL);
	node->val = val;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
void DListInit(DList *dlist)
{
	//创建头结点
	DListNode *head = BuyNode(0);
	head->next = head;
	head->prev = head;
	dlist->head = head;
}

void DListClear(DList *dlist)
{
	//只留头结点
	DListNode *cur, *next;
	cur = dlist->head->next;
	while (cur != dlist->head){
		next = cur->next;
		//free(cur);
		cur = next;
	}
	dlist->head->next = dlist->head;
	dlist->head->prev = dlist->head;
}

void DListDestroy(DList *dlist)
{
	//头结点也删除
	DListClear(dlist);
	free(dlist->head);
	dlist->head = NULL;
}

void DListPushFront(DList *dlist, DLDataType val)
{
	DListNode *node = BuyNode(val);
	dlist->head->next->prev = node;
	node->next = dlist->head->next;
	node->prev = dlist->head;
	dlist->head->next = node;
}

void DListPushBack(DList *dlist, DLDataType val)
{
	DListNode *node = BuyNode(val);
	dlist->head->prev->next = node;
	node->prev = dlist->head->prev;
	node->next = dlist->head;
	dlist->head->prev = node;
}

DListNode *DListFind(DList *dlist, DLDataType val)
{
	DListNode *cur = dlist->head->next, *next;
	while (cur != dlist->head){
		if (cur->val == val){
			return cur;
		}
		next = cur->next;
		cur = next;
	}
	return NULL;
}

//在pos前面插入
void DListInsert(DListNode *pos, DLDataType val)
{
	DListNode *node = BuyNode(val);
	pos->prev->next = node;
	node->next = pos;
	node->prev = pos->prev;
	pos->prev = node;
}

//删除pos结点。不是头结点
void DListErase(DListNode *pos)
{
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

void DListPopFront(DList *dlist)
{
	assert(dlist->head->next != dlist->head);
	DListNode *node = dlist->head->next;
	dlist->head->next = dlist->head->next->next;
	dlist->head->next->prev = dlist->head;
	free(node);
}

void DListPopBack(DList *dlist)
{
	assert(dlist->head->prev != dlist->head);
	DListNode *node = dlist->head->prev;
	dlist->head->prev->prev->next = dlist->head;
	dlist->head->prev = dlist->head->prev->prev;
	free(node);
}

void DListPrint(DListNode *head)
{
	DListNode *cur = head->next, *next;
	while (cur != head)
	{
		printf("%d->",cur->val);
		next = cur->next;
		cur = next;
	}
	printf("\n");
}
#endif









