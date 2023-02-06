#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num1, num2, num3,t;
	scanf("%d%d%d", &num1, &num2, &num3);
	if (num1 < num2)
	{
		t = num1;
		num1 = num2;
		num2 = t;
	}
	if (num1 < num3)
	{
		t = num1;
		num1 = num3;
		num3 = t;
	}
	if (num2 < num3)
	{
		t = num2;
		num2 = num3;
		num3 = t;
	}
	printf("%d %d %d", num1, num2, num3);
	return 0;
}