#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-29-1-1-BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
typedef struct BinaryTreeNode* QueueDataType;
typedef struct QueueNode
{
	QueueDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//队列初始化
void QueueInit(Queue* pq);

//队列的摧毁
void QueueDestroy(Queue* pq);

//队列的入列
void QueuePush(Queue* pq, QueueDataType x);

//队列的出列
void QueuePop(Queue* pq);

//队列的长度
int QueueSize(Queue* pq);

//队列是否为空
bool QueueEmpty(Queue* pq);

//队列列首元素
QueueDataType QueueFront(Queue* pq);

//队列的列尾元素
QueueDataType QueueBack(Queue* pq);
