#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[12] = { 0 }, b[13] = { 0 }, i, j, k;
	a[0] = 1;b[0] = 1;
	printf("1\n");
	for (i = 1;i < 11;i++)
	{
		for (k = 0;k < i;k++)
		{
			a[k + 1] = b[k] + b[k + 1];
		}
		for (j = 0;j < i + 1;j++)
		{
			printf("%-3d ", a[j]);
		}
		printf("\n");
		for (j = 1;j < i + 1;j++)
		{
			b[j] = a[j];
		}
	}
	return 0;
}