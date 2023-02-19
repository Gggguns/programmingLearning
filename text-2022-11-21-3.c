#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 10, b = 6;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d", a, b);
	return 0;
}