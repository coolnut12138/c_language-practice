#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"



void Init_board(char board[ROWS][COLS],int rows,int cols,char set)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for(i=0; i<rows; i++)
	{
		for(j=0; j<cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Display_board(char board[ROWS][COLS],int row,int col)//展示棋盘(传不同的参可以展示不同的键盘)
{
	int i = 0;
	int j = 0;
	for(i=0; i<=col; i++)
	{
		printf("%d ",i);//设置列标以便用户使用
	}
	printf("\n");
	for(i=1; i<=row; i++)
	{
		printf("%d ",i);//设置行标
		for(j=1; j<=col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}


void Set_mine(char real_board[ROWS][COLS],int row,int col)//布置雷
{
	int x = 0;
	int y = 0;
	int count = minenum;
	while(count)
	{
		x = rand()%row+1;
		y = rand()%col+1;
		if(real_board[x][y] == '0')
		{
			real_board[x][y] = '1';
			count--;
		}
	}
}

int Count_mine(char real_board[ROWS][COLS],int x,int y)//统计雷数
{
	return real_board[x-1][y-1] + real_board[x-1][y] + real_board[x-1][y+1]
	       + real_board[x][y-1] + real_board[x][y+1]
		   + real_board[x+1][y-1] + real_board[x+1][y] + real_board[x+1][y+1]
		   -8*'0';
}


void Fsafe(char real_board[ROWS][COLS],int x,int y)//第一次排雷绝对安全
{
	int i = 0;
	int j = 0;
	if(real_board[x][y] == '1')
	{
		i = rand()%9+1;
		j = rand()%9+1;
		if(real_board[i][j] == '0')
		{
			real_board[i][j] = '1';
			real_board[x][y] = '0';
		}
	}
}

int Iswin(char board[ROWS][COLS],int row,int col)//判断是否排完雷赢了
{
	int i = 0;
	int j = 0;
	int count = 0;
	for(i=1; i<=row; i++)
	{
		for(j=1; j<=col; j++)
		{
			if(board[i][j] == '*')//计算剩余雷的个数
			{
				count++;
			}
		}
	}
	return count;
}


void Unfold(char play_board[ROWS][COLS],char real_board[ROWS][COLS],int row,int col,int x,int y)//没雷展开
{
	int i = 0;
	int j = 0;
	if(Count_mine(real_board,x,y) == 0)
	{
		play_board[x][y] = '0';
		for(i=-1; i<=1; i++)
		{
			for(j=-1; j<=1; j++)
			{
				if(x+i>=1 && x+i<=row && y+j>=1 && y+j<=col && (i != 0||j !=0))
				{
					if(play_board[x+i][y+j] != '0')
					{
						Unfold(play_board,real_board,row,col,x+i,y+j);
					}
				}
			}
		}
	}
	else
	{
		play_board[x][y] = Count_mine(real_board,x,y) + '0';
	}
}

void Find_mine(char play_board[ROWS][COLS],char real_board[ROWS][COLS],int row,int col)//排雷
{
	int x = 0;
	int y = 0;
	int ret = 0;
	int count = 0;//排查次数
	while(Iswin(play_board,row,col) != minenum)
	{
		printf("请输入你要排查的坐标:\n");
		scanf("%d%d",&x,&y);
		if(x<1 || x>row || y<1 || y>col)
		{
			printf("输入坐标超出范围，请重新输入：\n");
		}
		else
		{	
			
			if(real_board[x][y] == '1')
		    {
					  if(count == 0 )
					  {
						Fsafe(real_board,x,y);
						Unfold(play_board,real_board,row,col,x,y);
						Display_board(play_board,row,col);
						count++;
					  }
						else
						{
							printf("你被炸死了，游戏结束\n");
							Display_board(real_board,row,col);
							count++;
							printf("一共排查了%d次\n",count);
							break;
						}
			}
			else
			{	
				Unfold(play_board,real_board,row,col,x,y);
				Display_board(play_board,row,col);
				count++;
			}
		}
	}
		if(Iswin(play_board,row,col) == minenum)
		{
			printf("恭喜你，游戏胜利！！！\n");
			printf("一共排查了%d次\n",count);
			Display_board(real_board,row,col);
		}
}

void game()
{
	char play_board[ROWS][COLS] = {0};//玩家棋盘
	char real_board[ROWS][COLS] = {0};//设计者棋盘(不显示)
	Init_board(play_board,ROWS,COLS,'*');
	Init_board(real_board,ROWS,COLS,'0');
	Display_board(play_board,ROW,COL);
	Set_mine(real_board,ROW,COL);
	//Display_board(real_board,ROW,COL);
	Find_mine(play_board,real_board,ROW,COL);
}