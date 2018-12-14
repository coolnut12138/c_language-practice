#pragma once


//定义数据类型
typedef int SDataType;

//静态顺序表实现栈
//顺序表大小
#define MaxSize 100

typedef struct {
	SDataType array[MaxSize];
	int top; //就是表示数组的大小
}	Stack;

//初始化
void StackInit(Stack *stack);

//销毁
void StackDestroy(Stack *stack);

//增删改查
//只能从栈顶操作
//增
void StackPush(Stack *stack, SDataType val);

//删
void StackPop(Stack *stack);

// 返回栈顶元素
SDataType StackTop(Stack *stack);

// 判断是否为空
int StackEmpty(const Stack *stack);


// 返回栈内数据个数
int StackSize(const Stack *stack);

void StackPrint(Stack *stack);