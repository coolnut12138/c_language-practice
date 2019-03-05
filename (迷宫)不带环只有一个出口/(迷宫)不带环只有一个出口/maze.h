#pragma once
#include <stdio.h>
#include <stdlib.h>
//�������ݣ�
//�� һ���ṹ�壬���ڼ�¼�Թ�ÿ����ĺ�������
//�� ����ջ path �� shortpath����¼ͨ·����̾��룬վ��Ԫ�����м�����̾���
//�� �Թ��������Թ���ͼ����ڵ㣩

#define N 6				//�Թ����ݳ���
#define stack_size 20	//ջ��С

typedef struct pos {	//�Թ���ÿ���������
	int row;
	int col;
}	pos;

typedef pos DataType;

typedef struct Stack{		//��Ž����Ϣ��ջ
	DataType *array;  //����ָ��
	size_t top;		  //ջ��
	size_t size;		  //�������
}	Stack;

typedef struct maze{		//�Թ�
	int mz[N][N];
	pos entry;		//���
}	maze;

void StackInit(Stack *s);
void StackPush(Stack *s, DataType x);
void StackPop(Stack *s);
int StackEmpty(Stack *s);
void MazeInit(maze *m);	//�Թ���ʼ��
void MazePrint(maze *m); //��ӡ�Թ�
int CanPush(pos node, maze *m);		//�ܷ���ջ
void AssignPosed(pos node, maze **m);		//����߹��ļ�Ϊ 2
int CheckExit(pos node, maze *m);	//����Ƿ񵽴����
void PrintStack(Stack *s);	//�ҵ����ڣ���ӡջ��Ԫ��
void GetPath(maze *m, pos node, Stack *s);
