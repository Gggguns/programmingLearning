#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-2-25-1.h"
int main()
{
	SListNode* phead = NULL;
	SListNode* Ret = NULL;
	SListPushBack(&phead, 1);
	SListPushBack(&phead, 2);
	SListPushBack(&phead, 3);
	SListPushBack(&phead, 6);
	SListPushFront(&phead, 2);
	SListPushFront(&phead, 3);
	SListPushFront(&phead, 4);
	SListPushFront(&phead, 5);
	/*SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);
	SListPopBack(&phead);*/
	Ret=SListFind(phead,6);

	/*if (Ret == NULL)
		printf("没找到\n");
	else
	{
		printf("%p ", Ret);
		printf("%d\n", Ret->data);
	}*/
	//SListInsertAfter(Ret, 8);

	if (Ret == NULL)
		printf("没有该数据\n");
	else
	{
		SListEraseAfter(Ret);
	}
	/*SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);
	SListPopFront(&phead);*/
	SListDestroy(&phead);
	SListPrint(phead);
	return 0;
}