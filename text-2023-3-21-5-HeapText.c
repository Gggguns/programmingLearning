#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-21-5-Heap.h"
int main()
{
	Heap  ph;
	HeapCreate(&ph);
	HeapPush(&ph,0);
	HeapPush(&ph, 0);
	HeapPush(&ph, 5);
	HeapPush(&ph, 200);
	HeapPush(&ph, 60);
	HeapPush(&ph, 7);
	HeapPush(&ph, 10);
	HeapPush(&ph, 30);
	HeapPush(&ph, 8);
	HeapPush(&ph, 42);
	HeapPush(&ph, 9);
	HeapPush(&ph, 80);
	while (!HeapEmpty(&ph))
	{
		printf("%d ", HeapTop(&ph));
		HeapPop(&ph);
	}
	//HeapPrintfTopk(&ph, 100);
	HeapDestory(&ph);
	return 0;
}