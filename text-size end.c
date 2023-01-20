#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
union
{
	char c;
	int a;
}un;
void text1()//第一种方法
{
	int a = 1;
	if (*(char *)&a == 1)
		printf("小端");
	else
		printf("大端");
}
void text2()//第二种方法
{
	un.a = 1;
	if (un.c == 1)
		printf("\n小端");
	else
		printf("\n大端");
}
int main()
{
	text1();
	text2();
	return 0;
}
