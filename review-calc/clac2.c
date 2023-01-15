#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void menu()
{
	printf("***********************************\n");
	printf("***   1.add      2.sub          ***\n");
	printf("***   3.mul      4.div          ***\n");
	printf("***        0.exist              ***\n");
	printf("***********************************\n");
	printf("***********************************\n");
}
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
int main()
{
	int a, b, n, ret;
	int(*calc[5])(int, int) = { NULL,add,sub,mul,div };
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &n);
		if (n == 0)
		{
			printf("推出计算器\n");
			break;
		}
		else if (n >= 1 && n <= 4)
		{
			printf("请输入两个操作数:>");
			scanf("%d%d", &a, &b);
			ret = calc[n](a, b);
			printf("%d\n", ret);
		}
		else
			printf("输入错误\n");
	} while (n);
	return 0;
}