#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int add(int x, int y)
{
	return x + y;
}
int sub(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
void menu()
{
	printf("**************************************\n");
	printf("****   1.add      2.sub           ****\n");
	printf("****   3.mul      4.div           ****\n");
	printf("****        0.exist               ****\n");
	printf("**************************************\n");
}
void calc(int (*pf)(int, int))
{
	int a, b, ret;
	printf("请输入两个操作的数字:>");
	scanf("%d%d", &a, &b);
	ret = pf(a, b);
	printf("%d\n", ret);
}
int main()
{
	int  input;
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出计算器\n");
			break;
		case 1:
			calc(add);
			break;
		case 2:
			calc(sub);
			break;
		case 3:
			calc(mul);
			break;
		case 4:
			calc(div);
			break;
		default:
			printf("输入错误\n");
		}
	} while (input);
	return 0;
}