#pragma once

//向下调整
void AdjustDown(int array[], int size, int root);
//建堆
void CreateHeap(int array[], int size);

typedef int HPDataType;

typedef struct Heap{
	HPDataType *array;
	int size;
	int capacity;
}	Heap;


//数据结构建堆
void HeapCreateHeap(Heap *heap, int array[], int size);

//增加
void HeapInsert(Heap *heap, int val);

//删除（只能删除堆顶元素，因为只有堆顶元素有意义）
void HeapPop(Heap *heap);
//返回堆顶元素（最值）
HPDataType HeapTop(Heap *heap);

//向上调整
void AdjustUp(int array[], int size, int root);

//堆排序
void HeapSort(int array[], int size);