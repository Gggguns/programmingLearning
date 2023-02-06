#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num1, num2, r;
	scanf("%d%d", &num1, &num2);
	if (num1 < num2)
	{
		r = num1;
		num1 = num2;
		num2 = r;
	}
	r = 1;
	while (r)
	{
		if (num2 != 0)
			r = num1 % num2;
		else
			r = 0;
		num1 = num2;
		num2 = r;
	}
	printf("%d", num1);
	return 0;
}