#pragma once
#include "slist.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

void SeqListInit(SeqList *sl){
	assert(sl);
	memset(sl->array, 0, sizeof(SLDataType) * N);
	sl->size = 0;
}

void SeqListDestory(SeqList* sl){
	assert(sl);
	sl->size = 0;
}

void SeqListPushBack(SeqList* sl, SLDataType val){
	assert(sl);

	if (sl->size >= N){
		printf("���Ա�����");
		return;
	}

	sl->array[sl->size] = val;
	sl->size++;
}

void SeqListPopBack(SeqList* sl){
	assert(sl);
	if (sl->size == 0){
		printf("��Ϊ�գ�ɾ��ʧ�ܣ�");
		return;
	}

	sl->array[sl->size] = 0;
	sl->size--;
}

//ͷ��
void SeqListPushFront(SeqList* sl, SLDataType val){
	assert(sl);
	if (sl->size >= N){
		printf("�����ˣ�����ʧ�ܣ�");
		return;
	}
	for (size_t i = sl->size; i > 0; i--){
		sl->array[i] = sl->array[i - 1];
	}
	sl->array[0] = val;
	sl->size++;
}
//ͷɾ
void SeqListPopFront(SeqList* sl){
	assert(sl);
	assert(sl->size > 0);
	for (size_t i = 0; i < sl->size - 1; i++){
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}
//����
int SeqListFind(SeqList* sl, SLDataType val){
	assert(sl);
	for (size_t i = 0; i < sl->size; i++){
		if (sl->array[i] == val){
			return i;
		}
	}
	return -1;
}
//����,��posλ�ò���val
void SeqListInsert(SeqList* sl, size_t pos, SLDataType val){
	assert(sl);
	if (sl->size >= N){
		printf("�����ˣ�ɾ��ʧ�ܣ�");
		return;
	}
	for (size_t i = sl->size; i > pos; i--){
		sl->array[i] = sl->array[i - 1];
	}
	sl->array[pos] = val;
	sl->size++;
}
//ɾ��ָ��λ��
void SeqListErase(SeqList* sl, size_t pos){
	assert(sl);
	assert(sl->size > 0);
	//ע��pos��ֵ���ܳ���Χ
	assert(pos >= 0 && (int)pos < sl->size);
	for (size_t i = pos; i < sl->size - 1; i++){
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}
//ɾ�����е���val��ֵ
void SeqListRemove(SeqList* sl, SLDataType val){
	assert(sl);
	size_t j = 0;
	for (size_t i = 0; i < sl->size; i++){
		if (val != sl->array[i]){
			sl->array[j++] = sl->array[i];
		}
	}
	sl->size = j;
}
//�޸�ָ��λ�õ�ֵ
void SeqListModify(SeqList* sl, size_t pos, SLDataType val){
	assert(sl);
	assert(pos >= 0 && pos < sl->size);
	sl->array[pos] = val;
}

void SeqListBubbleSort(SeqList *sl){
	assert(sl);
	bool isSort = true;
	for (size_t i = 0; i < sl->size; i++){
		for (size_t j = 0; j < sl->size - 1 - i; j++){
			if (sl->array[j] > sl->array[j + 1]){
				int tmp = sl->array[j];
				sl->array[j] = sl->array[j + 1];
				sl->array[j + 1] = tmp;
				isSort = false;
			}
		}
		if (isSort == true){
			return;
		}
	}
}

int SeqListBinarySearch(SeqList *sl, SLDataType val){
	assert(sl);
	int left = 0;
	int right = sl->size;
	while (left <= right){
		int mid = (left + right) / 2;
		if (val == sl->array[mid]){
			return mid;
		}
		else if (val > sl->array[mid]){
			left = mid + 1;
		}
		else if (val < sl->array[mid]){
			right = mid - 1;
		}
	}
	return -1;
}

void SeqListPrint(SeqList* sl){
	assert(sl);
	for (size_t i = 0; i < sl->size; i++){
		printf("%d ", sl->array[i]);
	}
	printf("\n");
}