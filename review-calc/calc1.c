#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
void menu()
	{
		printf("********************\n");
		printf("****1.add  2.sub****\n");
		printf("****3.mul  4.div****\n");
		printf("****0.exist     ****\n");
		printf("********************\n");
		printf("请输入:>");
	}
int main()
{
	int n,a,b,ret;
	
	do
	{
		menu();
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			printf("请输入两个操作数:>");
			scanf("%d%d",&a,&b);
			ret = Add(a, b);
			printf("%d\n", ret);
			break;
		case 2:
			printf("请输入两个操作数:>");
			scanf("%d%d", &a, &b);
			ret = Sub(a, b);
			printf("%d\n", ret);
			break;
		case 3:
			printf("请输入两个操作数:>");
			scanf("%d%d", &a, &b);
			ret = Mul(a, b);
			printf("%d\n", ret);
			break;
		case 4:
			printf("请输入两个操作数:>");
			scanf("%d%d", &a, &b);
			ret = Div(a, b);
			printf("%d\n", ret);
			break;
		case 0:
			printf("退出计算机\n");
			break;
		default:
			printf("输入错误\n");
		}
	} while (n);
	return 0;
}