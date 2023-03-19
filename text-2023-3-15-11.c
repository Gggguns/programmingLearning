#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
typedef char STDataType;
typedef struct Stack
{
    STDataType* data;
    int size;
    int capacity;
}Stack;
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
    return '\0';
}
bool isValid(char* s)
{
    Stack ST;
    STInit(&ST);
    STDataType x;
    int i = 0;
    while (s[i] != '\0')
    {
        x = s[i];
        i++;
        if (x == '(' || x == '{' || x == '[')
        {
            STPush(&ST, x);
        }
        else
        {
            STDataType ret = STTop(&ST);
            STPop(&ST);
            if (ret == '(' && x == ')')
                continue;
            else if (ret == '{' && x == '}')
                continue;
            else if (ret == '[' && x == ']')
                continue;
            else
                return false;
        }
    }
    if ((ST.size) != 0)
        return false;
    else
        return true;
}
int main()
{
    return 0;
}