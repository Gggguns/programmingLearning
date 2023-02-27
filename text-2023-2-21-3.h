#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#define N 10
typedef int SLDateType;
typedef struct SList
{
	SLDateType* s;
	int size;
	int capacity;
}SqeList;

SqeList s;

//检查容量
void CheckSqeListCapacity(SqeList* ps);

//顺序表的初始化
void SqeListInit(SqeList* ps);

//顺序表的摧毁
void SqeListDestory(SqeList* ps);

//顺序表的打印
void SqeListPrintf(SqeList* ps);

//顺序表的头插
void SqeListPushFront(SqeList* ps);

//顺序表的尾插
void SqeListPushBack(SqeList* ps);

//顺序表的尾删
void SqeListPopBack(SqeList* ps);

//顺序表的头删
void SqeListPopFront(SqeList* ps);