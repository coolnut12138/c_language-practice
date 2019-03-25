#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
void Merge(int array[], int left, int mid, int right, int extra[]) {
	int size = right - left;
	int left_index = left;
	int right_index = mid;
	int extra_index = 0;

	while (left_index < mid && right_index < right) {
		if (array[left_index] <= array[right_index]) {
			extra[extra_index] = array[left_index];
			left_index++;
		}
		else {
			extra[extra_index] = array[right_index];
			right_index++;
		}

		extra_index++;
	}

	while (left_index < mid) {
		extra[extra_index++] = array[left_index++];
	}

	while (right_index < right) {
		extra[extra_index++] = array[right_index++];
	}

	for (int i = 0; i < size; i++) {
		array[left + i] = extra[i];
	}
}

// 要排序的区间是 array[left, right)
void __MergeSort(int array[], int left, int right, int extra[]) {
	// 终止条件
	// [3, 4)
	if (right == left + 1) {
		// 只剩一个数
		return;
	}

	if (right <= left) {
		// 区间内没有数了
		return;
	}

	int mid = left + (right - left) / 2;
	// [left, mid)	[mid, right)
	__MergeSort(array, left, mid, extra);
	__MergeSort(array, mid, right, extra);
	// 左右区间都有序
	Merge(array, left, mid, right, extra);
}

void MergeSort(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);
	__MergeSort(array, 0, size, extra);
	free(extra);
}


void MergeSortNor(int array[], int size) {
	int *extra = (int *)malloc(sizeof(int)* size);

	for (int i = 1; i < size; i = i * 2) {
		for (int j = 0; j < size; j = j + 2 * i) {
			int left, mid, right;
			left = j;
			mid = j + i;
			right = mid + i;
			if (mid >= size) {
				// 没有右边的区间 [mid, right)
				continue;
			}

			if (right > size) {
				right = size;
			}

			Merge(array, left, mid, right, extra);
		}
	}

	free(extra);
}

int main() {
	int array[] = { 3, 9, 1, 4, 7, 8, 3, 5 };
	int size = sizeof(array) / sizeof(int);
	MergeSortNor(array, size);
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	system("pause");
	return 0;
}