#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//直接插入排序
void InsertSort(int arr[], int size) {
	for (int i = 0; i < size; i++){
		int key = arr[i];
		int j;
		for (j = i - 1; j >= 0 && arr[j] > key; j--){
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = key;
	}
}

//希尔排序
void InsertSortWithGap(int arr[], int size, int gap){
	for (int i = 0; i < size; i++){
		int key = arr[i];
		int j;
		for (j = i - gap; j >= 0 && arr[j] > key; j -= gap){
			arr[j + gap] = arr[j];
		}
		arr[j + gap] = key;
	}
}

void ShellSort(int arr[], int size){
	int gap = size;
	while (1){
		gap = gap / 3 + 1;
		InsertSortWithGap(arr, size, gap);
		if (gap == 1){
			break;
		}
	}
}

void Swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}

//选择排序
void SelectSort(int arr[], int size){
	for (int i = 0; i < size; i++){
		int max = 0; 
		for (int j = 0; j < size - i; j++){
			if (arr[j] > arr[max]){
				max = j;
			}
		}
		Swap(arr + max, arr + size - i - 1);
	}
}

//冒泡排序
void BubbleSort(int arr[], int size){
	for (int i = 0; i < size; i++){
		int sorted = 1;
		for (int j = 0; j < size - i - 1; j++){
			if (arr[j] > arr[j + 1]){
				Swap(arr + j, arr + j + 1);
			}
			sorted = -1;
		}
		if (sorted == 1){
			break;
		}
	}
}

//堆排序
//建大堆
void AdjustDown(int arr[], int size, int root){
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	int max;
	if (left >= size){
		return;
	}

	if (right < size && arr[right] > arr[left]){
		max = right;
	}
	else{
		max = left;
	}

	if (arr[root] >= arr[max]){
		return;
	}

	Swap(arr + root, arr + max);
	AdjustDown(arr, size, max);
}

void CreateHeap(int arr[], int size){
	for (int i = (size - 1 - 1) / 2; i >= 0; i--){
		AdjustDown(arr, size, i);
	}
}

void HeapSort(int arr[], int size){
	CreateHeap(arr, size);
	for (int i = 0; i < size; i++){
		Swap(arr, arr + size - i - 1);
		AdjustDown(arr, size - i - 1, 0);
	}
}

//快速排序

int Partition_1(int arr[], int left, int right){//hover法
	int begin = left;
	int end = right;
	while (begin < end){
		while (begin < end && arr[begin] <= arr[right]){
			begin++;
		}

		while (begin < end && arr[end] >= arr[right]){
			end--;
		}

		Swap(arr + begin, arr + end);
	}

	Swap(arr + begin, arr + right);
	return begin;
}

int Partition_2(int arr[], int left, int right){	//挖坑法
	int begin = left;
	int end = right;
	int pivot = arr[right];
	while (begin < end) {
		while (begin < end && arr[begin] <= pivot){
			begin++;
		}
		arr[end] = arr[begin];

		while (begin < end && arr[end] >= pivot){
			end--;
		}
		arr[begin] = arr[end];
	}
	arr[begin] = pivot;
	return begin;
}

int Partition_3(int arr[], int left, int right){ //前后下标
	int div = left;
	for (int i = left; i < right; i++){
		if (arr[i] < arr[right]){
			Swap(arr + i, arr + div);
			div++;
		}
	}

	Swap(arr + div, arr + right);
	return div;
}

void __QuickSort(int arr[], int left, int right){
	if (left == right){
		//区间内只有一个数
		return;
	}
	if (left > right){
		//区间内没有数
		return;
	}

	//基准值是 arr[right]
	int div;  //用来保存最终基准值所在的下标
	div = Partition_3(arr, left, right); //遍历arr[left, right],把小的放左，大的放右，返回最后基准值所在的下标

	//此时区间被分成了
	//[left, div - 1] 比基准值小
	//[div, div]	  基准值
	//[div + 1, right]比基准值大
	__QuickSort(arr, left, div - 1);
	__QuickSort(arr, div + 1, right);
}

void QuickSort(int arr[], int size){
	__QuickSort(arr, 0, size - 1);
}


int main(){
	int arr[] = { 2, 3, 1, 4, 62, 4, 6, 2 };
	int size = sizeof(arr) / sizeof(arr[0]);
	//InsertSort(arr, size);
	//ShellSort(arr, size);
	//SelectSort(arr, size);
	//BubbleSort(arr, size);
	//HeapSort(arr, size);
	QuickSort(arr, size);
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}