#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Power(int num, int Po)
{
	if (num == 0)
	{
		return 0;
	}
	if (Po == 0)
		return 1;
	else if (Po == 1)
		return num;
	else
		return num * Power(num,Po-1);
}
int main()
{
	int num = 0, Po = 0;
	scanf("%d%d", &num, &Po);
	printf("%d",Power(num, Po));
	return 0;
}