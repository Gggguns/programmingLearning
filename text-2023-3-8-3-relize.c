#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-8-3-ListNode.h"

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* head = NULL;
	ListNode* ptr = NULL;
	ptr = (ListNode*)malloc(sizeof(ListNode));
	if (!ptr)
	{
		perror("ListCreate malloc fail");
		return head;
	}
	else
	{
		head = ptr;
		head->_data = -1;
		head->_next = ptr;
		head->_prev = ptr;
		ptr = NULL;
		return head;
	}
}

// 双向链表销毁
void ListDestory(ListNode* pHead)
{
	ListNode* cur, * Del;
	pHead->_prev->_next = NULL;
	cur = pHead;
	while (cur)
	{
		Del = cur->_next;
		free(cur);
		cur = Del;
	}
	Del = NULL;
	cur = NULL;
}

//创建新的节点
ListNode* ListBuyNode(LTDataType x)
{
	ListNode* newnode = NULL;
	newnode = (ListNode*)malloc(sizeof(ListNode));
	if(!newnode)
	{
		perror("BuyNode malloc fail");
		return NULL;
	}
	else
	{
		newnode->_data = x;
		newnode->_next = NULL;
		newnode->_prev = NULL;
		return newnode;
	}
}

// 双向链表打印
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->_next;
	printf("<=>%s<=>", "head");
	while (cur != pHead)
	{
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	ListNode* ret;
	ret = ListBuyNode(x);
	if (ret)
	{
		ret->_prev = pHead->_prev;
		ret->_next = pHead;
		pHead->_prev = ret;
		ret->_prev->_next = ret;
	}
	return;
}

// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	if (pHead->_prev == pHead)
		return;
	else
	{
		pHead->_prev = pHead->_prev->_prev;
		free(pHead->_prev->_next);
		pHead->_prev->_next = pHead;
	}
}

// 双向链表头插
void ListPushFront(ListNode* pHead, LTDataType x)
{
	ListNode* ret = ListBuyNode(x);
	if (ret)
	{
		ret->_next = pHead->_next;
		pHead->_next->_prev = ret;
		pHead->_next = ret;
		ret->_prev = pHead;
	}
	return;
}

// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	pHead->_next = pHead->_next->_next;
	if(pHead->_next->_prev!=pHead)
	free(pHead->_next->_prev);
	pHead->_next->_prev = pHead;
}

// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	ListNode* ret = pHead->_next;
	while (ret != pHead)
	{
		if (ret->_data == x)
			return ret;
		ret = ret->_next;
	}
	return NULL;
}

// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* ret;
	ret = ListBuyNode(x);
	if (ret)
	{
		pos->_prev->_next = ret;
		ret->_prev = pos->_prev;
		ret->_next = pos;
		pos->_prev = ret;
	}
}

// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->_next->_prev = pos->_prev;
	pos->_prev->_next = pos->_next;
	free(pos);
	pos = NULL;
}