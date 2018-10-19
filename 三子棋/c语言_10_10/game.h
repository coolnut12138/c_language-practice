#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


#define ROW 3//棋盘的行
#define COL 3//棋盘的列



void Init_board(char board[ROW][COL],int row,int col);
void Display_board(char board[ROW][COL],int row,int col);
void Player_move(char board[ROW][COL],int row,int col);
void Computer_move(char board[ROW][COL],int row,int col);
void game();
int Is_full(char board[ROW][COL],int row,int col);


//Is_win
//'*'玩家赢
//'o'电脑赢
//'q'平局
//' '再来
char Is_win(char board[ROW][COL],int row,int col);


#endif//__GAME_H__