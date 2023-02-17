#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int mon = 0,sum=0;
	scanf("%d", &mon);
	sum = mon + mon / 2;
	printf("%d", sum);
	return 0;
}