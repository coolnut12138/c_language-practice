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
	//1.�������
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node);
	//2.��ֵ
	node->data = x;
	node->next = NULL;
	return node;
}
//ͷ��
void SListPushFront(SList* plist, SLTDataType x){
	assert(plist);
	SListNode *node = BuySListNode(x);
	//3.�µĽ�����һ��������ԭ���ĵĵ�һ�����
	node->next = plist->first;
	//4.��¼�µĵ�һ�����
	plist->first = node;
}
//ͷɾ
void SListPopFront(SList* plist){
	assert(plist);
	assert(plist->first != NULL);
	SListNode *oldfirst = plist->first;
	plist->first = plist->first->next;
	free(oldfirst);
}

//β��
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

//βɾ
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

//����
SListNode* SListFind(SList* plist, SLTDataType x){
	for (SListNode *cur = plist->first; cur != NULL; cur = cur->next){
		if (x == cur->data){
			return cur;
		}
	}
	return NULL;
}
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x){
	assert(pos != NULL);
	SListNode *node = BuySListNode(x);
	node->next = pos->next;
	pos->next = node;
}
// ɾ��pos������Ľ�� 
void SListEraseAfter(SListNode* pos){
	assert(pos != NULL);
	SListNode *old = pos->next;
	pos->next = pos->next->next;
	free(old);
}
//ɾ����һ��������x���
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