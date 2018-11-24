#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"game.h"
void test()
{
	int x = 0;
	menu(x);
}
void game()
{
	char arr[ROW][COL] = {0};
	chessboard(arr, ROW, COL);
	INIT(arr, ROW, COL);
	int ret = 0;
	while (1)
	{
		player(arr, ROW, COL);
		chessboard(arr, ROW, COL);
		ret = judgement(arr, ROW, COL);
		if (ret == 3 || ret == 2 || ret == 1)
		{
			break;
		}
		computerplay(arr, ROW, COL);
		chessboard(arr, ROW, COL);
	    ret=judgement(arr, ROW, COL);
		if (ret == 3 || ret == 2 || ret == 1)
		{
			break;
		}
	}
	test();
}
//int select(i)
//{
//	int j = 0;
//	printf("**************************\n");
//	printf("******1.ÊÇ      0.·ñ******\n");
//	printf("**************************\n");
//	scanf("%d", &j);
//	return j;
//
//}
int main()
{
	test();
	system("pause");
	return 0;
}


