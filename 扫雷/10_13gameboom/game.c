#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"



void Init_board(char board[ROWS][COLS],int rows,int cols,char set)//��ʼ������
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

void Display_board(char board[ROWS][COLS],int row,int col)//չʾ����(����ͬ�Ĳο���չʾ��ͬ�ļ���)
{
	int i = 0;
	int j = 0;
	for(i=0; i<=col; i++)
	{
		printf("%d ",i);//�����б��Ա��û�ʹ��
	}
	printf("\n");
	for(i=1; i<=row; i++)
	{
		printf("%d ",i);//�����б�
		for(j=1; j<=col; j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}


void Set_mine(char real_board[ROWS][COLS],int row,int col)//������
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

int Count_mine(char real_board[ROWS][COLS],int x,int y)//ͳ������
{
	return real_board[x-1][y-1] + real_board[x-1][y] + real_board[x-1][y+1]
	       + real_board[x][y-1] + real_board[x][y+1]
		   + real_board[x+1][y-1] + real_board[x+1][y] + real_board[x+1][y+1]
		   -8*'0';
}


void Fsafe(char real_board[ROWS][COLS],int x,int y)//��һ�����׾��԰�ȫ
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

int Iswin(char board[ROWS][COLS],int row,int col)//�ж��Ƿ�������Ӯ��
{
	int i = 0;
	int j = 0;
	int count = 0;
	for(i=1; i<=row; i++)
	{
		for(j=1; j<=col; j++)
		{
			if(board[i][j] == '*')//����ʣ���׵ĸ���
			{
				count++;
			}
		}
	}
	return count;
}


void Unfold(char play_board[ROWS][COLS],char real_board[ROWS][COLS],int row,int col,int x,int y)//û��չ��
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

void Find_mine(char play_board[ROWS][COLS],char real_board[ROWS][COLS],int row,int col)//����
{
	int x = 0;
	int y = 0;
	int ret = 0;
	int count = 0;//�Ų����
	while(Iswin(play_board,row,col) != minenum)
	{
		printf("��������Ҫ�Ų������:\n");
		scanf("%d%d",&x,&y);
		if(x<1 || x>row || y<1 || y>col)
		{
			printf("�������곬����Χ�����������룺\n");
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
							printf("�㱻ը���ˣ���Ϸ����\n");
							Display_board(real_board,row,col);
							count++;
							printf("һ���Ų���%d��\n",count);
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
			printf("��ϲ�㣬��Ϸʤ��������\n");
			printf("һ���Ų���%d��\n",count);
			Display_board(real_board,row,col);
		}
}

void game()
{
	char play_board[ROWS][COLS] = {0};//�������
	char real_board[ROWS][COLS] = {0};//���������(����ʾ)
	Init_board(play_board,ROWS,COLS,'*');
	Init_board(real_board,ROWS,COLS,'0');
	Display_board(play_board,ROW,COL);
	Set_mine(real_board,ROW,COL);
	//Display_board(real_board,ROW,COL);
	Find_mine(play_board,real_board,ROW,COL);
}