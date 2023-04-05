#define _CRT_SECURE_NO_WARNINGS
#include"text-2022-11-7-2-game.h"
void TextGame()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入选择操作数:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
}
int main()
{
	TextGame();
	return 0;
}