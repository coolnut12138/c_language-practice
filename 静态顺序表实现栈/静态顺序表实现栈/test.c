#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

void test(){
	Stack stack;
	StackInit(&stack);

	StackPush(&stack, 3);
	StackPush(&stack, 7);
	StackPush(&stack, 1);
	StackPrint(&stack);

	StackPop(&stack);
	StackPrint(&stack);

	printf("%d\n", StackTop(&stack));
	printf("%d\n", StackEmpty(&stack));
	printf("%d\n", StackSize(&stack));

	StackDestroy(&stack);
}

int main()
{
	test();
	system("pause");
	return 0;
}