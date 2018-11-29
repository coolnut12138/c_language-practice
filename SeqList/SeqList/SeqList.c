#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

//����Ƿ���Ҫ����
void CheckCapacity(SeqList *sl)
{
	//��size���ڵ���capacityʱ����Ҫ���ݣ����ڵ�ʱ��Ҳ��Ҫ
	//����������
	if (sl->size < sl->capacity)
	{ 
		return;
	}
	//1.�����¿ռ�
	int newCapacity = sl->capacity * 2;
	SLDataType *newArray = (SLDataType *)malloc(sizeof(SLDataType)* newCapacity);
	assert(newArray);
	//2.���
	for (int i = 0; i < sl->size; i++)
	{
		newArray[i] = sl->array[i];
	}
	//3.�ͷ��ϵģ��ͷ�ԭ���Ŀռ䣩
	free(sl->array);
	//4.�����µ�
	sl->array = newArray;
	sl->capacity = newCapacity;
}

void SeqListInit(SeqList *sl, size_t capacity)
{
	//��������ָ�벻��Ϊ��
	assert(sl != NULL);
	//��������ֵΪcapacity
	//��size ��ֵΪ0
	//��array ���ٿռ䣨���ϣ����ռ��СΪcapacity
	sl->size = 0;
	sl->capacity = capacity;
	sl->array = (SLDataType *)malloc(capacity * sizeof(SLDataType));
	//�ǵ���������
	assert(sl->array != NULL);
}

void SeqListDestroy(SeqList *sl)
{
	assert(sl != NULL);

	//�Ƽ������ŵ�˳���ͷţ���ջ��ԭ��һ��
	free(sl->array);
	sl->array = NULL;//�����Դ��룬��ֹ�´�Ӧ��ʱ���ִ���
	sl->capacity = sl->size = 0;
}

//��
//β��
void SeqListPushBack(SeqList *sl, SLDataType data)
{
	CheckCapacity(sl);

	sl->array[sl->size] = data;
	sl->size += 1;
}

// βɾ��ɾ��˳���β��������
void SeqListPopBack(SeqList *sl)
{
	assert(sl != NULL);
	assert(sl->size > 0);//��Ҫ������������Ч���ݵĸ���ԭ���Ƿ�Ϊ0�����Ϊ0�Ǿ�û�б�Ҫ��ɾ��
	sl->size--;
}

//ͷ��
void SeqListPushFront(SeqList *sl, SLDataType data)
{
	SeqListInsert(sl,0,data);//ͷ��Ҳ����ֱ�ӵ��ò��뺯��������д��һ������
#if 0
	assert(sl != NULL);
	//����Ƿ���Ҫ����
	CheckCapacity(sl);
	for (int i = sl->size; i >= 1; i--)
	{
		sl->array[i] = sl->array[i - 1];
	}
	sl->array[0] = data;
	sl->size++;
#endif
}

// ͷɾ��ɾ��˳���ͷ��������
void SeqListPopFront(SeqList *sl)
{
	assert(sl != NULL);
	assert(sl->size > 0);
	for (int i = 0; i < sl->size - 1; i++)//i�������±꣬[0,size-1]
	{
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}

//�м��
void SeqListInsert(SeqList * sl, size_t pos, SLDataType data)
{
	assert(sl);
	CheckCapacity(sl);
	assert(pos >= 0 && (int)pos <= sl->size);
	//�˴���i�������±�
	for (int i = sl->size - 1; i >= (int)pos; i--)
	{
		sl->array[i + 1] = sl->array[i];
	}
	sl->array[pos] = data;
	sl->size++;
}

//ɾ��pos���ڵ��±�����
void SeqListErase(SeqList *sl, size_t pos)
{
	assert(sl != NULL);
	assert(sl->size > 0);
	assert(pos >= 0 && (int)pos < sl->size);
	for (int i = pos; i < sl->size - 1; i++)
	{
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}

//����
int SeqListFind(SeqList *sl, SLDataType data)
{
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->array[i] == data)
		{
			return i;
		}
	}
	//û�ҵ�����-1
	return -1;
}

//ɾ����һ��������data
void SeqListRemove(SeqList *sl, SLDataType data)
{
	assert(sl != NULL);
	int pos = SeqListFind(sl, data);
	if (pos != -1)
	{
		SeqListErase(sl, pos);
	}
}

//ɾ�����������е�data
void SeqListRemoveAll(SeqList *sl, SLDataType data)
{
#if 0 //ʱ�临�Ӷ� O(n^2)
	int pos;
	while ((pos = SeqListFind(sl, data)) != -1)  //O(n)
	{
		SeqListErase(sl, pos); //O(n)
	}
#endif

#if 0 //ʱ�临�Ӷ�O(n),�ռ临�Ӷ�O(n)
	SLDataType *tempArray = (SLDataType *)malloc(sizeof(SLDataType)* sl->size);
	assert(tempArray != NULL);
	//����һ��������Ѳ�����data�����ݷŽ�ȥ�������ռ临�Ӷ���O(n)
	int j = 0;
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->array[i] != data)
		{
			tempArray[j++] = sl->array[i];
		}
	}
	for (int k = 0; k < j; j++)
	{
		sl->array[k] = tempArray[k];
	}
	sl->size = j;
#endif

//������������i��j�������ݲ�����dataʱ��i��j�������ƶ���
//�����ݵ���dataʱ j ������i ����ƶ�
//���±�Ϊ i �����ݲ�����dataʱ ���±�Ϊ i �����ݷ����±�Ϊj�����ݴ���Ȼ�� i ����ƶ���j ����ƶ�
//�Դ�����
	//������ʱ�临�Ӷ���O(n) �ռ临�Ӷ���O(1)
	int j = 0;
	for (int i = 0; i < sl->size; i++)
	{
		if (data != sl->array[i])
		{
			sl->array[j++] = sl->array[i];
		}
	}
	sl->size = j;
}

//�޸�pos ���ڵ��±�
void SeqListModify(SeqList *sl, size_t pos, SLDataType data)
{
	assert(sl != NULL);
	assert(pos >= 0 && (int)pos < sl->size);

	sl->array[pos] = data;
}

static void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//ð������
void SeqListBubbleSort(SeqList *sl)
{
	assert(sl != NULL);
	for (int i = 0; i < sl->size - 1; i++)
	{
		bool isSort = true;
		for (int j = 0; j <= sl->size - 2 - i; j++)
		{
			if (sl->array[j] > sl->array[j + 1])
			{
				Swap(sl->array + j, sl->array + j + 1);
				isSort = false;
			}
		}
		if (true == isSort)
		{
			return;
		}
	}
}

//���ֲ��ң�ǰ������������
int SeqListBinarySearch(SeqList *sl, SLDataType data)
{
	int left = 0;
	int right = sl->size;
	//[left,right)
	//left��right֮��û������ʱ��Ͳ���Ҫ����
	while (left < right)
	{
		int mid = left + (right - left) / 2;
		if (data == sl->array[mid])
		{
			return mid;
		}
		else if (data < sl->array[mid])
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return -1;
}

//��ӡ
void SeqListPrint(SeqList *sl)
{
	for (int i = 0; i < sl->size; i++){
		printf("%d ", sl->array[i]);
	}
	printf("\n");
}