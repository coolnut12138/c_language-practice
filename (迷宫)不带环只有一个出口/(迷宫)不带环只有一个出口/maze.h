#pragma once
#include <stdio.h>
#include <stdlib.h>
//定义内容：
//① 一个结构体，用于记录迷宫每个点的横纵坐标
//② 两个栈 path 和 shortpath，记录通路的最短距离，站内元素序列即是最短距离
//③ 迷宫（包括迷宫地图和入口点）

#define N 6				//迷宫横纵长度
#define stack_size 20	//栈大小

typedef struct pos {	//迷宫的每个点的坐标
	int row;
	int col;
}	pos;

typedef pos DataType;

typedef struct Stack{		//存放结点信息的栈
	DataType *array;  //数组指针
	size_t top;		  //栈顶
	size_t size;		  //最大容量
}	Stack;

typedef struct maze{		//迷宫
	int mz[N][N];
	pos entry;		//入口
}	maze;

void StackInit(Stack *s);
void StackPush(Stack *s, DataType x);
void StackPop(Stack *s);
int StackEmpty(Stack *s);
void MazeInit(maze *m);	//迷宫初始化
void MazePrint(maze *m); //打印迷宫
int CanPush(pos node, maze *m);		//能否入栈
void AssignPosed(pos node, maze **m);		//标记走过的记为 2
int CheckExit(pos node, maze *m);	//检查是否到达出口
void PrintStack(Stack *s);	//找到出口，打印栈内元素
void GetPath(maze *m, pos node, Stack *s);
