#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>


//�ڲ����
//�����½��ռ�
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
	//����ͷ���
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
//ͷ��
void DListPushFront(DList *dlist, DLDataType val)
{
	//Ҳ���Ե�����posǰ����
	DListInsert(dlist->head->next, val);

#if 0
	//�����½��
	DListNode *node = BuyNode(val);
	//����node��ǰ��ָ��ָ��
	node->next = dlist->head->next;
	node->prev = dlist->head;
	//����ͷ������һ������ǰָ��ָ��
	dlist->head->next->prev = node;
	//����ͷ���ĺ�ָ��
	dlist->head->next = node;
#endif
}

//β��
void DListPushBack(DList *dlist, DLDataType val)
{
	//Ҳ���Ե�����posǰ����
	DListInsert(dlist->head, val);
#if 0
	DListNode *node = BuyNode(val);
	node->next = dlist->head;
	node->prev = dlist->head->prev;
	dlist->head->prev->next = node;
	dlist->head->prev = node;
#endif
}

//����
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
//��pos���ǰ�����
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

//ͷɾ
void DListPopFront(DList *dlist)
{
	assert(dlist->head->next != dlist->head);

	//DListNode *OldFirst = dlist->head->next;
	//dlist->head->next = dlist->head->next->next;
	//dlist->head->next->prev = dlist->head;
	//free(OldFirst);
	//Ҳ���Ե���ɾ��pos���
	DListErase(dlist->head->next);
}

//βɾ
void DListPopBack(DList *dlist)
{
	//����Ϊ��
	assert(dlist->head->next != dlist->head);
	//DListNode *OldBack = dlist->head->prev;
	//dlist->head->prev->prev->next = dlist->head;
	//dlist->head->prev = dlist->head->prev->prev;
	//free(OldBack);
	//Ҳ������ɾ��pos���
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