#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>


#define ROW 3//���̵���
#define COL 3//���̵���



void Init_board(char board[ROW][COL],int row,int col);
void Display_board(char board[ROW][COL],int row,int col);
void Player_move(char board[ROW][COL],int row,int col);
void Computer_move(char board[ROW][COL],int row,int col);
void game();
int Is_full(char board[ROW][COL],int row,int col);


//Is_win
//'*'���Ӯ
//'o'����Ӯ
//'q'ƽ��
//' '����
char Is_win(char board[ROW][COL],int row,int col);


#endif//__GAME_H__