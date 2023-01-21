#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
int main()
{
	int input;
	Initcontact(&con);
	do
	{
	menu();
	printf("请输入数字:>");
	scanf("%d", &input);
	switch (input)
	{
	case add:
		Add(&con);
		break;
	case del:
		Del(&con);
		break;
	case search:
		Search(&con);
		break;
	case modify:
		Mondif(&con);
		break;
	case show:
		Show(&con);
		break;
	case exit:
		printf("退出\n");
		break;
	default :
		printf("输入错误\n");
		break;

	}

	} while (input);

	return 0;
}