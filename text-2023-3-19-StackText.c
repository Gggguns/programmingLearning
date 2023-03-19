#define _CRT_SECURE_NO_WARNINGS
#include"text-2023-3-19-Stack.h"
int main()
{
	Stack ST;
	STInit(&ST);
	STPush(&ST, '(');
	STPush(&ST, '{');
	STPush(&ST, '[');
	STPush(&ST, '(');
	STPush(&ST, '{');
	STPush(&ST, '[');
	STPush(&ST, '(');
	STDataType ret = STTop(&ST);
	printf("%c\n", ret);
	STPop(&ST);
	ret = STTop(&ST);
	printf("%c\n", ret);
	STPop(&ST);
	STDestroy(&ST);
	ret = STTop(&ST);
	printf("%c\n", ret);
	STPop(&ST);
	return;
}