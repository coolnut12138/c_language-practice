#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
#include<stdio.h>
#include<stdlib.h>
void Test1()
{
	SList list;
	SListInit(&list);

	SListPushFront(&list, 4);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPrint(&list);

	SListPopFront(&list);
	SListPopFront(&list);
	SListPrint(&list);

	SListPushBack(&list, 5);
	SListPushBack(&list, 6);
	SListPushBack(&list, 7);
	SListPushBack(&list, 8);
	SListPrint(&list);

	SListPopBack(&list);
	SListPopBack(&list);
	SListPrint(&list);
}

void Test2()
{
	SList list;
	SListInit(&list);

	SListPushFront(&list, 4);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPrint(&list);
	//printf("%p\n",SListFind(&list,8));

	SListNode *n1 = SListFind(&list, 3);
	//SListInsertAfter(n1, 9);
	SListEraseAfter(n1);
	SListPrint(&list);
}

void Test3()
{
	SList list;
	SListInit(&list);
	SListPushFront(&list, 4);
	SListPushFront(&list, 3);
	SListPushFront(&list, 2);
	SListPushFront(&list, 1);
	SListPrint(&list);

	SListRemove(&list, 3);
	SListRemove(&list, 1);
	SListPrint(&list);
}
void main()
{
	//Test1();
	//Test2();
	Test3();
	system("pause");
}