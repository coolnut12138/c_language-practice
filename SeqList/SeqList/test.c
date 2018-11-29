#define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
#include<assert.h>
#include<stdlib.h>

void Test1()
{
	SeqList seqList;
	SeqListInit(&seqList,10);//seqList的值需要发生变化，所以形参要传地址
	assert(seqList.size == 0);//初始化的顺序表应该是空的

#if 0
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPrint(&seqList);
	// 1 2 3

	SeqListPopBack(&seqList);
	SeqListPopBack(&seqList);
	SeqListPrint(&seqList);
	// 1

	SeqListPushFront(&seqList, 10);
	SeqListPushFront(&seqList, 20);
	SeqListPrint(&seqList);
	// 20 10 1

	SeqListPopFront(&seqList);
	SeqListPrint(&seqList);
	// 10 1
#endif
	for (int i = 0; i < 10; i++)
	{
		SeqListPushBack(&seqList,100+i);
	}
	SeqListPrint(&seqList);

	SeqListInsert(&seqList, 5, 1005);
	SeqListPrint(&seqList);

	SeqListInsert(&seqList, 0, 1000);
	SeqListPrint(&seqList);

	SeqListInsert(&seqList, seqList.size, 2000);
	SeqListPrint(&seqList);

	SeqListErase(&seqList, 0);
	SeqListErase(&seqList, 5);
	SeqListPrint(&seqList);

	SeqListDestroy(&seqList);
	SeqListPrint(&seqList);
}

void Test2()//测试冒泡
{
	SeqList seqList;
	SeqListInit(&seqList, 10);
	SeqListPushBack(&seqList, 6);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 5);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 7);

	SeqListBubbleSort(&seqList);
	SeqListPrint(&seqList);
	SeqListDestroy(&seqList);
}

void Test3()//测试删除遇到的所有data
{
	SeqList seqList;
	SeqListInit(&seqList, 10);

	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 2);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 1);
	SeqListPushBack(&seqList, 3);
	SeqListPushBack(&seqList, 4);

	SeqListPrint(&seqList);
	SeqListRemoveAll(&seqList, 3);
	SeqListPrint(&seqList);
	SeqListDestroy(&seqList);
}

int main()
{
	//Test1();
	//Test2();
	Test3();
	system("pause");
	return 0;
}