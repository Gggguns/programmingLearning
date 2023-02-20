#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int num1 = 0, num2 = 0,x=32,count=0;
	scanf("%d%d", &num1, &num2);
	while (x--)
	{
		if (num1 < 0 && num2 < 0)
		{
			count++;
		}
		else if (0 <= num1 && 0 <= num2)
		{
			count++;
		}
		num1 <<= 1;
		num2 <<= 1;
	}
	printf("%d", 32-count);
	return 0;
}