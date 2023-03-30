#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
typedef int HeapDataType;
typedef struct Heap
{
	HeapDataType* data;
	int size;
	int capacity;
}Heap;

void Swap(HeapDataType* p1, HeapDataType* p2)
{
	HeapDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HeapDataType* str, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (str[child] < str[parent])
		{
			Swap(&str[child], &str[parent]);
		}
		child = parent;
		parent = (child - 1) / 2;
	}
}

void AdjustDown(HeapDataType* pdata, int parent, int end)
{
	int child = parent * 2 + 1;
	while (child < end)
	{
		if ((child + 1) < end && pdata[child] > pdata[child + 1])
			child++;
		if(pdata[child]<pdata[parent])
			Swap(&pdata[child], &pdata[parent]);
		parent = child;
		child = parent * 2 + 1;
	}
}

//造数据
void CreateNData(const char* file)
{
	srand(time(0));
	int n = 10000;
	int num = 0;
	FILE* fin = fopen(file, "w");
	if (fin)
		for (int i = 0;i < n;i++)
		{
			num = rand() % 10000;
			fprintf(fin, "%d\n", num);
		}
	else
	{
		perror("fopen fail");
		return;
	}
	fclose(fin);
}
//打印最大的前k个数
void PrintfTopk(const char*file,int k)
{
	FILE* fout = fopen(file, "r");
	if (!fout)
	{
		perror("fopen fail");
		return;
	}
	Heap hp;
	hp.data = (HeapDataType*)malloc(sizeof(HeapDataType) * k);
	if (!hp.data)
	{
		perror("malloc fail");
		return;
	}
	hp.size = 0;
	hp.capacity = k;
	HeapDataType tmp = 0;
	int i = 0;
	while (k--)
	{
		fscanf(fout, "%d", &hp.data[hp.size]);
		AdjustUp(hp.data,hp.size);
		hp.size++;
	}
	for ( i = hp.capacity-1;i < 10000;i++)
	{

		fscanf(fout, "%d", &tmp);
		if ((hp.data[0]) < tmp)
		{
			hp.data[0] = tmp;
			AdjustDown(hp.data, 0, hp.size);
		}
	}
	for (i = 0;i < hp.capacity;i++)
	{
		printf("%d ", hp.data[i]);
		/*Swap(&hp.data[0], &hp.data[hp.size - 1]);*/
		//hp.size--;
		//AdjustDown(hp.data, 0, hp.size);
	}
}
int main()
{
	const char* file = "data.txt";
	//CreateNData(file);
	PrintfTopk(file, 10);
	return 0;
}