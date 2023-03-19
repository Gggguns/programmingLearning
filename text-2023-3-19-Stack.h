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
//Õ»Ö¡³õÊ¼»¯
void STInit(Stack* ST);

//Õ»Ö¡µÄÏú»Ù
void STDestroy(Stack* ST);

//Õ»Ö¡µÄÑ¹Õ»
void STPush(Stack* ST,STDataType x);

//Õ»Ö¡µÄ³öÕ»
void STPop(Stack* ST);

//Õ»Ö¡µÄÕ»¶¥
STDataType STTop(Stack* ST);

