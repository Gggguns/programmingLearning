#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int DigitSum(int num)
{
	if (num == 0)
		return 0;
	else
		return num % 10 + DigitSum(num / 10);
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n",DigitSum(num));
}
