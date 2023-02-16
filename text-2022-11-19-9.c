#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define N 13
int main()
{
	int i = 0, j = 0;
	for (i = 0;i < N;i++)
	{
		int k = N - i;
		while (k--)
		{
			printf("%c", ' ');
		}
		k = 2 * i + 1;
		while (k--)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
	for (;(-1) < i;i--)
	{
		int k = N - i;
		while (k--)
		{
			printf("%c", ' ');
		}
		k = 2 * i + 1;
		while (k--)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
	return 0;
}