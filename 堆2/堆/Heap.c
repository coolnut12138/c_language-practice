#include "Heap.h"
#include <assert.h>
#include <stdlib.h>

//array[size] ��ʾ�����Լ���С
//root ��ʾҪ�����Ľ����±�
//ǰ����[root]���ڵĽ�����������Ѿ�����ѵ�������
//��С��
void AdjustDown(int array[], int size, int root)
{
	while (1){
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int min;
		if (left >= size){
			//Խ�磬û������
			return;
		}

		//ȷ���ĸ�����С�ĺ���
		//�ȿ���û���Һ��ӣ��ٱȽ�ֵ
		//1.û���к��� ����С ->����
		//2.���Ҷ��У�����С��->����
		//3.���Ҷ��У��Һ���С�� ->�Һ���
		if (right < size && array[right] < array[left]){
			min = right;
		}
		else{
			min = left;
		}

		if (array[min] < array[root]){
			int tmp = array[root];
			array[root] = array[min];
			array[min] = tmp;
		}
		else{
			return;
		}
		//AdjustDown(array, size, min);
		root = min;
	}
}

//�����
void AdjustDown1(int array[], int size, int root)
{
	while (1){
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int max;
		if (left >= size){
			//Խ�磬û������
			return;
		}

		//ȷ���ĸ�����С�ĺ���
		//�ȿ���û���Һ��ӣ��ٱȽ�ֵ
		//1.û���к��� ����� ->����
		//2.���Ҷ��У����Ӵ�->����
		//3.���Ҷ��У��Һ��Ӵ� ->�Һ���
		if (right < size && array[right] > array[left]){
			max = right;
		}
		else{
			max = left;
		}

		if (array[max] > array[root]){
			int tmp = array[root];
			array[root] = array[max];
			array[max] = tmp;
		}
		else{
			return;
		}
		//AdjustDown(array, size, min);
		root = max;
	}
}

//����
void CreateHeap(int array[], int size)
{
	//�����һ����Ҷ�ӽ����е���,������ 0 ����
	//���һ����Ҷ�ӽ��������һ������˫�׽��
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown(array, size, i);
	}
}

//���ݽṹ���� 
void HeapCreateHeap(Heap *heap, int array[], int size)
{
	heap->size = size;
	heap->capacity = size *2; // ����������
	heap->array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++){
		heap->array[i] = array[i];
	}

	CreateHeap(heap->array, heap->size);
}

//����
void HeapInsert(Heap *heap, int val)
{
	heap->array[heap->size] = val;
	heap->size++;

	AdjustUp(heap->array, heap->size, heap->size - 1);
}

//ɾ���Ѷ�Ԫ�أ������һ��ֵ���ǵ�һ���Ѷ�Ԫ�أ�Ȼ�����µ���
void HeapPop(Heap *heap)
{
	assert(heap->size > 0);
	heap->array[0] = heap->array[heap->size - 1];
	heap->size--;

	AdjustDown(heap->array, heap->size, 0);
}

//���ضѶ�Ԫ��
HPDataType HeapTop(Heap *heap)
{
	assert(heap->size > 0);
	return heap->array[0];
}

//���룬���ϵ�����С��
//child ��Ҫ�����Ľ��
void AdjustUp(int array[], int size, int child)
{
	while (child != 0){
		if (array[child] >= array[(child - 1) / 2]){
			return;
		}
		int tmp = array[child];
		array[child] = array[(child - 1) / 2];
		array[(child - 1) / 2] = tmp;

		child = (child - 1) / 2;
	}
	
}

//������
void HeapSort(int array[], int size)
{
	//���ѣ���������򣬾ͽ����
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown1(array, size, i);
	}

	//���ü����㷨��ÿ��ѡ������������ֵ�����������
	//һ��Ҫѡ��size
	for (int j = 0; j < size; j++){
		int t = array[0];
		array[0] = array[size - 1 - j];
		array[size - 1 - j] = t;

		//����һ�Σ�ǰ��Ķѽṹ�Ѿ��ƻ��������ٽ���һ�����µ���
		//���ǰ�潨����С�ѣ�����һ�Σ��͵����½��ѣ�ʱ�临�ӶȾ���n^2*logN
		AdjustDown1(array, size - 1 - j, 0);
	}
}