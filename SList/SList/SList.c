#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void SListInit(SList *list)
{
	assert(list != NULL);
	list->first = NULL;
}

void SListDestroy(SList *list)
{
	SListNode *next;
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next){
		next = cur->next;
		free(cur);
	}
	list->first = NULL;
}

//创建空间
SListNode *BuySListNode(SLDataType data)
{
	//然后创建一个结点
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node != NULL);
	//赋值
	node->data = data;
	node->next = NULL;
	
	return node;
}

//头插
void SListPushFront(SList *list, SLDataType data)
{
	assert(list != NULL);
	//1.Node 空间
	//SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	//assert(node);
	////2.赋值
	//node->data = data;
	//3.新的第一个结点的下一个结点就是原来的第一个结点
	SListNode *node = BuySListNode(data);
	node->next = list->first;
	//4.记录新的第一个结点
	list->first = node;
}

//头删
void SListPopFront(SList *list)
{
	assert(list != NULL); //没有链表
	assert(list->first != NULL);//有链表但是链表是空的，排除一开始一个结点都没有

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

//尾插
void SListPushBack(SList *list, SLDataType data)
{
	//没有链表
	assert(list != NULL);
	//链表为空的情况就是头插
	if (list->first == NULL){
		SListPushFront(list, data);
		//头插完记得返回
		return;
	}
	//先找出最后一个结点
	SListNode *cur = list->first;
	for (; cur->next != NULL; cur = cur->next){
	}
	////然后创建一个结点
	//SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	//assert(node != NULL);
	////赋值
	//node->data = data;
	//node->next = NULL;
	SListNode *node = BuySListNode(data);
	cur->next = node;
}

//尾删
void SListPopBack(SList *list)
{
	assert(list != NULL);
	//链表为空
	assert(list->first != NULL);
	//链表只有一个结点就用头删
	if (list->first == NULL){
		SListPopFront(list);
		return;
	}
	//找到倒数第二个结点
	SListNode *cur = list->first;
	for (; cur->next->next != NULL; cur = cur->next){
	}
	//先释放，再指向空
	free(cur->next);
	cur->next = NULL;
}

//查找
SListNode *SListFind(SList *list, SLDataType data)
{
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next){
		if (cur->data == data){
			return cur;
		}
	}
	return NULL;
}

//在pos结点后面插入
void SListInsertAfter(SListNode *pos, SLDataType data)
{
	assert(pos != NULL);
	/*SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	node->data = data;*/
	SListNode *node = BuySListNode(data);
	node->next = pos->next;
	pos->next = node;
}

//删除pos结点后边的结点
void SListEraseAfter(SListNode *pos)
{
	assert(pos != NULL);
	SListNode *next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

//删除第一个遇到的data结点
void SListRemove(SList *list, SLDataType data)
{
	assert(list != NULL);
	assert(list->first != NULL);
	SListNode *cur = list->first;
	SListNode *prev = NULL;
	while (cur != NULL && cur->data != data){
		prev = cur;
		cur = cur->next;
	}
	if (cur == NULL){
		return;
	}	
	//如果prev为空就头删即可
	if (prev == NULL){
		SListPopFront(list);
		return;//删完一定要记得返回，不然就执行到下面去了
	}
	prev->next = cur->next;
	free(cur);
}

//打印
void SListPrint(SList *list)
{
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->data);
	}
	printf("NULL\n");
}