#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* data;
	int capacity;
	int size;
}Heap;

//交换两个数
void Swap(HeapDataType* p1, HeapDataType* p2)
{
	HeapDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//向上调整
void AdjustUp(HeapDataType* str, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (str[parent] < str[child])
		{
			Swap(&str[parent], &str[child]);	
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}
//向下调整
void AdjustDown(HeapDataType* str, int parent,int end)
{
	int child=parent*2+1;
	while (child < end)
	{
		if ((child + 1) < end && str[child] < str[child + 1])
		{
			child++;
		}
		if (str[child] > str[parent])
			Swap(&str[child], &str[parent]);
		parent = child;
		child = parent * 2 + 1;
	}
}
//堆排序
void HeapSort(HeapDataType* str, int size)
{
	//建堆
	/*for (int i = (size - 2) / 2;0 <= i;i--)
	{
		AdjustDown(str, i, size);
	}*/
	for (int i = 1;i < size;i++)
	{
		AdjustUp(str, i);
	}
	//排升序
	int end = size;
	while (end-1)
	{
		Swap(&str[0], &str[end - 1]);
		AdjustDown(str, 0, end-1);
		end--;
	}
}
int main()
{
	int arr[] = { 10,53,32,4,97,4,7,8,6,22 };
	int size = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, size);
	return 0;
}