#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int x = 0;
	scanf("%d", &x);
	if (x++ > 100)
		printf("%d", ++x);
	else
		printf("%d", --x);
	return 0;
}