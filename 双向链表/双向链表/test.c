#define _CRT_SECURE_NO_WARNINGS 1
#include "DList.h"
#include<stdio.h>
#include<stdlib.h>

void test()
{
	DList dlist;
	DListInit(&dlist);

	DListPushFront(&dlist, 3);
	DListPushFront(&dlist, 2);
	DListPushFront(&dlist, 1);
	DListPrint(dlist.head);

	DListPushBack(&dlist, 7);
	DListPushBack(&dlist, 8);
	DListPushBack(&dlist, 9);
	DListPrint(dlist.head);

	DListNode *a = DListFind(&dlist, 7);
	DListInsert(a, 17);
	DListPrint(dlist.head);

	DListErase(a);
	DListPrint(dlist.head);

	DListPopFront(&dlist);
	DListPrint(dlist.head);

	DListPopBack(&dlist);
	DListPrint(dlist.head);

	DListClear(&dlist);
	DListDestroy(&dlist);
}

int main()
{
	test();
	system("pause");
	return 0;
}