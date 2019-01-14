#include "SList.h"
#include <stdio.h>
#include <stdlib.h>

void test(){
	SeqList psl;
	SeqListInit(&psl, 4);

	SeqListPushBack(&psl, 1);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 2);
	SeqListPushBack(&psl, 3);
	SeqListPushBack(&psl, 4);
	SeqListPrint(&psl);

	SeqListPopBack(&psl);
	SeqListPopBack(&psl);
	SeqListPrint(&psl);

	SeqListPushFront(&psl, 0);
	SeqListPushFront(&psl, 11);
	SeqListPushFront(&psl, -2);
	SeqListPrint(&psl);

	SeqListPopFront(&psl);
	SeqListPrint(&psl);

	printf("%d \n", SeqListFind(&psl, 2));

	SeqListInsert(&psl, 2, 99);
	SeqListPrint(&psl);
	SeqListErase(&psl, 2);
	SeqListPrint(&psl);
	SeqListRemoveAll(&psl, 2);
	SeqListPrint(&psl);
	SeqListModify(&psl, 2, 7);
	SeqListPrint(&psl);
	SeqListBubbleSort(&psl);
	SeqListPrint(&psl);
	printf("%d\n", SeqListBinaryFind(&psl, 7));
}

int main(){
	test();
	system("pause");
	return 0;
}