#pragma once

//���µ���
void AdjustDown(int array[], int size, int root);
//����
void CreateHeap(int array[], int size);

typedef int HPDataType;

typedef struct Heap{
	HPDataType *array;
	int size;
	int capacity;
}	Heap;


//���ݽṹ����
void HeapCreateHeap(Heap *heap, int array[], int size);

//����
void HeapInsert(Heap *heap, int val);

//ɾ����ֻ��ɾ���Ѷ�Ԫ�أ���Ϊֻ�жѶ�Ԫ�������壩
void HeapPop(Heap *heap);
//���ضѶ�Ԫ�أ���ֵ��
HPDataType HeapTop(Heap *heap);

//���ϵ���
void AdjustUp(int array[], int size, int root);

//������
void HeapSort(int array[], int size);