#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
typedef int STDataType;
typedef struct Stack
{
    STDataType* data;
    int size;
    int capacity;
}Stack;

typedef struct {
    Stack ST1;
    Stack ST2;
} MyQueue;

void STInit(Stack* ST)
{
    ST->data = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ST->data)
    {
        ST->size = 0;
        ST->capacity = 4;
    }
    else
    {
        perror("malloc fail");
        return;
    }
}
void FindCapacity(Stack* ST)
{
    if (ST->size == ST->capacity)
    {
        STDataType* tmp = (STDataType*)realloc(ST->data, sizeof(STDataType) * ST->capacity * 2);
        if (tmp)
        {
            ST->data = tmp;
            ST->capacity = ST->capacity * 2;
        }
        else
            perror("remalloc fail");
    }
}
void STPush(Stack* ST, STDataType x)
{
    FindCapacity(ST);
    ST->data[ST->size] = x;
    ST->size++;
}
void STPop(Stack* ST)
{
    if (ST->size)
        ST->size--;
}
STDataType STTop(Stack* ST)
{
    if (ST->size)
        return ST->data[ST->size - 1];
    else
        return 0;
}
void STDestroy(Stack* ST)
{
    free(ST->data);
    ST->data = NULL;
    ST->capacity = 0;
    ST->size = 0;
}

MyQueue* myQueueCreate() {
    MyQueue* Queue = (MyQueue*)malloc(sizeof(MyQueue));
    if (!Queue)
    {
        perror("myQueueCreate malloc fail");
        return NULL;
    }
    else
    {
        STInit(&Queue->ST1);
        STInit(&Queue->ST2);
        return Queue;
    }
}

void myQueuePush(MyQueue* obj, int x) {
    STPush(&obj->ST1, x);
}

int myQueuePop(MyQueue* obj) {
    //µ¼Êý¾Ý
    if ((obj->ST2.size) == 0)
        while (obj->ST1.size > 0)
        {
            STPush(&obj->ST2, STTop(&obj->ST1));
            STPop(&obj->ST1);
        }
    int Front = STTop(&obj->ST2);
    STPop(&obj->ST2);
    return Front;
}

int myQueuePeek(MyQueue* obj) {
    if (obj->ST2.size == 0)
        while (obj->ST1.size > 0)
        {
            STPush(&obj->ST2, STTop(&obj->ST1));
            STPop(&obj->ST1);
        }
    int Front = STTop(&obj->ST2);
    return Front;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->ST1.size == 0 && obj->ST2.size == 0;
}

void myQueueFree(MyQueue* obj) {
    STDestroy(&obj->ST1);
    STDestroy(&obj->ST2);
    free(obj);
}
int main()
{
	return 0;
}