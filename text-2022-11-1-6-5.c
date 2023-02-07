#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	float fm = 1, fz = 1, i,sum;
	for (i = 0, sum = 0;i < 100;i++)
	{
		fm = fm + i;
		sum = sum + (fz / fm);
		fz = fz * (-1);
	}
	printf("%f", sum);
	return 0;
}