#define _CRT_SECURE_NO_WARNINGS 1
#include "slist.h"
#include <stdio.h>
#include <stdlib.h>

void test(){
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 12);
	SeqListPushBack(&sl, 13);
	SeqListPushBack(&sl, 12);
	SeqListPushBack(&sl, 14);
	SeqListPushBack(&sl, 12);
	SeqListPushBack(&sl, 14);
	SeqListPushBack(&sl, 23);
	SeqListPushBack(&sl, 54);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 11);
	SeqListPushBack(&sl, 4);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 79);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListFind(&sl, 3);
	printf("%d\n", SeqListFind(&sl, 13));

	SeqListInsert(&sl, 1, 45);
	SeqListPrint(&sl);

	SeqListErase(&sl, 1);
	SeqListPrint(&sl);

	SeqListRemove(&sl, 12);
	SeqListPrint(&sl);

	SeqListModify(&sl, 1, 79);
	SeqListPrint(&sl);
	SeqListBubbleSort(&sl);
	SeqListPrint(&sl);

	printf("%d \n", SeqListBinarySearch(&sl, 11));
}

int main(){
	test();
	system("pause");
	return 0;
}