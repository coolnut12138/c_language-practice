#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//ʵ�ʵ�����(��ӡ����������)
#define ROW 9
#define COL 9
//���ʱ�����У���ʵ�ʵĶ������Է�Խ�磬����������С��в���ӡ��
#define ROWS ROW+2
#define COLS COL+2
//���õ�����Ŀ
#define minenum 10

void game();
void Init_board(char board[ROWS][COLS],int rows,int cols,char set);//��ʼ����������
void Display_board(char board[ROWS][COLS],int row,int col);//չʾ����
void Set_mine(char real_board[ROWS][COLS],int row,int col);//������
int Count_mine(char real_board[ROWS][COLS],int x,int y);//ͳ�Ƶ�ǰ������Χ������
void Find_mine(char play_board[ROWS][COLS],char real_board[ROWS][COLS],int row,int col);//����
void Fsafe(char board[ROWS][COLS],int x,int y);//��һ�����׾��԰�ȫ
void Unfold(char play_board[ROWS][COLS],char real_board[ROWS][COLS],int row,int col,int x,int y);//û��չ��
int Iswin(char board[ROWS][COLS],int row,int col);//�ж��Ƿ�������Ӯ��


#endif