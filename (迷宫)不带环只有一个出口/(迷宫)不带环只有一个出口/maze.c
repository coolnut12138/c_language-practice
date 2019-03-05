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
	if (s->size >= s->top){		//栈满
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
		printf("栈为空\n");
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

DataType StackTop(Stack *s){		//取栈顶元素
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

	//初始化入口
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
	if (node.row >= 0 && node.row < N && node.col >= 0 && node.col < N	//符合坐标范围
		&& m->mz[node.row][node.col] != 0 && m->mz[node.row][node.col] != 2){//不为墙也不为走过的
		return 1;	//可以入栈
	}

	return 0;
}

void AssignPosed(pos node, maze **m){	//传一级指针的话改变的就只是形参的值
	(*m)->mz[node.row][node.col] = 2;
}

int CheckExit(pos node, maze *m){
	if ((node.row == 0) || (node.row == N - 1) || (node.col == 0) || (node.col == N - 1)){
		if ((node.row) != (m->entry.row) && (node.col != m->entry.col)){
			return 1;		//到达出口
		}
	}

	return 0;
}

void PrintStack(Stack *s){
	printf("找到出口！\n");
	printf("栈顶\n");
	for (size_t i = 0; i < s->top; i++){
		printf("[%d %d]\n", s->array[i].row, s->array[i].col);
	}
	printf("栈底\n\n");
	printf("路径长度为：%d\n", s->top);
}

void GetPath(maze *m, pos node, Stack *s){
	assert(m);

	//1、判定当前结点能否走
	if (CanPush(node, m) == 1){
		//2、如果合法则将当前标记成走过的并入栈
		AssignPosed(node, &m);
		StackPush(s, node);
	}
	else{
		return;
	}
	//每走一步判断一次是否到达终点
	if (CheckExit(node, m) == 1){
		PrintStack(s);
		return;
	}

	//3、判断当前点是否是出口，是出口就return(因为只有一个出口)，
	//如果不是出口，按顺时针的方向(上、右、下、左)遍历旁边的点是否可以走(即不为 0 和 2 的点)，
	//递归重复1-3步
	
	//上
	pos up = node;
	up.row -= 1;
	GetPath(m, up, s);

	//右
	pos right = node;
	right.col += 1;
	GetPath(m, right, s);

	//下
	pos down = node;
	down.row += 1;
	GetPath(m, down, s);

	//左
	pos left = node;
	left.col -= 1;
	GetPath(m, left, s);

	//4、当一个点的四个点都已经探测过，就返回上一层栈帧(就是有三面都走不通的点)
	StackPop(s);
	return;
}

