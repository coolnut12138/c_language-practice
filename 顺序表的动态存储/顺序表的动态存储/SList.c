#include "SList.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

void CheckCapacity(SeqList* psl){
	if (psl->size < psl->capacity){
		return;
	}
	//����ռ�
	SLDataType newCapacity = psl->capacity * 2;
	SLDataType *newArray = (SLDataType *)malloc(sizeof(SLDataType)* newCapacity);
	assert(newArray);
	//���
	for (size_t i = 0; i < psl->size; i++){
		newArray[i] = psl->array[i];
	}
	//�ͷ��ϵ�
	free(psl->array);
	//�����µ�
	psl->array = newArray;
	psl->capacity = newCapacity;
}

void SeqListInit(SeqList* psl, size_t capacity){
	assert(psl);
	psl->capacity = capacity;
	psl->size = 0;
	psl->array = (SLDataType *)malloc(sizeof(SLDataType) * capacity);
	//��������
	assert(psl->array != NULL);
}

void SeqListDestory(SeqList* psl){
	assert(psl);

	free(psl->array);
	psl->array = NULL;
	psl->capacity = psl->size = 0;
}

void SeqListPushBack(SeqList* psl, SLDataType x){
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}

void SeqListPopBack(SeqList* psl){
	assert(psl);
	assert(psl->size > 0);
	psl->size--;
}

//ͷ��
void SeqListPushFront(SeqList* psl, SLDataType x){
	assert(psl);
	CheckCapacity(psl);
	for (size_t i = psl->size; i > 0; i--){
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[0] = x;
	psl->size++;
}
//ͷɾ
void SeqListPopFront(SeqList* psl){
	assert(psl);
	assert(psl->size > 0);
	for (size_t i = 0; i < psl->size - 1; i++){
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
//���ң��ҵ����ص�һ�����±꣬û�ҵ�����-1��
int SeqListFind(SeqList* psl, SLDataType x){
	assert(psl);
	for (size_t i = 0; i < psl->size; i++){
		if (x == psl->array[i]){
			return i;
		}
	}
	return -1;
}
//����
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x){
	assert(psl);
	assert(pos >= 0 && pos < psl->size);
	CheckCapacity(psl);
	for (size_t i = psl->size; i > pos; i--){
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}
//ɾ��
void SeqListErase(SeqList* psl, size_t pos){
	assert(psl);
	assert(psl->size > 0);
	assert(pos >= 0 && pos < psl->size);
	for (size_t i = pos; i < psl->size - 1; i++){
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
//ɾ������x
void SeqListRemoveAll(SeqList* psl, SLDataType x){
	//�������꣬�����ݲ�����xʱ��i �� j�������һλ
	//�����ݵ���xʱ��j ������i �����һλ��
	//����ʱ�临�Ӷ���O��n�����ռ临�Ӷ���O��1����
	assert(psl);
	assert(psl->size > 0);
	SLDataType j = 0;
	for (size_t i = 0; i < psl->size; i++){
		if (x != psl->array[i]){
			psl->array[j++] = psl->array[i];
		}
	}
	psl->size = j;
}
//�޸�posλ��
void SeqListModify(SeqList* psl, size_t pos, SLDataType x){
	assert(psl);
	assert(pos >= 0 && pos < psl->size);
	psl->array[pos] = x;
}

// ��չ������ʵ��
void SeqListBubbleSort(SeqList* psl){
	assert(psl);
	bool isSort = true;
	for (size_t i = 0; i < psl->size; i++){
		for (size_t j = 0; j < psl->size - 1 - i; j++){
			if (psl->array[j] > psl->array[j + 1]){
				SLDataType tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
				isSort = false;
			}
		}
		if (isSort == true){
			return;
		}
	}
}
int SeqListBinaryFind(SeqList* psl, SLDataType x){
	assert(psl);
	int left = 0;
	int right = psl->size;
	while (left <= right){
		int mid = (left + right) / 2;
		if (x == psl->array[mid]){
			return mid;
		}
		else if (x > psl->array[mid]){
			left = mid + 1;
		}
		else if (x < psl->array[mid]){
			right = mid - 1;
		}
	}
	return -1;
}




void SeqListPrint(SeqList* psl){
	for (size_t i = 0; i < psl->size; i++){
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}