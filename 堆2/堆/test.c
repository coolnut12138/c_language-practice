#include "Heap.h"
#include <stdio.h>
#include <stdlib.h>

//void test()
//{
//	int array[] = { 3, 9, 1, 7, 5, 8, 14, 13, 2, 6, 9 };
//	int size = sizeof(array) / sizeof(int);
//
//	//CreateHeap(array, size);
//	Heap heap;
//	HeapCreateHeap(&heap, array, size);
//	printf("½¨¶Ñ³É¹¦\n");
//	HeapInsert(&heap, 0);
//	printf("%d\n", HeapTop(&heap));
//	HeapPop(&heap);
//	printf("%d\n", HeapTop(&heap));
//}

void testHeapSort()
{
	int array[] = { 1, 5, 9, 4, 3, 6, 17, 8, 21, 44 };
	int size = sizeof(array) / sizeof(int);
	HeapSort(array, size);

	for (int i = 0; i < size; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
}

int main()
{
	//test();
	testHeapSort();
	system("pause");
	return 0;
}