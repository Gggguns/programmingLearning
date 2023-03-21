#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-21-Queue.h"
//队列的初始化
void QueueInit(Queue* pq)
{
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//队列的摧毁
void QueueDestroy(Queue* pq)
{
	assert(pq);
	Queue* cur;
	cur = pq->head;
	while (cur)
	{
		pq->head = pq->head->next;
		free(cur);
		cur = pq->head;
	}
	cur = NULL;
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//队列的入列
void QueuePush(Queue* pq, QueueDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (QueueEmpty(pq))
		pq->head = pq->tail = newnode;
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

//队列的出列
void QueuePop(Queue* pq)
{
	Queue* cur;
	cur = pq->head;
	if (!QueueEmpty(pq))
	{
		pq->head = pq->head->next;
		free(cur);
	}
}

//队列是否为空
bool QueueEmpty(Queue* pq)
{
	return pq->size == 0;
}