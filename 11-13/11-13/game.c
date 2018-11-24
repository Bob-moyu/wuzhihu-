#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu(int x)
{
	printf("****************************\n");
	printf("******0.quit    1.play******\n");
	printf("****************************\n");
	scanf("%d", &x);
	choice(x);
}
void choice(x)
{
	switch (x)
	{
	case 1:game();
		break;
	case 0:
		break;
	default:
		printf("选择错误，请重新选择\n");
		menu(x);
		break;
	}
}
void chessboard(char arr1[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row;i++)
	{
		printf(" %c | %c | %c  \n", arr1[i][0],arr1[i][1],arr1[i][2]);
		if (i < row - 1)
		{
			printf("___|___|___\n");
		}
	/*int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i != row - 1)
			{
				printf("___");
			}
		    if (j != col - 1 && i != row - 1)
			{
				printf("|");
			}
			if (i== row - 1&& j==col-1)
			{
				printf("   |   |");
			}
		}
		printf("\n");*/
	}
	printf("   |   |   \n");
}
void INIT(char arr1[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr1[i][j] =  ' ' ;
		}
	}
}
void computerplay(char arr1[ROW][COL], int row, int col)
{
	printf("\n");
	int i = 0;
	int j = 0;
	while (1)
	{
		i = rand() % row;
		j = rand() % col;
		if (arr1[i][j] == ' ')
		{
			arr1[i][j] = 'X';
			break;
		}
	}

}
void player(char arr1[ROW][COL], int row, int col)
{
	printf("玩家走");
	int x = 0; 
	int y = 0;
	while (1)
	{
		scanf("%d %d", &x, &y);
		if ((x <= row&&x >= 1) && (y <= col&&y >= 1))
		{
			if (arr1[x - 1][y - 1] == ' ')
			{
				arr1[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标占用，请重新输入\n");
			}

		}
		else
		{
			printf("输入错误，请重新输入\n");
		}
	}
	printf("\n");
}
int judgement(char arr1[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
		for (i = 0; i < row; i++)
		{
			if (arr1[i][0] == arr1[i][1] && arr1[i][0] == arr1[i][2] && arr1[i][2] != ' ')
			{
				if (arr1[i][0] == '*')
				{
					printf("游戏结束，玩家胜利\n");
					return 3;
				}
				else if (arr1[i][0] == 'X')
				{
					printf("游戏结束，电脑胜利\n");
					return 1;
				}
				else
				{
					printf("游戏结束，平局\n");
					return 2;
				}
			}
		}
		for (i = 0; i < col; i++)
		{
			if (arr1[0][i] == arr1[1][i] && arr1[1][i] == arr1[2][i] && arr1[1][i] != ' ')
			{
				if (arr1[0][i] == '*')
				{
					printf("游戏结束，玩家胜利\n");
					return 3;
				}
				else if (arr1[0][i] == 'X')
				{
					printf("游戏结束，电脑胜利\n");
					return 1;
				}
				else
				{
					printf("游戏结束，平局\n");
					return 2;
				}
			}	
		}
		if ((arr1[0][0] == arr1[1][1]) && (arr1[1][1] == arr1[2][2]) && arr1[1][1] != ' ')
		{
			if (arr1[1][1] == '*')
			{
				printf("游戏结束，玩家胜利\n");
				return 3;
			}
			else if (arr1[1][1] == 'X')
			{
				printf("游戏结束，电脑胜利\n");
				return 1;
			}
			else
			{
				printf("游戏结束，平局\n");
				return 2;
			}
		}
		if ((arr1[2][0] == arr1[1][1]) && (arr1[1][1] == arr1[0][2]) && arr1[1][1] != ' ')
		{
			if (arr1[1][1] == '*')
			{
				printf("游戏结束，玩家胜利\n");
				return 3;
			}
			else if (arr1[1][1] == 'X')
			{
				printf("游戏结束，电脑胜利\n");
				return 1;
			}
			else
			{
				printf("游戏结束，平局\n");
				return 2;
			}
		}
}
