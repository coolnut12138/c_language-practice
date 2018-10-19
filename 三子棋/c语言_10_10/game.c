#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Init_board(char board[ROW][COL],int row,int col)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			board[i][j] = ' ';
		}
	}
}


void Display_board(char board[ROW][COL],int row,int col)//展示棋盘
{
    int i = 0;
    for(i=0; i<row; i++)
    {
        int j = 0;
        for(j=0; j<col;j++)
        {
            printf(" %c ",board[i][j]);
            if(j<col-1)
                printf("|");
        }
        printf("\n");
        if(i<row-1)
        {
            for(j=0; j<col; j++)
            {
                printf("---");
                if(j<col-1)
                    printf("|");
            }
            printf("\n");
        }
    }
}

void Player_move(char board[ROW][COL],int row,int col)//玩家走棋
{
	int x = 0;
	int y = 0;
	while(1)
	{
		printf("玩家走棋(请输入坐标)：\n");
		scanf("%d%d",&x,&y);
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(board[x-1][y-1]==' ')
			{
			board[x-1][y-1] = '*';
			break;
			}
			else
			{
				printf("该位置已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("输入位置错误，请重新输入\n");
		}
	}
}

void Computer_move(char board[ROW][COL],int row,int col)//电脑走棋
{
	printf("电脑走棋：\n");
	while(1)
	{
		int x = rand()%3;
		int y = rand()%3;
		if(x>=0 && x<row && y>=0 && y<col)
		{
			if(board[x][y] == ' ')
			{
				board[x][y] = 'o';
				break;
			}
		}
	}
}

char Is_win(char board[ROW][COL],int row,int col)//判断胜负
{
	int i = 0;
	int j = 0;
	//判断横行是否有三个连棋
	for(i=0; i<row; i++)
	{
		for(j=0; j<col-1; j++)
		{
			if(board[i][j] != board[i][j+1])
				break;
		}
		if(j == col-1)
		{
			return board[i][j];
		}
	}
	//判断竖行是否有三个连棋
	for(i=0; i<row; i++)
	{
		for(j=0; j<col-1; j++)
		{
			if(board[j][i] != board[j+1][i])
				break;
		}
		if(j == col-1)
		{
			return board[j][i];
		}
	}
	//判断捺是否有三个连棋[0][0],[1][1],[2][2]
	//if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
			//return board[0][0];
	for(i=0; i<row-1; i++)
	{
		if(board[i][i] != board[i+1][i+1])
		{
			break;
		}
	}
	if(i == row-1)
		{
			return board[i][i];
		}
	
	//判断撇是否有三个连棋[0][2],[1][1],[2][0]
	//if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
			//return board[0][2];
	for(i=0; i<row-1; i++)
	{
		if(board[i][row-1-i] != board[i+1][row-1-i-1])
		{
			break;
		}
	}
	if(i == row-1)
		return board[0][row-1];
	
	if(Is_full(board,ROW,COL))
		return 'q';
	else
		return ' ';
}

int Is_full(char board[ROW][COL],int row,int col)//判断棋盘是否满了
{
	int i = 0;
	int j = 0;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
		{
			if(board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

void game()
{
	char board[ROW][COL] = {0};
	char ret = 0;
	Init_board(board,ROW,COL);
	Display_board(board,ROW,COL);
	srand((unsigned int)time(NULL));
	while(1)
	{
		Computer_move(board,ROW,COL);
		ret = Is_win(board,ROW,COL);
		{
			if(ret != ' ')
				break;
		}
		Display_board(board,ROW,COL);
		Player_move(board,ROW,COL);
		ret = Is_win(board,ROW,COL);
		{
			if(ret != ' ')
				break;
		}
		Display_board(board,ROW,COL);
	}
	{
		if(ret == '*')
		{
			printf("玩家赢\n");
		}
		else if(ret == 'o')
		{
			printf("电脑赢\n");
		}
		else if(ret == 'q')
		{
			printf("平局\n");
		}
		Display_board(board,ROW,COL);
	}
}