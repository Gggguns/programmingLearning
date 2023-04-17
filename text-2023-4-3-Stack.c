#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-4-3-Stack.h"
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
}
void STDestroy(Stack* ST)
{
    free(ST->data);
    ST->data = NULL;
    ST->capacity = 0;
    ST->size = 0;
}