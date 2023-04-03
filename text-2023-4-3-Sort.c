#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-4-3-Sort.h"
//插入排序
void InsertSort(int* str, int size);

//希尔排序
void ShellSort(int* str, int size)
{
	int gap = size;
	int i = 0, end, tmp;
	while(gap>0)
	{
		gap = gap / 2;
		for (i = 0;i < size - gap;i++)
		{
			end = i;
			tmp = str[end+gap];
			while (end >= 0)
			{
				if (str[end] > tmp)
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

//选择排序
void SelectSort(int* str, int size)
{
	int left = 0, right = size-1;
	int maxi = 0, mini = 0;
	int i = 0;
	while(left<right)
	{
		maxi = left;
		mini = left;
		for (i = left;i <= right;i++)
		{
			if (str[i] < str[mini])
				mini = i;
			if (str[maxi] < str[i])
				maxi = i;
		}
		Swap(&str[mini], &str[left]);
		if (maxi == left)
			maxi = mini;
		Swap(&str[maxi], &str[right]);
		left++;
		right--;
	}
}

//堆排序
void HeapSort(int* str, int n)
{
	int end = n;
	int i = 0;
	//建大堆
	for (i = n/2-1;i >= 0;i--)
	{
		AdjustDown(str, n, i);
	}
	//建小堆
	while (end>0)
	{
		Swap(&str[end - 1], &str[0]);
		AdjustDown(str, end-1, 0);
		end--;
	}
}

//冒泡排序
void BubbleSort(int* str, int size)
{
	int i = 0, j = 0;
	for(j=0;j<size-1;j++)
	{
		for (i = 0;i < size - 1 - j;i++)
		{
			if (str[i] > str[i + 1])
				Swap(&str[i], &str[i + 1]);
		}
	}
}

//快速排序
void QuickSort(int* str, int left, int right)
{
	if (right < left)
		return;
	int key = left;
	int end = right;
	while (left < right)
	{
		while (left < right && str[right] >= str[key])
			right--;
		while (left < right && str[left] <= str[key])
			left++;
		Swap(&str[left], &str[right]);
	}
	Swap(&str[key], &str[left]);
	QuickSort(str, key, left - 1);
	QuickSort(str, right + 1, end);
}

//归并排序

//交换两个数据
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//大堆的向下调整
void AdjustDown(int* str, int end, int parent)
{
	int child = parent * 2 + 1;
	while (child < end)
	{
		if (child + 1 < end && str[child] < str[child + 1])
			child++;
		if (str[child] > str[parent])
			Swap(&str[child], &str[parent]);
		parent = child;
		child = parent * 2 + 1;
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
		
		a1[i] = rand();
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
	BubbleSort(a1,Size);
	PrintfArray(a1, Size);
	int end1 = clock();







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