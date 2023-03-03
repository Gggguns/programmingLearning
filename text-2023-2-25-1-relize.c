#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-2-25-1.h"
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* NewNode=(SListNode*)calloc(1, sizeof(SListNode));
	if (NewNode == NULL)
	{
		perror("calloc fail");
		return NewNode;
	}
	else
	{
		NewNode->data = x;
		NewNode->next = NULL;
		return NewNode;
	}
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode*ptr=BuySListNode(x);
	SListNode* tail = *pplist;
	if (ptr == NULL)
		printf("尾插失败\n");
	else if (*pplist == NULL)
	{
		*pplist = ptr;
	}
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = ptr;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode*ptr=BuySListNode(x);
	if (ptr == NULL)
	{
		printf("头插失败\n");
	}
	else
	{
		ptr->next = *pplist;
		*pplist = ptr;
	}
}
// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	SListNode* tail = *pplist;
	if (*pplist == NULL)
	{
		return;
	}
	else if (tail->next==NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	else
	{
		while (tail->next->next)
		{
			tail = tail->next;
		}
		free(tail->next);
		tail->next = NULL;
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	SListNode* frist = *pplist;
	if ((*pplist) == NULL)
		return;
	*pplist = (*pplist)->next;
	free(frist);
	frist = NULL;
}
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	if (plist == NULL)
		return NULL;
	else
	{
		while (plist)
		{
			if (plist->data == x)
				return plist;
			plist = plist->next;
		}
		return NULL;
	}
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode* ret = NULL;
	ret=BuySListNode(x);
	if (ret == NULL)
		printf("插入失败\n");
	else
	{
		ret->next = pos->next;
		pos->next=ret;
	}
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	SListNode* After = NULL;
	if (!pos->next)
		return;
	After = pos->next->next;
	free(pos->next);
	pos->next = After;
}
// 单链表的销毁
void SListDestroy(SListNode** pplist)
{
	SListNode* des = *pplist;
	SListNode* Judge = *pplist;
	*pplist = NULL;
	while (Judge)
	{
		des = Judge;
		Judge = Judge->next;
		free(des);
		des = NULL;
	}
}