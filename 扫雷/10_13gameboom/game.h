#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//实际的行列(打印出来的棋盘)
#define ROW 9
#define COL 9
//设计时的行列（比实际的多两行以防越界，多出来的两行、列不打印）
#define ROWS ROW+2
#define COLS COL+2
//设置的雷数目
#define minenum 10

void game();
void Init_board(char board[ROWS][COLS],int rows,int cols,char set);//初始化两个棋盘
void Display_board(char board[ROWS][COLS],int row,int col);//展示棋盘
void Set_mine(char real_board[ROWS][COLS],int row,int col);//布置雷
int Count_mine(char real_board[ROWS][COLS],int x,int y);//统计当前坐标周围的雷数
void Find_mine(char play_board[ROWS][COLS],char real_board[ROWS][COLS],int row,int col);//排雷
void Fsafe(char board[ROWS][COLS],int x,int y);//第一次排雷绝对安全
void Unfold(char play_board[ROWS][COLS],char real_board[ROWS][COLS],int row,int col,int x,int y);//没雷展开
int Iswin(char board[ROWS][COLS],int row,int col);//判断是否排完雷赢了


#endif