#define _CRT_SECURE_NO_WARNINGS
#include"text-2022-11-7-2-game.h"

//菜单
void menu()
{
	printf("*************************************\n");
	printf("*********      1.Play      **********\n");
	printf("*********      0.Exit     **********\n");
	printf("*************************************\n");
}

//游戏
void Game()
{
	char broad[Row][Col];
	srand((unsigned int)time(NULL));
	Init_broad(broad, Row, Col);
	char ret;
	while(1)
	{
		
		//Printf_broad(broad, Row, Col);
		Playmove(broad, Row, Col);
		ret=Is_win(broad, Row, Col);
		if (ret != 'C')
		{
			break;
		}
		Conputurmove(broad, Row, Col);
		ret = Is_win(broad, Row, Col);
		if (ret != 'C')
		{
			break;
		}
	}
	
	if (ret == '*')
		printf("玩家获胜\n");
	else if (ret == '#')
		printf("电脑获胜\n");
	else
		printf("平局\n");
	Printf_broad(broad, Row, Col);
}

//棋盘初始化
void Init_broad(char broad[Row][Col], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			broad[i][j] = ' ';
		}
	}
}

//玩家下棋
void Playmove(char broad[Row][Col], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家下棋\n");
	Printf_broad(broad, row, col);
	printf("请输入放棋坐标:>");
	while(1)
	{
		
		scanf("%d%d", &x, &y);
		if (0 < x && 0 < y && x <= 3 && y <= 3)
		{
			if (broad[x - 1][y - 1] == ' ')
			{
				broad[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该位置已放有棋子\n");
		}
		else
		{
			printf("输入坐标错误\n");
		}
		printf("请重新输入放棋坐标:>");
	}
}

//打印棋盘
void Printf_broad(char broad[Row][Col], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf(" %c ", broad[i][j]);
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		if(i<row-1)
		{
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

//电脑下棋
void Conputurmove(char broad[Row][Col], int row, int col)
{
	printf("电脑下棋\n");
	Printf_broad(broad, row, col);
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (0 <= x && 0 <= y && x < 3 && y < 3)
		{
			if (broad[x][y] == ' ')
			{
				broad[x][y] = '#';
				break;
			}
		}
	}
}

//谁赢了
char Is_win(char broad[Row][Col], int row, int col)
{
	//三行
	int i = 0;
	for (i = 0;i < row;i++)
	{
		if (broad[i][0] == broad[i][1] && broad[i][1] == broad[i][2] && broad[i][0] != ' ')
			return broad[i][0];
	}
	//三列
	for (i = 0;i < col;i++)
	{
		if (broad[0][i] == broad[1][i] && broad[1][i] == broad[2][i] && broad[0][i] != ' ')
			return broad[0][i];
	}
	//对角线
	if (broad[0][0] == broad[1][1] && broad[1][1] == broad[2][2] && broad[1][1] != ' ')
		return broad[0][0];
	if (broad[0][2] == broad[1][1] && broad[1][1] == broad[2][0] && broad[1][1] != ' ')
		return broad[0][2];
	//平局
	return Is_full(broad, row, col);
}

//棋盘判满
char Is_full(char broad[Row][Col], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		int j = 0;
		for (j = 0;j < col;j++)
		{
			if (broad[i][j] == ' ')
				return 'C';
		}
	}
	return 'Q';
}