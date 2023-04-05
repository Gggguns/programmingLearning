#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#define Col 3
#define Row 3

//菜单
void menu();

//游戏
void Game();

//棋盘初始化
void Init_broad(char broad[Row][Col], int row, int col);

//玩家下棋
void Playmove(char broad[Row][Col], int row, int col);

//电脑下棋
void Conputurmove(char broad[Row][Col], int row, int col);

//打印棋盘
void Printf_broad(char broad[Row][Col], int row, int col);

//谁赢了
char Is_win(char broad[Row][Col], int row, int col);

//棋盘判满
char Is_full(char broad[Row][Col], int row, int col);