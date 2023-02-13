#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int arr1[10], arr2[10],i,j=10;
	int tmp;
	for (i = 0;i < 10;i++)
	{
		arr1[i] = i;
	}
	for (i=0;i < 10;i++,j++)
	{
		arr2[i] = j;
	}
	printf("交换前\n");
	for (i = 0;i < 10;i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0;i < 10;i++)
	{
		printf("%d ", arr2[i]);
	}
	for (i = 0;i < 10;i++)
	{
		tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
	printf("\n交换后\n");
	for (i = 0;i < 10;i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	for (i = 0;i < 10;i++)
	{
		printf("%d ", arr2[i]);
	}
	return 0;
}