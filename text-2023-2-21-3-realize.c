#pragma once
#include"text-2023-2-21-3.h"

void CheckSqeListCapacity(SqeList* ps)
{
	SLDateType* ptr = NULL;
	if (ps->capacity == ps->size)
		ptr = (SLDateType*)realloc(ps->s, (ps->capacity + N) * sizeof(SLDateType));
	else
		return;
	if (ptr == NULL)
		perror("realloc fail");
	else
	{
		ps->s = ptr;
		ptr = NULL;
		ps->capacity = ps->capacity + N;
	}
}

void SqeListInit(SqeList* ps)
{
	SLDateType* ptr = (SLDateType*)calloc(N, sizeof(SLDateType));
	if (ptr == NULL)
	{
		perror("calloc fail");
	}
	else
		ps->s = ptr;
	ps->capacity = N;
	ps->size = 0;
}

void SqeListDestory(SqeList* ps)
{
	free(ps->s);
	ps->s = NULL;
}

void SqeListPrintf(SqeList* ps)
{
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		printf("%d ", ps->s[i]);
	}
}

void SqeListPushBack(SqeList* ps,SLDateType x)
{
	CheckSqeListCapacity(ps);
	ps->s[ps->size] = x;
	ps->size++;
}

void SqeListPopBack(SqeList* ps)
{
	if (ps->size == 0)
		return;
	ps->size--;
}
void SqeListPushFront(SqeList* ps,SLDateType x)
{
	SLDateType sum = ps->size;
	CheckSqeListCapacity(ps);
	while (sum)
	{
		ps->s[sum] = ps->s[sum - 1];
		sum--;
	}
	ps->s[0] = x;
	ps->size++;
}

void SqeListPopFront(SqeList* ps)
{
	SLDateType sum = 0;
	while (sum < ps->size)
	{
		ps->s[sum] = ps->s[sum + 1];
		sum++;
	}
	ps->size--;
}