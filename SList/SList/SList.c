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

//�����ռ�
SListNode *BuySListNode(SLDataType data)
{
	//Ȼ�󴴽�һ�����
	SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	assert(node != NULL);
	//��ֵ
	node->data = data;
	node->next = NULL;
	
	return node;
}

//ͷ��
void SListPushFront(SList *list, SLDataType data)
{
	assert(list != NULL);
	//1.Node �ռ�
	//SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	//assert(node);
	////2.��ֵ
	//node->data = data;
	//3.�µĵ�һ��������һ��������ԭ���ĵ�һ�����
	SListNode *node = BuySListNode(data);
	node->next = list->first;
	//4.��¼�µĵ�һ�����
	list->first = node;
}

//ͷɾ
void SListPopFront(SList *list)
{
	assert(list != NULL); //û������
	assert(list->first != NULL);//�������������ǿյģ��ų�һ��ʼһ����㶼û��

	SListNode *old_first = list->first;
	list->first = list->first->next;
	free(old_first);
}

//β��
void SListPushBack(SList *list, SLDataType data)
{
	//û������
	assert(list != NULL);
	//����Ϊ�յ��������ͷ��
	if (list->first == NULL){
		SListPushFront(list, data);
		//ͷ����ǵ÷���
		return;
	}
	//���ҳ����һ�����
	SListNode *cur = list->first;
	for (; cur->next != NULL; cur = cur->next){
	}
	////Ȼ�󴴽�һ�����
	//SListNode *node = (SListNode *)malloc(sizeof(SListNode));
	//assert(node != NULL);
	////��ֵ
	//node->data = data;
	//node->next = NULL;
	SListNode *node = BuySListNode(data);
	cur->next = node;
}

//βɾ
void SListPopBack(SList *list)
{
	assert(list != NULL);
	//����Ϊ��
	assert(list->first != NULL);
	//����ֻ��һ��������ͷɾ
	if (list->first == NULL){
		SListPopFront(list);
		return;
	}
	//�ҵ������ڶ������
	SListNode *cur = list->first;
	for (; cur->next->next != NULL; cur = cur->next){
	}
	//���ͷţ���ָ���
	free(cur->next);
	cur->next = NULL;
}

//����
SListNode *SListFind(SList *list, SLDataType data)
{
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next){
		if (cur->data == data){
			return cur;
		}
	}
	return NULL;
}

//��pos���������
void SListInsertAfter(SListNode *pos, SLDataType data)
{
	assert(pos != NULL);
	/*SListNode *node = (SListNode*)malloc(sizeof(SListNode));
	node->data = data;*/
	SListNode *node = BuySListNode(data);
	node->next = pos->next;
	pos->next = node;
}

//ɾ��pos����ߵĽ��
void SListEraseAfter(SListNode *pos)
{
	assert(pos != NULL);
	SListNode *next = pos->next->next;
	free(pos->next);
	pos->next = next;
}

//ɾ����һ��������data���
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
	//���prevΪ�վ�ͷɾ����
	if (prev == NULL){
		SListPopFront(list);
		return;//ɾ��һ��Ҫ�ǵ÷��أ���Ȼ��ִ�е�����ȥ��
	}
	prev->next = cur->next;
	free(cur);
}

//��ӡ
void SListPrint(SList *list)
{
	for (SListNode *cur = list->first; cur != NULL; cur = cur->next)
	{
		printf("%d-->", cur->data);
	}
	printf("NULL\n");
}