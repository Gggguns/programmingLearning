#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-2-21-3.h"
int main()
{
	SqeList s;
	SqeListInit(&s);
	SqeListPushBack(&s, 1);
	SqeListPushBack(&s, 2);
	SqeListPushBack(&s, 3);
	SqeListPushBack(&s, 4);
	SqeListPushBack(&s, 5);
	SqeListPushBack(&s, 6);
	SqeListPushBack(&s, 7);
	SqeListPushBack(&s, 8);
	SqeListPushBack(&s, 9);
	SqeListPushBack(&s, 10);
	SqeListPushBack(&s, 11);
	SqeListPushBack(&s, 12);
	SqeListPushBack(&s, 13);
	SqeListPushBack(&s, 14);
	SqeListPushBack(&s, 15);
	SqeListPushBack(&s, 16);
	SqeListPushBack(&s, 17);
	SqeListPushBack(&s, 18);
	SqeListPushFront(&s, -1);
	SqeListPopFront(&s);
	SqeListPopFront(&s);
	SqeListPopFront(&s);
	SqeListPopFront(&s);
	SqeListPopBack(&s);
	SqeListPopBack(&s);
	SqeListPopBack(&s);
	SqeListPrintf(&s);
	return 0;
}