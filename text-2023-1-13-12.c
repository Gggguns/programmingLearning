#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
char* my_strncat(char* des, const char* ses, size_t num)
{
	assert(des && ses);
	char* ret = des;
	while (*des)
	{
		des++;
	}
	while (*des++ = *ses++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[50] = "hello,";
	char arr2[] = "my name is tutu";
	my_strncat(arr1, arr2, strlen(arr2));
	printf("%s", arr1);
	return 0;
}