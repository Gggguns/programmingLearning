#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void check_solo(int arr[],int sz)
{
	int i, j, flat;
	for (i = 0;i < sz;i++)
	{
		flat = 1;
		for (j = 0;j < sz;j++)
		{ 
			if (i == j)
				continue;
			else if (arr[i] == arr[j])
			{
				flat = 0;
				break;
			}
		}
		if (1 == flat)
			printf("%d ", arr[i]);
	}
}
int  main()
{
	printf("µ¥Éí¹·:");
	int arr[] = {1,5,1,8,7,9,6,5,4,4,7,6,9,22,22,3,3,11},sz,i,j,flat;
	sz = sizeof(arr) / sizeof(arr[0]);
	check_solo(arr, sz);
	return 0;
}