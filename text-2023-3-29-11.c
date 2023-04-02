#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
//插入排序-升序为例
void InsertSort(int* str, int size)
{
	int i = 0;
	for(i=0;i<size-1;i++)
	{
		int end = i;
		int tmp = str[i+1];
		while (end >= 0)
		{
			if (tmp < str[end])
			{
				str[end + 1] = str[end];
				end--;
			}
			else
				break;
		}
		str[end + 1] = tmp;
	}
}
//希尔排序
void ShellSort(int* str, int size)
{
	int gap = size;
	int i = 0;
	while(gap)
	{
		gap = gap / 2;
		for (i = 0;i < size - gap;i++)
		{
			int end = i;
			int tmp = str[i + gap];
			while (end >= 0)
			{
				if (tmp < str[end])
				{
					str[end + gap] = str[end];
					end = end - gap;
				}
				else
					break;
			}
			str[end + gap] = tmp;
		}
	}
}
//造数据
void CreateArray(int* str, int size)
{
	srand(time(0));
	int i = 0;
	for (i = 0;i < size;i++)
	{
		str[i] = rand();
	}

}
//打印数组
void PrintfArray(int* str, int size)
{
	int i = 0;
	for (i = 0;i < size;i++)
	{
		printf("%d ", str[i]);
	}
	printf("\n");
}
int main()
{
	/*int arr[] = { 31,432,656,2,54,1,43,132,66,4,2,7,9,0,42,12,43,6531,34 };
	int size = sizeof(arr) / sizeof(arr[0]);*/
	int* arr = NULL;
	int size = 10000;
	arr = (int*)malloc(sizeof(int) * size);
	if (!arr)
	{
		perror("malloc fail");
		return;
	}
	
	CreateArray(arr, size);
	int begin = clock();
	//InsertSort(arr, size);
	ShellSort(arr, size);
	int end = clock();
	//printf("InsertSort:%d\n", end - begin);
	printf("ShellSort:%d\n", end - begin);
	//PrintfArray(arr, size);
	free(arr);
	return 0;
}