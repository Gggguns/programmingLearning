#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int i,arr[10],Max;
	for(i=0;i<10;i++)
	{
		scanf("%d", &arr[i]);
	}
	for (Max = arr[0], i = 1;i < 10;i++)
	{
		if (Max < arr[i])
			Max = arr[i];
	}
	printf("%d", Max);
	return 0;
}