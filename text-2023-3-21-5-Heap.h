#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int HeapDataType;

typedef struct Heap
{
	HeapDataType* data;
	int size;
	int capacity;
}Heap;

//堆的构建
void HeapCreate(Heap* php);

//堆的插入
void HeapPush(Heap* php,HeapDataType x);

//堆的删除
void HeapPop(Heap* php);

//堆的销毁
void HeapDestory(Heap* php);

//取堆顶元素
HeapDataType HeapTop(Heap* php);

//堆的数据个数
int HeapSize(Heap* php);

//堆的判空
bool HeapEmpty(Heap* php);

//打印堆的前k个元素
void HeapPrintfTopk(Heap* php,int k);

//堆的判满
bool HeapFull(Heap* php);

//堆的扩容
void HeapExpandCapacity(Heap* php);

//数的交换
void Swap(HeapDataType* p1, HeapDataType* p2);

//大堆的向上调整
void LargeHeapAdjustUp(Heap* php, int child);

//大堆的向下调整
void LargeHeapAdjustDown(Heap* php, int parent);