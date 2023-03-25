#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
typedef int QueueDataType;
typedef struct Queue {
    QueueDataType* data;
    int Front;
    int Rear;
    int size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    if (!obj)
    {
        perror("myCircularQueueCreate malloc fail");
        return NULL;
    }
    else
    {
        QueueDataType* ptr = (QueueDataType*)malloc(sizeof(QueueDataType) * (k + 1));
        if (ptr)
        {
            obj->data = ptr;
            obj->Front = obj->Rear = 0;
            obj->size = k + 1;
        }
        return obj;
    }
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    if (obj->Front == obj->Rear)
        return true;
    else
        return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
    if ((obj->Rear + 1) % (obj->size) == obj->Front)
        return true;
    else
        return false;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj))
        return false;
    else
    {
        obj->data[obj->Rear] = value;
        obj->Rear = (obj->Rear + 1) % (obj->size);
        return true;
    }
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return false;
    else
    {
        obj->Front = (obj->Front + 1) % (obj->size);
        return true;
    }
}

int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
        return obj->data[obj->Front];
}

int myCircularQueueRear(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj))
        return -1;
    else
    {
        if (obj->Rear == 0)
            return obj->data[obj->Rear - 1 + obj->size];
        else
            return obj->data[obj->Rear - 1];
    }

}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    obj->data = NULL;
    free(obj);
    obj = NULL;
}
int main()
{
    return 0;
}