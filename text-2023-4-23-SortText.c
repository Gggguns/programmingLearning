#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-4-3-Sort.h"
int main()
{
	int arr1[] = { 23,500,78,34,34,2,52,6,244,72,6,23 };
	int size = sizeof(arr1) / sizeof(arr1[0]);
	//BubbleSort(arr1, size);
	//SelectSort(arr1,size);
	//HeapSort(arr1, size);
	//ShellSort(arr1, size);
	QuickSort(arr1, 0, size - 1);
	PrintfArray(arr1, size);
	//TextOP();
	return 0;
}