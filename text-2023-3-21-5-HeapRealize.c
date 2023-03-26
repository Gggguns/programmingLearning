#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-21-5-Heap.h"
//堆的构建
void HeapCreate(Heap* php)
{
	assert(php);
	HeapDataType* ptr = (HeapDataType*)malloc(sizeof(HeapDataType) * 4);
	if (ptr)
	{
		php->data = ptr;
		php->capacity = 4;
		php->size = 0;
	}
	else
	{
		perror("HeapCreate malloc fail");
		return;
	}
}

//堆的销毁
void HeapDestory(Heap* php)
{
	free(php->data);
	php->data = NULL;
}

//堆的判满
bool HeapFull(Heap* php)
{
	return php->capacity == php->size;
}

//堆的判空
bool HeapEmpty(Heap* php)
{
	return php->size == 0;
}

//堆的扩容
void HeapExpandCapacity(Heap* php)
{
	HeapDataType* ptr = (HeapDataType*)realloc(php->data, sizeof(HeapDataType) * php->capacity * 2);
	if (ptr)
	{
		php->data = ptr;
		php->capacity = php->capacity * 2;
	}
	else
	{
		perror("HeapExpendCapacity realloc fail");
		return;
	}
}

//堆的插入
void HeapPush(Heap* php,HeapDataType x)
{
	if (HeapFull(php))
		HeapExpandCapacity(php);
	php->data[php->size] = x;
	LargeHeapAdjustUp(php,php->size);
	php->size++;
}

//堆的删除
void HeapPop(Heap* php)
{
	if(!HeapEmpty(php))
	php->size--;
}

//取堆顶元素
HeapDataType HeapTop(Heap* php)
{
	assert(php->size > 0);
	return php->data[0];
}

//数的交换
void Swap(HeapDataType* p1, HeapDataType* p2)
{
	HeapDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//大堆的向上调整
void LargeHeapAdjustUp(Heap* php, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (php->data[child] > php->data[parent])
		{
			Swap(&php->data[child], &php->data[parent]);
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}

//大堆的向下调整
void LargeHeapAdjustDown(Heap* php, int parent)
{
	int child = parent * 2 + 1;
	while (child < php->size)
	{
		if ((child + 1) < php->size && php->data[child] < php->data[child + 1])
			child++;
		if (php->data[child] > php->data[parent])
			Swap(&php->data[child], &php->data[parent]);
		parent = child;
		child = parent * 2 + 1;
	}
}

//打印堆的前k个元素
void HeapPrintfTopk(Heap* php,int k)
{
	while (k--)
	{
		printf("%d ", php->data[0]);
		Swap(&php->data[0], &php->data[php->size - 1]);
		php->size--;
		LargeHeapAdjustDown(php, 0);
	}
}