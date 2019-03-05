#pragma once
#include "maze.h"
#include <assert.h>

void StackInit(Stack *s){
	assert(s);
	s->array = (DataType *)malloc(sizeof(DataType) * stack_size);
	s->size = stack_size;
	s->top = 0;
}

void StackPush(Stack *s, DataType x){
	assert(s);
	if (s->size >= s->top){		//ջ��
		s->size *= 2;
		s->array = (DataType *)realloc(s->array, sizeof(DataType) * s->size);
		s->array[s->top] = x;
		s->top++;
	}
	else{
		s->array[s->top] = x;
		s->top++;
	}
}

void StackPop(Stack *s){
	assert(s);
	if (s->top == 0){
		return;
		printf("ջΪ��\n");
	}
	else{
		s->top--;
	}
}

int StackEmpty(Stack *s){
	assert(s);
	if (s->top == 0){
		return 1;
	}
	else{
		return 0;
	}
}

DataType StackTop(Stack *s){		//ȡջ��Ԫ��
	assert(s);

	DataType num = s->array[s->top - 1];
	return num;
}

void MazeInit(maze *m){
	assert(m);
	int arr[N][N] = {
		{ 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 1, 1, 1, 0 },
		{ 0, 0, 1, 0, 1, 1 },
		{ 0, 0, 1, 0, 0, 0 }
	};

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			m->mz[i][j] = arr[i][j];
		}
	}

	//��ʼ�����
	m->entry.row = 5;
	m->entry.col = 2;
}

void MazePrint(maze *m){
	assert(m);
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			printf("%d ", m->mz[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int CanPush(pos node, maze *m){
	if (node.row >= 0 && node.row < N && node.col >= 0 && node.col < N	//�������귶Χ
		&& m->mz[node.row][node.col] != 0 && m->mz[node.row][node.col] != 2){//��ΪǽҲ��Ϊ�߹���
		return 1;	//������ջ
	}

	return 0;
}

void AssignPosed(pos node, maze **m){	//��һ��ָ��Ļ��ı�ľ�ֻ���βε�ֵ
	(*m)->mz[node.row][node.col] = 2;
}

int CheckExit(pos node, maze *m){
	if ((node.row == 0) || (node.row == N - 1) || (node.col == 0) || (node.col == N - 1)){
		if ((node.row) != (m->entry.row) && (node.col != m->entry.col)){
			return 1;		//�������
		}
	}

	return 0;
}

void PrintStack(Stack *s){
	printf("�ҵ����ڣ�\n");
	printf("ջ��\n");
	for (size_t i = 0; i < s->top; i++){
		printf("[%d %d]\n", s->array[i].row, s->array[i].col);
	}
	printf("ջ��\n\n");
	printf("·������Ϊ��%d\n", s->top);
}

void GetPath(maze *m, pos node, Stack *s){
	assert(m);

	//1���ж���ǰ����ܷ���
	if (CanPush(node, m) == 1){
		//2������Ϸ��򽫵�ǰ��ǳ��߹��Ĳ���ջ
		AssignPosed(node, &m);
		StackPush(s, node);
	}
	else{
		return;
	}
	//ÿ��һ���ж�һ���Ƿ񵽴��յ�
	if (CheckExit(node, m) == 1){
		PrintStack(s);
		return;
	}

	//3���жϵ�ǰ���Ƿ��ǳ��ڣ��ǳ��ھ�return(��Ϊֻ��һ������)��
	//������ǳ��ڣ���˳ʱ��ķ���(�ϡ��ҡ��¡���)�����Աߵĵ��Ƿ������(����Ϊ 0 �� 2 �ĵ�)��
	//�ݹ��ظ�1-3��
	
	//��
	pos up = node;
	up.row -= 1;
	GetPath(m, up, s);

	//��
	pos right = node;
	right.col += 1;
	GetPath(m, right, s);

	//��
	pos down = node;
	down.row += 1;
	GetPath(m, down, s);

	//��
	pos left = node;
	left.col -= 1;
	GetPath(m, left, s);

	//4����һ������ĸ��㶼�Ѿ�̽������ͷ�����һ��ջ֡(���������涼�߲�ͨ�ĵ�)
	StackPop(s);
	return;
}

