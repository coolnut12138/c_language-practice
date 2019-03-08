#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//ֱ�Ӳ�������
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

//ϣ������
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

//ѡ������
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

//ð������
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

//������
//�����
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

//��������

int Partition_1(int arr[], int left, int right){//hover��
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

int Partition_2(int arr[], int left, int right){	//�ڿӷ�
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

int Partition_3(int arr[], int left, int right){ //ǰ���±�
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
		//������ֻ��һ����
		return;
	}
	if (left > right){
		//������û����
		return;
	}

	//��׼ֵ�� arr[right]
	int div;  //�����������ջ�׼ֵ���ڵ��±�
	div = Partition_3(arr, left, right); //����arr[left, right],��С�ķ��󣬴�ķ��ң���������׼ֵ���ڵ��±�

	//��ʱ���䱻�ֳ���
	//[left, div - 1] �Ȼ�׼ֵС
	//[div, div]	  ��׼ֵ
	//[div + 1, right]�Ȼ�׼ֵ��
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