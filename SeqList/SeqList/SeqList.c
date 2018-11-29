#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

//检查是否需要扩容
void CheckCapacity(SeqList *sl)
{
	//当size大于等于capacity时就需要扩容，等于的时候也需要
	//不符合条件
	if (sl->size < sl->capacity)
	{ 
		return;
	}
	//1.申请新空间
	int newCapacity = sl->capacity * 2;
	SLDataType *newArray = (SLDataType *)malloc(sizeof(SLDataType)* newCapacity);
	assert(newArray);
	//2.搬家
	for (int i = 0; i < sl->size; i++)
	{
		newArray[i] = sl->array[i];
	}
	//3.释放老的（释放原来的空间）
	free(sl->array);
	//4.保存新的
	sl->array = newArray;
	sl->capacity = newCapacity;
}

void SeqListInit(SeqList *sl, size_t capacity)
{
	//传进来的指针不能为空
	assert(sl != NULL);
	//给容量赋值为capacity
	//给size 赋值为0
	//给array 开辟空间（堆上），空间大小为capacity
	sl->size = 0;
	sl->capacity = capacity;
	sl->array = (SLDataType *)malloc(capacity * sizeof(SLDataType));
	//记得做错误检查
	assert(sl->array != NULL);
}

void SeqListDestroy(SeqList *sl)
{
	assert(sl != NULL);

	//推荐按进门的顺序释放，和栈的原理一样
	free(sl->array);
	sl->array = NULL;//防御性代码，防止下次应用时出现错误
	sl->capacity = sl->size = 0;
}

//增
//尾插
void SeqListPushBack(SeqList *sl, SLDataType data)
{
	CheckCapacity(sl);

	sl->array[sl->size] = data;
	sl->size += 1;
}

// 尾删，删除顺序表尾部的数据
void SeqListPopBack(SeqList *sl)
{
	assert(sl != NULL);
	assert(sl->size > 0);//还要检查这个数组有效数据的个数原本是否为0，如果为0那就没有必要再删了
	sl->size--;
}

//头插
void SeqListPushFront(SeqList *sl, SLDataType data)
{
	SeqListInsert(sl,0,data);//头插也可以直接调用插入函数，参数写第一个即可
#if 0
	assert(sl != NULL);
	//检查是否需要扩容
	CheckCapacity(sl);
	for (int i = sl->size; i >= 1; i--)
	{
		sl->array[i] = sl->array[i - 1];
	}
	sl->array[0] = data;
	sl->size++;
#endif
}

// 头删，删除顺序表头部的数据
void SeqListPopFront(SeqList *sl)
{
	assert(sl != NULL);
	assert(sl->size > 0);
	for (int i = 0; i < sl->size - 1; i++)//i是数据下标，[0,size-1]
	{
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}

//中间插
void SeqListInsert(SeqList * sl, size_t pos, SLDataType data)
{
	assert(sl);
	CheckCapacity(sl);
	assert(pos >= 0 && (int)pos <= sl->size);
	//此处的i是数据下标
	for (int i = sl->size - 1; i >= (int)pos; i--)
	{
		sl->array[i + 1] = sl->array[i];
	}
	sl->array[pos] = data;
	sl->size++;
}

//删除pos所在的下标数据
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

//查找
int SeqListFind(SeqList *sl, SLDataType data)
{
	for (int i = 0; i < sl->size; i++)
	{
		if (sl->array[i] == data)
		{
			return i;
		}
	}
	//没找到返回-1
	return -1;
}

//删除第一个遇到的data
void SeqListRemove(SeqList *sl, SLDataType data)
{
	assert(sl != NULL);
	int pos = SeqListFind(sl, data);
	if (pos != -1)
	{
		SeqListErase(sl, pos);
	}
}

//删除遇到的所有的data
void SeqListRemoveAll(SeqList *sl, SLDataType data)
{
#if 0 //时间复杂度 O(n^2)
	int pos;
	while ((pos = SeqListFind(sl, data)) != -1)  //O(n)
	{
		SeqListErase(sl, pos); //O(n)
	}
#endif

#if 0 //时间复杂度O(n),空间复杂度O(n)
	SLDataType *tempArray = (SLDataType *)malloc(sizeof(SLDataType)* sl->size);
	assert(tempArray != NULL);
	//开辟一个新数组把不等于data的数据放进去，这样空间复杂度是O(n)
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

//定义两个变量i，j，当数据不等于data时，i和j都往后移动；
//当数据等于data时 j 不动，i 向后移动
//当下标为 i 的数据不等于data时 将下标为 i 的数据放在下标为j的数据处，然后 i 向后移动，j 向后移动
//以此类推
	//这样的时间复杂度是O(n) 空间复杂度是O(1)
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

//修改pos 所在的下标
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

//冒泡排序
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

//二分查找（前提是数据有序）
int SeqListBinarySearch(SeqList *sl, SLDataType data)
{
	int left = 0;
	int right = sl->size;
	//[left,right)
	//left和right之间没有数的时候就不需要找了
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

//打印
void SeqListPrint(SeqList *sl)
{
	for (int i = 0; i < sl->size; i++){
		printf("%d ", sl->array[i]);
	}
	printf("\n");
}