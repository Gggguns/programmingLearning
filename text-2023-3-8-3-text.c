#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-8-3-ListNode.h"
int main()
{
	ListNode* Guardhead = ListCreate();
	ListPushBack(Guardhead,1);
	ListPushBack(Guardhead,2);
	ListPushBack(Guardhead,3);
	ListPushBack(Guardhead,4);
	ListPrint(Guardhead);
	ListPopBack(Guardhead);
	ListPrint(Guardhead);
	ListPopBack(Guardhead);
	ListPrint(Guardhead);
	ListPopBack(Guardhead);
	ListPrint(Guardhead);
	ListPushFront(Guardhead,1);
	ListPushFront(Guardhead, 2);
	ListPushFront(Guardhead, 3);
	ListPushFront(Guardhead, 4);
	ListPushFront(Guardhead, 5);
	ListPushFront(Guardhead, 6);
	/*ListPrint(Guardhead);
	ListPopFront(Guardhead);
	ListPrint(Guardhead);
	ListPopFront(Guardhead);
	ListPrint(Guardhead);
	ListPopFront(Guardhead);
	ListPrint(Guardhead);
	ListPopFront(Guardhead);
	ListPrint(Guardhead);
	ListPopFront(Guardhead);
	ListPrint(Guardhead);
	ListPopFront(Guardhead);
	ListPrint(Guardhead);
	ListPopFront(Guardhead);
	ListPrint(Guardhead);
	ListPopFront(Guardhead);*/
	ListPrint(Guardhead);
	ListNode*ret=ListFind(Guardhead,6);
	if (ret)
	{
		printf("%d在%x\n", ret->_data, ret);
	}
	else
	{
		printf("找不到\n");
	}
	ListInsert(Guardhead, 66);
	ListPrint(Guardhead);
	ret = ListFind(Guardhead, 66);
	if (ret)
	{
		printf("%d在%x\n", ret->_data, ret);
	}
	else
	{
		printf("找不到\n");
	}
	ListErase(ret);
	ListPrint(Guardhead);
	return 0;
}