#define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
#include <stdio.h>
#include <stdlib.h>

void test(){
	SList list;
	SListInit(&list);
	SListPushFront(&list, 1);
	/*SListPushFront(&list, 2);
	SListPushFront(&list, 3);
	SListPushFront(&list, 4);
	SListPrint(&list);

	SListPopFront(&list);
	SListPrint(&list);

	SListRemove(&list, 1);
	SListPrint(&list);

	SListPushBack(&list, 2);
	SListPushBack(&list, 3);
	SListPushBack(&list, 4);
	SListPrint(&list);*/
	SListPopBack(&list);
	SListPrint(&list);

	SListDestory(&list);
}

int main(){
	test();
	system("pause");
	return 0;
}