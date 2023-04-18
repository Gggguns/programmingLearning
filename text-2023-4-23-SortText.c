#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-4-3-Sort.h"
//各个排序的比较测试
void TextOP()
{
	int* a1 = (int*)malloc(sizeof(int) * Size);
	int* a2 = (int*)malloc(sizeof(int) * Size);
	int* a3 = (int*)malloc(sizeof(int) * Size);
	int* a4 = (int*)malloc(sizeof(int) * Size);
	int* a5 = (int*)malloc(sizeof(int) * Size);
	int* a6 = (int*)malloc(sizeof(int) * Size);
	int* a7 = (int*)malloc(sizeof(int) * Size);
	int* a8 = (int*)malloc(sizeof(int) * Size);
	int* a9 = (int*)malloc(sizeof(int) * Size);
	int i = 0;
	srand(time(0));
	for (i = 0;i < Size;i++)
	{

		a1[i] = rand()%100;
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
		a9[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1,Size);
	int end1 = clock();

	/*int begin2 = clock();
	ShellSort(a2, Size);
	int end2 = clock();*/

	/*int begin3 = clock();
	SelectSort(a3, Size);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, Size);
	int end4 = clock();*/

	/*int begin5 = clock();
	QuickSort(a2, 0, Size - 1);
	int end5 = clock();*/

	/*int begin6 = clock();
	ShellSort(a6, Size);
	int end6 = clock();

	int begin7 = clock();
	InsertSort(a7, Size);
	int end7 = clock();

	int begin8 = clock();
	ShellSort(a8, Size);
	int end8 = clock();

	int begin9 = clock();
	InsertSort(a9, Size);
	int end9 = clock();

	int begin2 = clock();
	ShellSort(a1, Size);
	int end2 = clock();*/

	/*printf("QuickSort:%d", end5 - begin5);*/

	//PrintfArray(a1, Size);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
	free(a7);
	free(a8);
	free(a9);
}
int main()
{
	int arr1[] = { 23,6,3,7,8,500,78,34,34,2,52,6,244,72,6,23,6,8,4,100,-1,78,0,20,-4,66,77};
	int size = sizeof(arr1) / sizeof(arr1[0]);
	//BubbleSort(arr1, size);
	//SelectSort(arr1,size);
	//HeapSort(arr1, size);
	//ShellSort(arr1, size);
	//QuickSort2(arr1, 0, size - 1);
	/*InsertSort(arr1, size);*/
	//QuickSort3(arr1, 0, size - 1);
	//MergeSort2(arr1, size);
	//QuickSort4(arr1, size);
	CountSort(arr1, size);
	PrintfArray(arr1, size);
	//TextOP();
	return 0;
}