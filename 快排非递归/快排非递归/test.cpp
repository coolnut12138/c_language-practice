#define _CRT_SECURE_NO_WARNINGS 1
#include <stack>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int arr[], int left, int right){
	int begin = left;
	int end = right;
	while (begin < end){
		while (begin < end && arr[begin] <= arr[right]){
			begin++;
		}

		while (begin < end && arr[end] >= arr[right]) {
			end--;
		}
		swap(arr + begin, arr + end);
	}
	swap(arr + begin, arr + right);
	return begin;
}

void QuickSortNor(int arr[], int size){
	std::stack<int>	stack;
	stack.push(size - 1);	//right
	stack.push(0);	//left

	while (!stack.empty())	{
		int left = stack.top(); stack.pop();
		int right = stack.top(); stack.pop();

		if (left >= right){
			continue;
		}
		else{
			int d = partition(arr, left, right);
			stack.push(right);
			stack.push(d + 1);
			stack.push(d - 1);
			stack.push(left);
		}
	}
}

int main()
{
	int arr[] = { 2, 3, 1, 41, 2, 52, 6, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);
	QuickSortNor(arr, size);
	for (int i = 0; i < size; i++){
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}