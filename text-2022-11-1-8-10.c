#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void Multae(int num)
{
	int i, j;
	for (i = 1;i < num + 1;i++)
	{
		for (j = 1;j <i + 1;j++)
		{
			printf("%2dX%d=%-3d ", i, j, i * j);
		}
		printf("\n");
	}	
}
int main()
{
	int num;
	scanf("%d",&num);
	Multae(num);
	return 0;
}