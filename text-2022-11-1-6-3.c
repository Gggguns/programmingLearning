#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i, j;
	for (i = 1;i < 10;i++)
	{
		for (j = 1;j < i + 1;j++)
		{
			printf("%dX%d=%-2d ", i, j,i*j);

		}
		printf("\n");
	}
	return 0;
}