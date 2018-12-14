#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include <stdio.h>
#include <assert.h>

//初始化
void StackInit(Stack *stack)
{
	stack->top = 0;
}

//销毁
void StackDestroy(Stack *stack)
{
	stack->top = 0;
}

void StackPush(Stack *stack, SDataType val)
{
	assert(stack != NULL);
	//判断栈内数据是否满了
	assert(stack->top < MaxSize);
	stack->array[stack->top] = val;
	stack->top++;
}

void StackPop(Stack *stack)
{
	assert(stack != NULL);
	assert(stack->top > 0);

	stack->top--;
}

SDataType StackTop(Stack *stack)
{
	assert(stack != NULL);
	assert(stack->top > 0);

	return stack->array[stack->top - 1];
}

int StackEmpty(const Stack *stack)
{
	return stack->top == 0 ? 1 : 0;
}

int StackSize(const Stack *stack)
{
	return stack->top;
}

void StackPrint(Stack *stack)
{
	assert(stack != NULL);
	for (int i = stack->top - 1; i >= 0; i--){
		printf("%d\n", stack->array[i]);
	}
}