#pragma once


//������������
typedef int SDataType;

//��̬˳���ʵ��ջ
//˳����С
#define MaxSize 100

typedef struct {
	SDataType array[MaxSize];
	int top; //���Ǳ�ʾ����Ĵ�С
}	Stack;

//��ʼ��
void StackInit(Stack *stack);

//����
void StackDestroy(Stack *stack);

//��ɾ�Ĳ�
//ֻ�ܴ�ջ������
//��
void StackPush(Stack *stack, SDataType val);

//ɾ
void StackPop(Stack *stack);

// ����ջ��Ԫ��
SDataType StackTop(Stack *stack);

// �ж��Ƿ�Ϊ��
int StackEmpty(const Stack *stack);


// ����ջ�����ݸ���
int StackSize(const Stack *stack);

void StackPrint(Stack *stack);