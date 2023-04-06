#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-4-3-Sort.h"
//插入排序
void InsertSort(int* str, int size)
{
	int i = 0;
	for(i=0;i<size-1;i++)
	{
		int end = i;
		int tmp = str[i + 1];
		while (0 <= end)
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
	if (right <= left)
		return;
	int begin = left;
	int end = right;
	//随机选key
	/*int random = left+rand()%(right);
	Swap(&str[left], &str[random]);*/
	//三数取中
	int mid = GetMidNumi(str,left, right);
	if (mid != left)
		Swap(&str[mid], &str[left]);
	int key = left;
	while (left < right)
	{
		while (left < right && str[right] >= str[key])
			right--;
		while (left < right && str[left] <= str[key])
			left++;
		Swap(&str[left], &str[right]);
	}
	Swap(&str[key], &str[left]);
	key = left;
	QuickSort(str, begin, key - 1);
	QuickSort(str, key + 1, end);
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

//取中间值
int GetMidNumi(int* str, int left, int right)
{
	int mid = (left + right) / 2;
	if (str[left] < str[right])
	{
		if (str[right] < str[mid])
			return right;
		else if (str[mid] < str[left])
			return left;
		else
			return mid;
	}
	else
	{
		if (str[left] < str[mid])
			return left;
		else if (str[mid] < str[right])
			return right;
		else
			return mid;
	}
}

void QuickSort2(int* str, int left, int right)
{
	if (right <= left)
		return;
	int begin = left;
	int end = right;
	//随机选key
	/*int random = left+rand()%(right);
	Swap(&str[left], &str[random]);*/
	//三重取中
	int mid = GetMidNumi(str, left, right);
	if (mid != left)
		Swap(&str[mid], &str[left]);
	int key = str[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && str[right] >= key)
			right--;
		str[hole] = str[right];
		hole = right;
		while (left < right && str[left] <= key)
			left++;
		str[hole] = str[left];
		hole = left;
	}
	str[hole] = key;
	QuickSort2(str, begin, hole - 1);
	QuickSort2(str, hole + 1, end);
}

//void QuickSort3(int* str, int left, int right)
//{
//	if (right <= left)
//		return;
//	int begin = left;
//	int end = right;
//	//随机选key
//	/*int random = left+rand()%(right);
//	Swap(&str[left], &str[random]);*/
//	//三重取中
//	int mid = GetMidNumi(str, left, right);
//	if (mid != left)
//		Swap(&str[mid], &str[left]);
//	int key = str[left];
//	int hole = left;
//	while (left < right)
//	{
//		while (left < right && str[right] >= key)
//			right--;
//		str[hole] = str[right];
//		hole = right;
//		while (left < right && str[left] <= key)
//			left++;
//		str[hole] = str[left];
//		hole = left;
//	}
//	str[hole] = key;
//	QuickSort3(str, begin, hole - 1);
//	QuickSort3(str, hole + 1, end);
//}