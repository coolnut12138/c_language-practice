#include "Heap.h"
#include <assert.h>
#include <stdlib.h>

//array[size] 表示数组以及大小
//root 表示要调整的结点的下标
//前提是[root]所在的结点左右子树已经满足堆的性质了
//建小堆
void AdjustDown(int array[], int size, int root)
{
	while (1){
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int min;
		if (left >= size){
			//越界，没有左孩子
			return;
		}

		//确定哪个是最小的孩子
		//先看有没有右孩子，再比较值
		//1.没有有孩子 ，最小 ->左孩子
		//2.左右都有，左孩子小。->左孩子
		//3.左右都有，右孩子小。 ->右孩子
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

//建大堆
void AdjustDown1(int array[], int size, int root)
{
	while (1){
		int left = root * 2 + 1;
		int right = root * 2 + 2;
		int max;
		if (left >= size){
			//越界，没有左孩子
			return;
		}

		//确定哪个是最小的孩子
		//先看有没有右孩子，再比较值
		//1.没有有孩子 ，最大 ->左孩子
		//2.左右都有，左孩子大。->左孩子
		//3.左右都有，右孩子大。 ->右孩子
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

//建堆
void CreateHeap(int array[], int size)
{
	//从最后一个非叶子结点进行调整,调整到 0 结束
	//最后一个非叶子结点就是最后一个结点的双亲结点
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown(array, size, i);
	}
}

//数据结构建堆 
void HeapCreateHeap(Heap *heap, int array[], int size)
{
	heap->size = size;
	heap->capacity = size *2; // 不考虑扩容
	heap->array = (int *)malloc(sizeof(int)* size);
	for (int i = 0; i < size; i++){
		heap->array[i] = array[i];
	}

	CreateHeap(heap->array, heap->size);
}

//增加
void HeapInsert(Heap *heap, int val)
{
	heap->array[heap->size] = val;
	heap->size++;

	AdjustUp(heap->array, heap->size, heap->size - 1);
}

//删除堆顶元素，用最后一个值覆盖第一个堆顶元素，然后向下调整
void HeapPop(Heap *heap)
{
	assert(heap->size > 0);
	heap->array[0] = heap->array[heap->size - 1];
	heap->size--;

	AdjustDown(heap->array, heap->size, 0);
}

//返回堆顶元素
HPDataType HeapTop(Heap *heap)
{
	assert(heap->size > 0);
	return heap->array[0];
}

//插入，向上调整，小堆
//child 是要调整的结点
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

//堆排序
void HeapSort(int array[], int size)
{
	//建堆，如果排升序，就建大堆
	for (int i = (size - 2) / 2; i >= 0; i--){
		AdjustDown1(array, size, i);
	}

	//利用减治算法，每次选出数组中最大的值，交换到最后
	//一共要选出size
	for (int j = 0; j < size; j++){
		int t = array[0];
		array[0] = array[size - 1 - j];
		array[size - 1 - j] = t;

		//交换一次，前面的堆结构已经破坏，所以再进行一次向下调整
		//如果前面建的是小堆，交换一次，就得重新建堆，时间复杂度就是n^2*logN
		AdjustDown1(array, size - 1 - j, 0);
	}
}